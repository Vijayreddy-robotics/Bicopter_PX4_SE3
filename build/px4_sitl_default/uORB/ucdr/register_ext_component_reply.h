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
#include <uORB/topics/register_ext_component_reply.h>


static inline constexpr int ucdr_topic_size_register_ext_component_reply()
{
	return 48;
}

static inline bool ucdr_serialize_register_ext_component_reply(const void* data, ucdrBuffer& buf, int64_t time_offset = 0)
{
	const register_ext_component_reply_s& topic = *static_cast<const register_ext_component_reply_s*>(data);
	static_assert(sizeof(topic.timestamp) == 8, "size mismatch");
	const uint64_t timestamp_adjusted = topic.timestamp + time_offset;
	memcpy(buf.iterator, &timestamp_adjusted, sizeof(topic.timestamp));
	buf.iterator += sizeof(topic.timestamp);
	buf.offset += sizeof(topic.timestamp);
	static_assert(sizeof(topic.request_id) == 8, "size mismatch");
	memcpy(buf.iterator, &topic.request_id, sizeof(topic.request_id));
	buf.iterator += sizeof(topic.request_id);
	buf.offset += sizeof(topic.request_id);
	static_assert(sizeof(topic.name) == 25, "size mismatch");
	memcpy(buf.iterator, &topic.name, sizeof(topic.name));
	buf.iterator += sizeof(topic.name);
	buf.offset += sizeof(topic.name);
	buf.iterator += 1; // padding
	buf.offset += 1; // padding
	static_assert(sizeof(topic.px4_ros2_api_version) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.px4_ros2_api_version, sizeof(topic.px4_ros2_api_version));
	buf.iterator += sizeof(topic.px4_ros2_api_version);
	buf.offset += sizeof(topic.px4_ros2_api_version);
	static_assert(sizeof(topic.success) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.success, sizeof(topic.success));
	buf.iterator += sizeof(topic.success);
	buf.offset += sizeof(topic.success);
	static_assert(sizeof(topic.arming_check_id) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.arming_check_id, sizeof(topic.arming_check_id));
	buf.iterator += sizeof(topic.arming_check_id);
	buf.offset += sizeof(topic.arming_check_id);
	static_assert(sizeof(topic.mode_id) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.mode_id, sizeof(topic.mode_id));
	buf.iterator += sizeof(topic.mode_id);
	buf.offset += sizeof(topic.mode_id);
	static_assert(sizeof(topic.mode_executor_id) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.mode_executor_id, sizeof(topic.mode_executor_id));
	buf.iterator += sizeof(topic.mode_executor_id);
	buf.offset += sizeof(topic.mode_executor_id);
	return true;
}

static inline bool ucdr_deserialize_register_ext_component_reply(ucdrBuffer& buf, register_ext_component_reply_s& topic, int64_t time_offset = 0)
{
	static_assert(sizeof(topic.timestamp) == 8, "size mismatch");
	memcpy(&topic.timestamp, buf.iterator, sizeof(topic.timestamp));
	if (topic.timestamp == 0) topic.timestamp = hrt_absolute_time();
	else topic.timestamp = math::min(topic.timestamp - time_offset, hrt_absolute_time());
	buf.iterator += sizeof(topic.timestamp);
	buf.offset += sizeof(topic.timestamp);
	static_assert(sizeof(topic.request_id) == 8, "size mismatch");
	memcpy(&topic.request_id, buf.iterator, sizeof(topic.request_id));
	buf.iterator += sizeof(topic.request_id);
	buf.offset += sizeof(topic.request_id);
	static_assert(sizeof(topic.name) == 25, "size mismatch");
	memcpy(&topic.name, buf.iterator, sizeof(topic.name));
	buf.iterator += sizeof(topic.name);
	buf.offset += sizeof(topic.name);
	buf.iterator += 1; // padding
	buf.offset += 1; // padding
	static_assert(sizeof(topic.px4_ros2_api_version) == 2, "size mismatch");
	memcpy(&topic.px4_ros2_api_version, buf.iterator, sizeof(topic.px4_ros2_api_version));
	buf.iterator += sizeof(topic.px4_ros2_api_version);
	buf.offset += sizeof(topic.px4_ros2_api_version);
	static_assert(sizeof(topic.success) == 1, "size mismatch");
	memcpy(&topic.success, buf.iterator, sizeof(topic.success));
	buf.iterator += sizeof(topic.success);
	buf.offset += sizeof(topic.success);
	static_assert(sizeof(topic.arming_check_id) == 1, "size mismatch");
	memcpy(&topic.arming_check_id, buf.iterator, sizeof(topic.arming_check_id));
	buf.iterator += sizeof(topic.arming_check_id);
	buf.offset += sizeof(topic.arming_check_id);
	static_assert(sizeof(topic.mode_id) == 1, "size mismatch");
	memcpy(&topic.mode_id, buf.iterator, sizeof(topic.mode_id));
	buf.iterator += sizeof(topic.mode_id);
	buf.offset += sizeof(topic.mode_id);
	static_assert(sizeof(topic.mode_executor_id) == 1, "size mismatch");
	memcpy(&topic.mode_executor_id, buf.iterator, sizeof(topic.mode_executor_id));
	buf.iterator += sizeof(topic.mode_executor_id);
	buf.offset += sizeof(topic.mode_executor_id);
	return true;
}
