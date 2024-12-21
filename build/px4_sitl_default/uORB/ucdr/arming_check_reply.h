/****************************************************************************
 *
 *   Copyright (C) 2013-2022 PX4 Development Team. All rights reserved.
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


// auto-generated file

#pragma once

#include <ucdr/microcdr.h>
#include <string.h>
#include <uORB/topics/arming_check_reply.h>

#include <uORB/ucdr/event.h>

static inline constexpr int ucdr_topic_size_arming_check_reply()
{
	return 226;
}

static inline bool ucdr_serialize_arming_check_reply(const void* data, ucdrBuffer& buf, int64_t time_offset = 0)
{
	const arming_check_reply_s& topic = *static_cast<const arming_check_reply_s*>(data);
	static_assert(sizeof(topic.timestamp) == 8, "size mismatch");
	const uint64_t timestamp_adjusted = topic.timestamp + time_offset;
	memcpy(buf.iterator, &timestamp_adjusted, sizeof(topic.timestamp));
	buf.iterator += sizeof(topic.timestamp);
	buf.offset += sizeof(topic.timestamp);
	static_assert(sizeof(topic.request_id) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.request_id, sizeof(topic.request_id));
	buf.iterator += sizeof(topic.request_id);
	buf.offset += sizeof(topic.request_id);
	static_assert(sizeof(topic.registration_id) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.registration_id, sizeof(topic.registration_id));
	buf.iterator += sizeof(topic.registration_id);
	buf.offset += sizeof(topic.registration_id);
	static_assert(sizeof(topic.health_component_index) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.health_component_index, sizeof(topic.health_component_index));
	buf.iterator += sizeof(topic.health_component_index);
	buf.offset += sizeof(topic.health_component_index);
	static_assert(sizeof(topic.health_component_is_present) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.health_component_is_present, sizeof(topic.health_component_is_present));
	buf.iterator += sizeof(topic.health_component_is_present);
	buf.offset += sizeof(topic.health_component_is_present);
	static_assert(sizeof(topic.health_component_warning) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.health_component_warning, sizeof(topic.health_component_warning));
	buf.iterator += sizeof(topic.health_component_warning);
	buf.offset += sizeof(topic.health_component_warning);
	static_assert(sizeof(topic.health_component_error) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.health_component_error, sizeof(topic.health_component_error));
	buf.iterator += sizeof(topic.health_component_error);
	buf.offset += sizeof(topic.health_component_error);
	static_assert(sizeof(topic.can_arm_and_run) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.can_arm_and_run, sizeof(topic.can_arm_and_run));
	buf.iterator += sizeof(topic.can_arm_and_run);
	buf.offset += sizeof(topic.can_arm_and_run);
	static_assert(sizeof(topic.num_events) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.num_events, sizeof(topic.num_events));
	buf.iterator += sizeof(topic.num_events);
	buf.offset += sizeof(topic.num_events);
	static_assert(sizeof(topic.events[0].timestamp) == 8, "size mismatch");
	memcpy(buf.iterator, &topic.events[0].timestamp, sizeof(topic.events[0].timestamp));
	buf.iterator += sizeof(topic.events[0].timestamp);
	buf.offset += sizeof(topic.events[0].timestamp);
	static_assert(sizeof(topic.events[0].id) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.events[0].id, sizeof(topic.events[0].id));
	buf.iterator += sizeof(topic.events[0].id);
	buf.offset += sizeof(topic.events[0].id);
	static_assert(sizeof(topic.events[0].event_sequence) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.events[0].event_sequence, sizeof(topic.events[0].event_sequence));
	buf.iterator += sizeof(topic.events[0].event_sequence);
	buf.offset += sizeof(topic.events[0].event_sequence);
	static_assert(sizeof(topic.events[0].arguments) == 25, "size mismatch");
	memcpy(buf.iterator, &topic.events[0].arguments, sizeof(topic.events[0].arguments));
	buf.iterator += sizeof(topic.events[0].arguments);
	buf.offset += sizeof(topic.events[0].arguments);
	static_assert(sizeof(topic.events[0].log_levels) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.events[0].log_levels, sizeof(topic.events[0].log_levels));
	buf.iterator += sizeof(topic.events[0].log_levels);
	buf.offset += sizeof(topic.events[0].log_levels);
	static_assert(sizeof(topic.events[1].timestamp) == 8, "size mismatch");
	memcpy(buf.iterator, &topic.events[1].timestamp, sizeof(topic.events[1].timestamp));
	buf.iterator += sizeof(topic.events[1].timestamp);
	buf.offset += sizeof(topic.events[1].timestamp);
	static_assert(sizeof(topic.events[1].id) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.events[1].id, sizeof(topic.events[1].id));
	buf.iterator += sizeof(topic.events[1].id);
	buf.offset += sizeof(topic.events[1].id);
	static_assert(sizeof(topic.events[1].event_sequence) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.events[1].event_sequence, sizeof(topic.events[1].event_sequence));
	buf.iterator += sizeof(topic.events[1].event_sequence);
	buf.offset += sizeof(topic.events[1].event_sequence);
	static_assert(sizeof(topic.events[1].arguments) == 25, "size mismatch");
	memcpy(buf.iterator, &topic.events[1].arguments, sizeof(topic.events[1].arguments));
	buf.iterator += sizeof(topic.events[1].arguments);
	buf.offset += sizeof(topic.events[1].arguments);
	static_assert(sizeof(topic.events[1].log_levels) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.events[1].log_levels, sizeof(topic.events[1].log_levels));
	buf.iterator += sizeof(topic.events[1].log_levels);
	buf.offset += sizeof(topic.events[1].log_levels);
	static_assert(sizeof(topic.events[2].timestamp) == 8, "size mismatch");
	memcpy(buf.iterator, &topic.events[2].timestamp, sizeof(topic.events[2].timestamp));
	buf.iterator += sizeof(topic.events[2].timestamp);
	buf.offset += sizeof(topic.events[2].timestamp);
	static_assert(sizeof(topic.events[2].id) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.events[2].id, sizeof(topic.events[2].id));
	buf.iterator += sizeof(topic.events[2].id);
	buf.offset += sizeof(topic.events[2].id);
	static_assert(sizeof(topic.events[2].event_sequence) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.events[2].event_sequence, sizeof(topic.events[2].event_sequence));
	buf.iterator += sizeof(topic.events[2].event_sequence);
	buf.offset += sizeof(topic.events[2].event_sequence);
	static_assert(sizeof(topic.events[2].arguments) == 25, "size mismatch");
	memcpy(buf.iterator, &topic.events[2].arguments, sizeof(topic.events[2].arguments));
	buf.iterator += sizeof(topic.events[2].arguments);
	buf.offset += sizeof(topic.events[2].arguments);
	static_assert(sizeof(topic.events[2].log_levels) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.events[2].log_levels, sizeof(topic.events[2].log_levels));
	buf.iterator += sizeof(topic.events[2].log_levels);
	buf.offset += sizeof(topic.events[2].log_levels);
	static_assert(sizeof(topic.events[3].timestamp) == 8, "size mismatch");
	memcpy(buf.iterator, &topic.events[3].timestamp, sizeof(topic.events[3].timestamp));
	buf.iterator += sizeof(topic.events[3].timestamp);
	buf.offset += sizeof(topic.events[3].timestamp);
	static_assert(sizeof(topic.events[3].id) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.events[3].id, sizeof(topic.events[3].id));
	buf.iterator += sizeof(topic.events[3].id);
	buf.offset += sizeof(topic.events[3].id);
	static_assert(sizeof(topic.events[3].event_sequence) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.events[3].event_sequence, sizeof(topic.events[3].event_sequence));
	buf.iterator += sizeof(topic.events[3].event_sequence);
	buf.offset += sizeof(topic.events[3].event_sequence);
	static_assert(sizeof(topic.events[3].arguments) == 25, "size mismatch");
	memcpy(buf.iterator, &topic.events[3].arguments, sizeof(topic.events[3].arguments));
	buf.iterator += sizeof(topic.events[3].arguments);
	buf.offset += sizeof(topic.events[3].arguments);
	static_assert(sizeof(topic.events[3].log_levels) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.events[3].log_levels, sizeof(topic.events[3].log_levels));
	buf.iterator += sizeof(topic.events[3].log_levels);
	buf.offset += sizeof(topic.events[3].log_levels);
	static_assert(sizeof(topic.events[4].timestamp) == 8, "size mismatch");
	memcpy(buf.iterator, &topic.events[4].timestamp, sizeof(topic.events[4].timestamp));
	buf.iterator += sizeof(topic.events[4].timestamp);
	buf.offset += sizeof(topic.events[4].timestamp);
	static_assert(sizeof(topic.events[4].id) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.events[4].id, sizeof(topic.events[4].id));
	buf.iterator += sizeof(topic.events[4].id);
	buf.offset += sizeof(topic.events[4].id);
	static_assert(sizeof(topic.events[4].event_sequence) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.events[4].event_sequence, sizeof(topic.events[4].event_sequence));
	buf.iterator += sizeof(topic.events[4].event_sequence);
	buf.offset += sizeof(topic.events[4].event_sequence);
	static_assert(sizeof(topic.events[4].arguments) == 25, "size mismatch");
	memcpy(buf.iterator, &topic.events[4].arguments, sizeof(topic.events[4].arguments));
	buf.iterator += sizeof(topic.events[4].arguments);
	buf.offset += sizeof(topic.events[4].arguments);
	static_assert(sizeof(topic.events[4].log_levels) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.events[4].log_levels, sizeof(topic.events[4].log_levels));
	buf.iterator += sizeof(topic.events[4].log_levels);
	buf.offset += sizeof(topic.events[4].log_levels);
	static_assert(sizeof(topic.mode_req_angular_velocity) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.mode_req_angular_velocity, sizeof(topic.mode_req_angular_velocity));
	buf.iterator += sizeof(topic.mode_req_angular_velocity);
	buf.offset += sizeof(topic.mode_req_angular_velocity);
	static_assert(sizeof(topic.mode_req_attitude) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.mode_req_attitude, sizeof(topic.mode_req_attitude));
	buf.iterator += sizeof(topic.mode_req_attitude);
	buf.offset += sizeof(topic.mode_req_attitude);
	static_assert(sizeof(topic.mode_req_local_alt) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.mode_req_local_alt, sizeof(topic.mode_req_local_alt));
	buf.iterator += sizeof(topic.mode_req_local_alt);
	buf.offset += sizeof(topic.mode_req_local_alt);
	static_assert(sizeof(topic.mode_req_local_position) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.mode_req_local_position, sizeof(topic.mode_req_local_position));
	buf.iterator += sizeof(topic.mode_req_local_position);
	buf.offset += sizeof(topic.mode_req_local_position);
	static_assert(sizeof(topic.mode_req_local_position_relaxed) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.mode_req_local_position_relaxed, sizeof(topic.mode_req_local_position_relaxed));
	buf.iterator += sizeof(topic.mode_req_local_position_relaxed);
	buf.offset += sizeof(topic.mode_req_local_position_relaxed);
	static_assert(sizeof(topic.mode_req_global_position) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.mode_req_global_position, sizeof(topic.mode_req_global_position));
	buf.iterator += sizeof(topic.mode_req_global_position);
	buf.offset += sizeof(topic.mode_req_global_position);
	static_assert(sizeof(topic.mode_req_mission) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.mode_req_mission, sizeof(topic.mode_req_mission));
	buf.iterator += sizeof(topic.mode_req_mission);
	buf.offset += sizeof(topic.mode_req_mission);
	static_assert(sizeof(topic.mode_req_home_position) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.mode_req_home_position, sizeof(topic.mode_req_home_position));
	buf.iterator += sizeof(topic.mode_req_home_position);
	buf.offset += sizeof(topic.mode_req_home_position);
	static_assert(sizeof(topic.mode_req_prevent_arming) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.mode_req_prevent_arming, sizeof(topic.mode_req_prevent_arming));
	buf.iterator += sizeof(topic.mode_req_prevent_arming);
	buf.offset += sizeof(topic.mode_req_prevent_arming);
	static_assert(sizeof(topic.mode_req_manual_control) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.mode_req_manual_control, sizeof(topic.mode_req_manual_control));
	buf.iterator += sizeof(topic.mode_req_manual_control);
	buf.offset += sizeof(topic.mode_req_manual_control);
	return true;
}

static inline bool ucdr_deserialize_arming_check_reply(ucdrBuffer& buf, arming_check_reply_s& topic, int64_t time_offset = 0)
{
	static_assert(sizeof(topic.timestamp) == 8, "size mismatch");
	memcpy(&topic.timestamp, buf.iterator, sizeof(topic.timestamp));
	if (topic.timestamp == 0) topic.timestamp = hrt_absolute_time();
	else topic.timestamp = math::min(topic.timestamp - time_offset, hrt_absolute_time());
	buf.iterator += sizeof(topic.timestamp);
	buf.offset += sizeof(topic.timestamp);
	static_assert(sizeof(topic.request_id) == 1, "size mismatch");
	memcpy(&topic.request_id, buf.iterator, sizeof(topic.request_id));
	buf.iterator += sizeof(topic.request_id);
	buf.offset += sizeof(topic.request_id);
	static_assert(sizeof(topic.registration_id) == 1, "size mismatch");
	memcpy(&topic.registration_id, buf.iterator, sizeof(topic.registration_id));
	buf.iterator += sizeof(topic.registration_id);
	buf.offset += sizeof(topic.registration_id);
	static_assert(sizeof(topic.health_component_index) == 1, "size mismatch");
	memcpy(&topic.health_component_index, buf.iterator, sizeof(topic.health_component_index));
	buf.iterator += sizeof(topic.health_component_index);
	buf.offset += sizeof(topic.health_component_index);
	static_assert(sizeof(topic.health_component_is_present) == 1, "size mismatch");
	memcpy(&topic.health_component_is_present, buf.iterator, sizeof(topic.health_component_is_present));
	buf.iterator += sizeof(topic.health_component_is_present);
	buf.offset += sizeof(topic.health_component_is_present);
	static_assert(sizeof(topic.health_component_warning) == 1, "size mismatch");
	memcpy(&topic.health_component_warning, buf.iterator, sizeof(topic.health_component_warning));
	buf.iterator += sizeof(topic.health_component_warning);
	buf.offset += sizeof(topic.health_component_warning);
	static_assert(sizeof(topic.health_component_error) == 1, "size mismatch");
	memcpy(&topic.health_component_error, buf.iterator, sizeof(topic.health_component_error));
	buf.iterator += sizeof(topic.health_component_error);
	buf.offset += sizeof(topic.health_component_error);
	static_assert(sizeof(topic.can_arm_and_run) == 1, "size mismatch");
	memcpy(&topic.can_arm_and_run, buf.iterator, sizeof(topic.can_arm_and_run));
	buf.iterator += sizeof(topic.can_arm_and_run);
	buf.offset += sizeof(topic.can_arm_and_run);
	static_assert(sizeof(topic.num_events) == 1, "size mismatch");
	memcpy(&topic.num_events, buf.iterator, sizeof(topic.num_events));
	buf.iterator += sizeof(topic.num_events);
	buf.offset += sizeof(topic.num_events);
	static_assert(sizeof(topic.events[0].timestamp) == 8, "size mismatch");
	memcpy(&topic.events[0].timestamp, buf.iterator, sizeof(topic.events[0].timestamp));
	buf.iterator += sizeof(topic.events[0].timestamp);
	buf.offset += sizeof(topic.events[0].timestamp);
	static_assert(sizeof(topic.events[0].id) == 4, "size mismatch");
	memcpy(&topic.events[0].id, buf.iterator, sizeof(topic.events[0].id));
	buf.iterator += sizeof(topic.events[0].id);
	buf.offset += sizeof(topic.events[0].id);
	static_assert(sizeof(topic.events[0].event_sequence) == 2, "size mismatch");
	memcpy(&topic.events[0].event_sequence, buf.iterator, sizeof(topic.events[0].event_sequence));
	buf.iterator += sizeof(topic.events[0].event_sequence);
	buf.offset += sizeof(topic.events[0].event_sequence);
	static_assert(sizeof(topic.events[0].arguments) == 25, "size mismatch");
	memcpy(&topic.events[0].arguments, buf.iterator, sizeof(topic.events[0].arguments));
	buf.iterator += sizeof(topic.events[0].arguments);
	buf.offset += sizeof(topic.events[0].arguments);
	static_assert(sizeof(topic.events[0].log_levels) == 1, "size mismatch");
	memcpy(&topic.events[0].log_levels, buf.iterator, sizeof(topic.events[0].log_levels));
	buf.iterator += sizeof(topic.events[0].log_levels);
	buf.offset += sizeof(topic.events[0].log_levels);
	static_assert(sizeof(topic.events[1].timestamp) == 8, "size mismatch");
	memcpy(&topic.events[1].timestamp, buf.iterator, sizeof(topic.events[1].timestamp));
	buf.iterator += sizeof(topic.events[1].timestamp);
	buf.offset += sizeof(topic.events[1].timestamp);
	static_assert(sizeof(topic.events[1].id) == 4, "size mismatch");
	memcpy(&topic.events[1].id, buf.iterator, sizeof(topic.events[1].id));
	buf.iterator += sizeof(topic.events[1].id);
	buf.offset += sizeof(topic.events[1].id);
	static_assert(sizeof(topic.events[1].event_sequence) == 2, "size mismatch");
	memcpy(&topic.events[1].event_sequence, buf.iterator, sizeof(topic.events[1].event_sequence));
	buf.iterator += sizeof(topic.events[1].event_sequence);
	buf.offset += sizeof(topic.events[1].event_sequence);
	static_assert(sizeof(topic.events[1].arguments) == 25, "size mismatch");
	memcpy(&topic.events[1].arguments, buf.iterator, sizeof(topic.events[1].arguments));
	buf.iterator += sizeof(topic.events[1].arguments);
	buf.offset += sizeof(topic.events[1].arguments);
	static_assert(sizeof(topic.events[1].log_levels) == 1, "size mismatch");
	memcpy(&topic.events[1].log_levels, buf.iterator, sizeof(topic.events[1].log_levels));
	buf.iterator += sizeof(topic.events[1].log_levels);
	buf.offset += sizeof(topic.events[1].log_levels);
	static_assert(sizeof(topic.events[2].timestamp) == 8, "size mismatch");
	memcpy(&topic.events[2].timestamp, buf.iterator, sizeof(topic.events[2].timestamp));
	buf.iterator += sizeof(topic.events[2].timestamp);
	buf.offset += sizeof(topic.events[2].timestamp);
	static_assert(sizeof(topic.events[2].id) == 4, "size mismatch");
	memcpy(&topic.events[2].id, buf.iterator, sizeof(topic.events[2].id));
	buf.iterator += sizeof(topic.events[2].id);
	buf.offset += sizeof(topic.events[2].id);
	static_assert(sizeof(topic.events[2].event_sequence) == 2, "size mismatch");
	memcpy(&topic.events[2].event_sequence, buf.iterator, sizeof(topic.events[2].event_sequence));
	buf.iterator += sizeof(topic.events[2].event_sequence);
	buf.offset += sizeof(topic.events[2].event_sequence);
	static_assert(sizeof(topic.events[2].arguments) == 25, "size mismatch");
	memcpy(&topic.events[2].arguments, buf.iterator, sizeof(topic.events[2].arguments));
	buf.iterator += sizeof(topic.events[2].arguments);
	buf.offset += sizeof(topic.events[2].arguments);
	static_assert(sizeof(topic.events[2].log_levels) == 1, "size mismatch");
	memcpy(&topic.events[2].log_levels, buf.iterator, sizeof(topic.events[2].log_levels));
	buf.iterator += sizeof(topic.events[2].log_levels);
	buf.offset += sizeof(topic.events[2].log_levels);
	static_assert(sizeof(topic.events[3].timestamp) == 8, "size mismatch");
	memcpy(&topic.events[3].timestamp, buf.iterator, sizeof(topic.events[3].timestamp));
	buf.iterator += sizeof(topic.events[3].timestamp);
	buf.offset += sizeof(topic.events[3].timestamp);
	static_assert(sizeof(topic.events[3].id) == 4, "size mismatch");
	memcpy(&topic.events[3].id, buf.iterator, sizeof(topic.events[3].id));
	buf.iterator += sizeof(topic.events[3].id);
	buf.offset += sizeof(topic.events[3].id);
	static_assert(sizeof(topic.events[3].event_sequence) == 2, "size mismatch");
	memcpy(&topic.events[3].event_sequence, buf.iterator, sizeof(topic.events[3].event_sequence));
	buf.iterator += sizeof(topic.events[3].event_sequence);
	buf.offset += sizeof(topic.events[3].event_sequence);
	static_assert(sizeof(topic.events[3].arguments) == 25, "size mismatch");
	memcpy(&topic.events[3].arguments, buf.iterator, sizeof(topic.events[3].arguments));
	buf.iterator += sizeof(topic.events[3].arguments);
	buf.offset += sizeof(topic.events[3].arguments);
	static_assert(sizeof(topic.events[3].log_levels) == 1, "size mismatch");
	memcpy(&topic.events[3].log_levels, buf.iterator, sizeof(topic.events[3].log_levels));
	buf.iterator += sizeof(topic.events[3].log_levels);
	buf.offset += sizeof(topic.events[3].log_levels);
	static_assert(sizeof(topic.events[4].timestamp) == 8, "size mismatch");
	memcpy(&topic.events[4].timestamp, buf.iterator, sizeof(topic.events[4].timestamp));
	buf.iterator += sizeof(topic.events[4].timestamp);
	buf.offset += sizeof(topic.events[4].timestamp);
	static_assert(sizeof(topic.events[4].id) == 4, "size mismatch");
	memcpy(&topic.events[4].id, buf.iterator, sizeof(topic.events[4].id));
	buf.iterator += sizeof(topic.events[4].id);
	buf.offset += sizeof(topic.events[4].id);
	static_assert(sizeof(topic.events[4].event_sequence) == 2, "size mismatch");
	memcpy(&topic.events[4].event_sequence, buf.iterator, sizeof(topic.events[4].event_sequence));
	buf.iterator += sizeof(topic.events[4].event_sequence);
	buf.offset += sizeof(topic.events[4].event_sequence);
	static_assert(sizeof(topic.events[4].arguments) == 25, "size mismatch");
	memcpy(&topic.events[4].arguments, buf.iterator, sizeof(topic.events[4].arguments));
	buf.iterator += sizeof(topic.events[4].arguments);
	buf.offset += sizeof(topic.events[4].arguments);
	static_assert(sizeof(topic.events[4].log_levels) == 1, "size mismatch");
	memcpy(&topic.events[4].log_levels, buf.iterator, sizeof(topic.events[4].log_levels));
	buf.iterator += sizeof(topic.events[4].log_levels);
	buf.offset += sizeof(topic.events[4].log_levels);
	static_assert(sizeof(topic.mode_req_angular_velocity) == 1, "size mismatch");
	memcpy(&topic.mode_req_angular_velocity, buf.iterator, sizeof(topic.mode_req_angular_velocity));
	buf.iterator += sizeof(topic.mode_req_angular_velocity);
	buf.offset += sizeof(topic.mode_req_angular_velocity);
	static_assert(sizeof(topic.mode_req_attitude) == 1, "size mismatch");
	memcpy(&topic.mode_req_attitude, buf.iterator, sizeof(topic.mode_req_attitude));
	buf.iterator += sizeof(topic.mode_req_attitude);
	buf.offset += sizeof(topic.mode_req_attitude);
	static_assert(sizeof(topic.mode_req_local_alt) == 1, "size mismatch");
	memcpy(&topic.mode_req_local_alt, buf.iterator, sizeof(topic.mode_req_local_alt));
	buf.iterator += sizeof(topic.mode_req_local_alt);
	buf.offset += sizeof(topic.mode_req_local_alt);
	static_assert(sizeof(topic.mode_req_local_position) == 1, "size mismatch");
	memcpy(&topic.mode_req_local_position, buf.iterator, sizeof(topic.mode_req_local_position));
	buf.iterator += sizeof(topic.mode_req_local_position);
	buf.offset += sizeof(topic.mode_req_local_position);
	static_assert(sizeof(topic.mode_req_local_position_relaxed) == 1, "size mismatch");
	memcpy(&topic.mode_req_local_position_relaxed, buf.iterator, sizeof(topic.mode_req_local_position_relaxed));
	buf.iterator += sizeof(topic.mode_req_local_position_relaxed);
	buf.offset += sizeof(topic.mode_req_local_position_relaxed);
	static_assert(sizeof(topic.mode_req_global_position) == 1, "size mismatch");
	memcpy(&topic.mode_req_global_position, buf.iterator, sizeof(topic.mode_req_global_position));
	buf.iterator += sizeof(topic.mode_req_global_position);
	buf.offset += sizeof(topic.mode_req_global_position);
	static_assert(sizeof(topic.mode_req_mission) == 1, "size mismatch");
	memcpy(&topic.mode_req_mission, buf.iterator, sizeof(topic.mode_req_mission));
	buf.iterator += sizeof(topic.mode_req_mission);
	buf.offset += sizeof(topic.mode_req_mission);
	static_assert(sizeof(topic.mode_req_home_position) == 1, "size mismatch");
	memcpy(&topic.mode_req_home_position, buf.iterator, sizeof(topic.mode_req_home_position));
	buf.iterator += sizeof(topic.mode_req_home_position);
	buf.offset += sizeof(topic.mode_req_home_position);
	static_assert(sizeof(topic.mode_req_prevent_arming) == 1, "size mismatch");
	memcpy(&topic.mode_req_prevent_arming, buf.iterator, sizeof(topic.mode_req_prevent_arming));
	buf.iterator += sizeof(topic.mode_req_prevent_arming);
	buf.offset += sizeof(topic.mode_req_prevent_arming);
	static_assert(sizeof(topic.mode_req_manual_control) == 1, "size mismatch");
	memcpy(&topic.mode_req_manual_control, buf.iterator, sizeof(topic.mode_req_manual_control));
	buf.iterator += sizeof(topic.mode_req_manual_control);
	buf.offset += sizeof(topic.mode_req_manual_control);
	return true;
}
