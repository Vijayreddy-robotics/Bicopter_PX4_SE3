/****************************************************************************
 *
 *   Copyright (c) 2019-2023 PX4 Development Team. All rights reserved.
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
 * @file RateControl.cpp
 */

#include "rate_control.hpp"
#include <px4_platform_common/defines.h>
#include <iostream>

using namespace matrix;

void RateControl::setPidGains(const Vector3f &P, const Vector3f &I, const Vector3f &D)
{
	_gain_p = P;
	_gain_i = I;
	_gain_d = D;
}

void RateControl::setSaturationStatus(const Vector3<bool> &saturation_positive,
				      const Vector3<bool> &saturation_negative)
{
	_control_allocator_saturation_positive = saturation_positive;
	_control_allocator_saturation_negative = saturation_negative;
}

void RateControl::setPositiveSaturationFlag(size_t axis, bool is_saturated)
{
	if (axis < 3) {
		_control_allocator_saturation_positive(axis) = is_saturated;
	}
}

void RateControl::setNegativeSaturationFlag(size_t axis, bool is_saturated)
{
	if (axis < 3) {
		_control_allocator_saturation_negative(axis) = is_saturated;
	}
}

Vector3f RateControl::update(const Vector3f &rate, const Vector3f &rate_sp, const matrix::Dcm<float> &R, const matrix::Dcm<float> &Rd, const Vector3f &angular_accel,
			     const float dt, const bool landed)
{


	if(count ==1){
		Rd_prev = Rd;
	}
	count +=1;


	Matrix3f Rd_dot = (Rd - Rd_prev)/dt;
	Matrix3f Wd_hat = Rd.transpose()*Rd_dot;
	Vector3f Wd = Dcmf(Wd_hat).vee();
	Vector3f Wd_dot = (Wd - Wd_prev)/dt;
	Wd_dot = Wd_dot;

	//R_hat = R_hat_prev.expmso3(Vector3f(rate_sp*dt));
	matrix::Dcm<float> eQ;
	eQ = Rd.transpose()*R;
	Matrix3f eR_hat = eQ - eQ.transpose();
	Vector3f eR = 0.5f*Dcmf(eR_hat).vee();
	//omega_hat_dot = (rate_sp - omega_hat_prev)/dt ;
	Vector3f eOmega = rate - eQ.transpose()*Wd;
	//Matrix3f eOmega_cap = eOmega.hat();
	Matrix3f Omega_cap = rate.hat();

	//Vector3f K_R = Vector3f(0.71f, 0.71f, 0.41f);
	//Vector3f K_Omega = Vector3f(0.1f, 0.1f, 0.031f);

	Vector3f K_R = Vector3f(0.45f, 0.4f, 0.45f);
	Vector3f K_Omega = Vector3f(0.125f, 0.1f, 0.05f);
	
	//const Vector3f torque = -_gain_p.emult(eR)- _gain_i.emult(eOmega) + rate.cross(J_*rate) - J_*Omega_cap*eQ.transpose()*Wd  ;//+ J_*eQ.transpose()*Wd_dot;
	//const Vector3f torque = -K_R.emult(eR)  - K_Omega.emult(eOmega) - J_*eOmega_cap*eQ.transpose()*rate_sp + rate.cross(J_*rate) + J_*eQ.transpose()*omega_hat_dot;
	const Vector3f torque = -K_R.emult(eR)- K_Omega.emult(eOmega) + rate.cross(J_*rate) - J_*Omega_cap*eQ.transpose()*Wd  ;
	//omega_hat_prev = rate_sp;

	Rd_prev = Rd;
	Wd_prev = Wd;
	
	return torque;
}

void RateControl::updateIntegral(Vector3f &rate_error, const float dt)
{
	for (int i = 0; i < 3; i++) {
		// prevent further positive control saturation
		if (_control_allocator_saturation_positive(i)) {
			rate_error(i) = math::min(rate_error(i), 0.f);
		}

		// prevent further negative control saturation
		if (_control_allocator_saturation_negative(i)) {
			rate_error(i) = math::max(rate_error(i), 0.f);
		}

		// I term factor: reduce the I gain with increasing rate error.
		// This counteracts a non-linear effect where the integral builds up quickly upon a large setpoint
		// change (noticeable in a bounce-back effect after a flip).
		// The formula leads to a gradual decrease w/o steps, while only affecting the cases where it should:
		// with the parameter set to 400 degrees, up to 100 deg rate error, i_factor is almost 1 (having no effect),
		// and up to 200 deg error leads to <25% reduction of I.
		float i_factor = rate_error(i) / math::radians(400.f);
		i_factor = math::max(0.0f, 1.f - i_factor * i_factor);

		// Perform the integration using a first order method
		float rate_i = _rate_int(i) + i_factor * _gain_i(i) * rate_error(i) * dt;

		// do not propagate the result if out of range or invalid
		if (PX4_ISFINITE(rate_i)) {
			_rate_int(i) = math::constrain(rate_i, -_lim_int(i), _lim_int(i));
		}
	}
}

void RateControl::getRateControlStatus(rate_ctrl_status_s &rate_ctrl_status)
{
	rate_ctrl_status.rollspeed_integ = _rate_int(0);
	rate_ctrl_status.pitchspeed_integ = _rate_int(1);
	rate_ctrl_status.yawspeed_integ = _rate_int(2);
}
