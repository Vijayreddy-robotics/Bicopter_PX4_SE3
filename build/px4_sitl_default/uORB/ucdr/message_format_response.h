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
#include <uORB/topics/message_format_response.h>


static inline constexpr int ucdr_topic_size_message_format_response()
{
	return 68;
}

static inline bool ucdr_serialize_message_format_response(const void* data, ucdrBuffer& buf, int64_t time_offset = 0)
{
	const message_format_response_s& topic = *static_cast<const message_format_response_s*>(data);
	static_assert(sizeof(topic.timestamp) == 8, "size mismatch");
	const uint64_t timestamp_adjusted = topic.timestamp + time_offset;
	memcpy(buf.iterator, &timestamp_adjusted, sizeof(topic.timestamp));
	buf.iterator += sizeof(topic.timestamp);
	buf.offset += sizeof(topic.timestamp);
	static_assert(sizeof(topic.protocol_version) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.protocol_version, sizeof(topic.protocol_version));
	buf.iterator += sizeof(topic.protocol_version);
	buf.offset += sizeof(topic.protocol_version);
	static_assert(sizeof(topic.topic_name) == 50, "size mismatch");
	memcpy(buf.iterator, &topic.topic_name, sizeof(topic.topic_name));
	buf.iterator += sizeof(topic.topic_name);
	buf.offset += sizeof(topic.topic_name);
	static_assert(sizeof(topic.success) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.success, sizeof(topic.success));
	buf.iterator += sizeof(topic.success);
	buf.offset += sizeof(topic.success);
	buf.iterator += 3; // padding
	buf.offset += 3; // padding
	static_assert(sizeof(topic.message_hash) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.message_hash, sizeof(topic.message_hash));
	buf.iterator += sizeof(topic.message_hash);
	buf.offset += sizeof(topic.message_hash);
	return true;
}

static inline bool ucdr_deserialize_message_format_response(ucdrBuffer& buf, message_format_response_s& topic, int64_t time_offset = 0)
{
	static_assert(sizeof(topic.timestamp) == 8, "size mismatch");
	memcpy(&topic.timestamp, buf.iterator, sizeof(topic.timestamp));
	if (topic.timestamp == 0) topic.timestamp = hrt_absolute_time();
	else topic.timestamp = math::min(topic.timestamp - time_offset, hrt_absolute_time());
	buf.iterator += sizeof(topic.timestamp);
	buf.offset += sizeof(topic.timestamp);
	static_assert(sizeof(topic.protocol_version) == 2, "size mismatch");
	memcpy(&topic.protocol_version, buf.iterator, sizeof(topic.protocol_version));
	buf.iterator += sizeof(topic.protocol_version);
	buf.offset += sizeof(topic.protocol_version);
	static_assert(sizeof(topic.topic_name) == 50, "size mismatch");
	memcpy(&topic.topic_name, buf.iterator, sizeof(topic.topic_name));
	buf.iterator += sizeof(topic.topic_name);
	buf.offset += sizeof(topic.topic_name);
	static_assert(sizeof(topic.success) == 1, "size mismatch");
	memcpy(&topic.success, buf.iterator, sizeof(topic.success));
	buf.iterator += sizeof(topic.success);
	buf.offset += sizeof(topic.success);
	buf.iterator += 3; // padding
	buf.offset += 3; // padding
	static_assert(sizeof(topic.message_hash) == 4, "size mismatch");
	memcpy(&topic.message_hash, buf.iterator, sizeof(topic.message_hash));
	buf.iterator += sizeof(topic.message_hash);
	buf.offset += sizeof(topic.message_hash);
	return true;
}
