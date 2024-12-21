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
#include <uORB/topics/goto_setpoint.h>


static inline constexpr int ucdr_topic_size_goto_setpoint()
{
	return 52;
}

static inline bool ucdr_serialize_goto_setpoint(const void* data, ucdrBuffer& buf, int64_t time_offset = 0)
{
	const goto_setpoint_s& topic = *static_cast<const goto_setpoint_s*>(data);
	static_assert(sizeof(topic.timestamp) == 8, "size mismatch");
	const uint64_t timestamp_adjusted = topic.timestamp + time_offset;
	memcpy(buf.iterator, &timestamp_adjusted, sizeof(topic.timestamp));
	buf.iterator += sizeof(topic.timestamp);
	buf.offset += sizeof(topic.timestamp);
	static_assert(sizeof(topic.position) == 12, "size mismatch");
	memcpy(buf.iterator, &topic.position, sizeof(topic.position));
	buf.iterator += sizeof(topic.position);
	buf.offset += sizeof(topic.position);
	static_assert(sizeof(topic.flag_control_heading) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.flag_control_heading, sizeof(topic.flag_control_heading));
	buf.iterator += sizeof(topic.flag_control_heading);
	buf.offset += sizeof(topic.flag_control_heading);
	buf.iterator += 3; // padding
	buf.offset += 3; // padding
	static_assert(sizeof(topic.heading) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.heading, sizeof(topic.heading));
	buf.iterator += sizeof(topic.heading);
	buf.offset += sizeof(topic.heading);
	static_assert(sizeof(topic.flag_set_max_horizontal_speed) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.flag_set_max_horizontal_speed, sizeof(topic.flag_set_max_horizontal_speed));
	buf.iterator += sizeof(topic.flag_set_max_horizontal_speed);
	buf.offset += sizeof(topic.flag_set_max_horizontal_speed);
	buf.iterator += 3; // padding
	buf.offset += 3; // padding
	static_assert(sizeof(topic.max_horizontal_speed) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.max_horizontal_speed, sizeof(topic.max_horizontal_speed));
	buf.iterator += sizeof(topic.max_horizontal_speed);
	buf.offset += sizeof(topic.max_horizontal_speed);
	static_assert(sizeof(topic.flag_set_max_vertical_speed) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.flag_set_max_vertical_speed, sizeof(topic.flag_set_max_vertical_speed));
	buf.iterator += sizeof(topic.flag_set_max_vertical_speed);
	buf.offset += sizeof(topic.flag_set_max_vertical_speed);
	buf.iterator += 3; // padding
	buf.offset += 3; // padding
	static_assert(sizeof(topic.max_vertical_speed) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.max_vertical_speed, sizeof(topic.max_vertical_speed));
	buf.iterator += sizeof(topic.max_vertical_speed);
	buf.offset += sizeof(topic.max_vertical_speed);
	static_assert(sizeof(topic.flag_set_max_heading_rate) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.flag_set_max_heading_rate, sizeof(topic.flag_set_max_heading_rate));
	buf.iterator += sizeof(topic.flag_set_max_heading_rate);
	buf.offset += sizeof(topic.flag_set_max_heading_rate);
	buf.iterator += 3; // padding
	buf.offset += 3; // padding
	static_assert(sizeof(topic.max_heading_rate) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.max_heading_rate, sizeof(topic.max_heading_rate));
	buf.iterator += sizeof(topic.max_heading_rate);
	buf.offset += sizeof(topic.max_heading_rate);
	return true;
}

static inline bool ucdr_deserialize_goto_setpoint(ucdrBuffer& buf, goto_setpoint_s& topic, int64_t time_offset = 0)
{
	static_assert(sizeof(topic.timestamp) == 8, "size mismatch");
	memcpy(&topic.timestamp, buf.iterator, sizeof(topic.timestamp));
	if (topic.timestamp == 0) topic.timestamp = hrt_absolute_time();
	else topic.timestamp = math::min(topic.timestamp - time_offset, hrt_absolute_time());
	buf.iterator += sizeof(topic.timestamp);
	buf.offset += sizeof(topic.timestamp);
	static_assert(sizeof(topic.position) == 12, "size mismatch");
	memcpy(&topic.position, buf.iterator, sizeof(topic.position));
	buf.iterator += sizeof(topic.position);
	buf.offset += sizeof(topic.position);
	static_assert(sizeof(topic.flag_control_heading) == 1, "size mismatch");
	memcpy(&topic.flag_control_heading, buf.iterator, sizeof(topic.flag_control_heading));
	buf.iterator += sizeof(topic.flag_control_heading);
	buf.offset += sizeof(topic.flag_control_heading);
	buf.iterator += 3; // padding
	buf.offset += 3; // padding
	static_assert(sizeof(topic.heading) == 4, "size mismatch");
	memcpy(&topic.heading, buf.iterator, sizeof(topic.heading));
	buf.iterator += sizeof(topic.heading);
	buf.offset += sizeof(topic.heading);
	static_assert(sizeof(topic.flag_set_max_horizontal_speed) == 1, "size mismatch");
	memcpy(&topic.flag_set_max_horizontal_speed, buf.iterator, sizeof(topic.flag_set_max_horizontal_speed));
	buf.iterator += sizeof(topic.flag_set_max_horizontal_speed);
	buf.offset += sizeof(topic.flag_set_max_horizontal_speed);
	buf.iterator += 3; // padding
	buf.offset += 3; // padding
	static_assert(sizeof(topic.max_horizontal_speed) == 4, "size mismatch");
	memcpy(&topic.max_horizontal_speed, buf.iterator, sizeof(topic.max_horizontal_speed));
	buf.iterator += sizeof(topic.max_horizontal_speed);
	buf.offset += sizeof(topic.max_horizontal_speed);
	static_assert(sizeof(topic.flag_set_max_vertical_speed) == 1, "size mismatch");
	memcpy(&topic.flag_set_max_vertical_speed, buf.iterator, sizeof(topic.flag_set_max_vertical_speed));
	buf.iterator += sizeof(topic.flag_set_max_vertical_speed);
	buf.offset += sizeof(topic.flag_set_max_vertical_speed);
	buf.iterator += 3; // padding
	buf.offset += 3; // padding
	static_assert(sizeof(topic.max_vertical_speed) == 4, "size mismatch");
	memcpy(&topic.max_vertical_speed, buf.iterator, sizeof(topic.max_vertical_speed));
	buf.iterator += sizeof(topic.max_vertical_speed);
	buf.offset += sizeof(topic.max_vertical_speed);
	static_assert(sizeof(topic.flag_set_max_heading_rate) == 1, "size mismatch");
	memcpy(&topic.flag_set_max_heading_rate, buf.iterator, sizeof(topic.flag_set_max_heading_rate));
	buf.iterator += sizeof(topic.flag_set_max_heading_rate);
	buf.offset += sizeof(topic.flag_set_max_heading_rate);
	buf.iterator += 3; // padding
	buf.offset += 3; // padding
	static_assert(sizeof(topic.max_heading_rate) == 4, "size mismatch");
	memcpy(&topic.max_heading_rate, buf.iterator, sizeof(topic.max_heading_rate));
	buf.iterator += sizeof(topic.max_heading_rate);
	buf.offset += sizeof(topic.max_heading_rate);
	return true;
}
