/****************************************************************************
 *
 *   Copyright (c) 2019 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file AttitudeControl.cpp
 */

#include <AttitudeControl.hpp>

#include <mathlib/math/Functions.hpp>

using namespace matrix;

void AttitudeControl::setProportionalGain(const matrix::Vector3f &proportional_gain, const float yaw_weight)
{
	_proportional_gain = proportional_gain;
	_yaw_w = math::constrain(yaw_weight, 0.f, 1.f);

	// compensate for the effect of the yaw weight rescaling the output
	if (_yaw_w > 1e-4f) {
		_proportional_gain(2) /= _yaw_w;
	}
}
/*
matrix::Vector3f AttitudeControl::angular_velocity(const matrix::Quatf &q_prev,const matrix::Quatf &q_current,float dt)
{
	// Compute the angular velocity using quaternion components
	matrix::Quatf q1 = q_prev;
	matrix::Quatf q2 = q_current;
    	return (2.0f / dt) * matrix::Vector3f(
        q1(0)*q2(1) - q1(1)*q2(0) - q1(2)*q2(3) + q1(3)*q2(2),  // x-component
        q1(0)*q2(2) + q1(1)*q2(3) - q1(2)*q2(0) - q1(3)*q2(1),  // y-component
        q1(0)*q2(3) - q1(1)*q2(2) + q1(2)*q2(1) - q1(3)*q2(0));   // z-component
}
*/



matrix::Vector3f AttitudeControl::update(const Quatf &q,float dt) const
{
	Quatf qd = _attitude_setpoint_q;

	//Dcmf R_hat = qd.Quaternion();
	Dcm<float> R_hat(qd); // Convert quaternion to DCM
	// Calculate angular velocity: ω = vee(R_sp^T * (R_sp - R_prev) / dt)
    	matrix::Matrix3f R_dot = (R_hat-R_prev)/dt ;
    	matrix::Matrix3f omega_matrix = R_hat.transpose() * R_dot;
    	matrix::Vector3f rate_setpoint2 = Vector3f(omega_matrix(2, 1), omega_matrix(0, 2), omega_matrix(1, 0));
	R_prev = R_hat;

	// in terms of quaternion
	// Get the current attitude quaternion and previous attitude quaternion

	// Compute the angular velocity using quaternion components
	matrix::Quatf q1 = qd_prev;
	matrix::Quatf q2 = qd;
    	matrix::Vector3f rate_setpoint3 =  (2.0f / dt) * Vector3f(
        						q1(0)*q2(1) - q1(1)*q2(0) - q1(2)*q2(3) + q1(3)*q2(2),  // x-component
        						q1(0)*q2(2) + q1(1)*q2(3) - q1(2)*q2(0) - q1(3)*q2(1),  // y-component
        						q1(0)*q2(3) - q1(1)*q2(2) + q1(2)*q2(1) - q1(3)*q2(0));   // z-component
}

	// Update previous quaternion
	qd_prev = qd;



	// calculate reduced desired attitude neglecting vehicle's yaw to prioritize roll and pitch
	const Vector3f e_z = q.dcm_z();
	const Vector3f e_z_d = qd.dcm_z();
	Quatf qd_red(e_z, e_z_d);

	if (fabsf(qd_red(1)) > (1.f - 1e-5f) || fabsf(qd_red(2)) > (1.f - 1e-5f)) {
		// In the infinitesimal corner case where the vehicle and thrust have the completely opposite direction,
		// full attitude control anyways generates no yaw input and directly takes the combination of
		// roll and pitch leading to the correct desired yaw. Ignoring this case would still be totally safe and stable.
		qd_red = qd;

	} else {
		// transform rotation from current to desired thrust vector into a world frame reduced desired attitude
		qd_red *= q;
	}

	// mix full and reduced desired attitude
	Quatf q_mix = qd_red.inversed() * qd;
	q_mix.canonicalize();
	// catch numerical problems with the domain of acosf and asinf
	q_mix(0) = math::constrain(q_mix(0), -1.f, 1.f);
	q_mix(3) = math::constrain(q_mix(3), -1.f, 1.f);
	qd = qd_red * Quatf(cosf(_yaw_w * acosf(q_mix(0))), 0, 0, sinf(_yaw_w * asinf(q_mix(3))));

	// quaternion attitude control law, qe is rotation from q to qd
	const Quatf qe = q.inversed() * qd;

	// using sin(alpha/2) scaled rotation axis as attitude error (see quaternion definition by axis angle)
	// also taking care of the antipodal unit quaternion ambiguity(means adjusting the first non-zero element of qe to be positive
	// and take only vector part of adjusted qe and append to the eq)
	// canonical() is something like sign() function
	const Vector3f eq = 2.f * qe.canonical().imag();

	// calculate angular rates setpoint
	matrix::Vector3f rate_setpoint = eq.emult(_proportional_gain);
	//rate_setpoint2 += rate_setpoint2;

	// Feed forward the yaw setpoint rate.
	// yawspeed_setpoint is the feed forward commanded rotation around the world z-axis,
	// but we need to apply it in the body frame (because _rates_sp is expressed in the body frame).
	// Therefore we infer the world z-axis (expressed in the body frame) by taking the last column of R.transposed (== q.inversed)
	// and multiply it by the yaw setpoint rate (yawspeed_setpoint).
	// This yields a vector representing the commanded rotatation around the world z-axis expressed in the body frame
	// such that it can be added to the rates setpoint.
	if (std::isfinite(_yawspeed_setpoint)) {
		rate_setpoint2 += q.inversed().dcm_z() * _yawspeed_setpoint;
	}

	// limit rates
	for (int i = 0; i < 3; i++) {
		rate_setpoint2(i) = math::constrain(rate_setpoint2(i), -_rate_limit(i), _rate_limit(i));
	}

	return rate_setpoint3;
}
