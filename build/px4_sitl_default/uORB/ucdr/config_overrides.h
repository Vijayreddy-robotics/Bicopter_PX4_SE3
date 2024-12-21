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
#include <uORB/topics/config_overrides.h>


static inline constexpr int ucdr_topic_size_config_overrides()
{
	return 14;
}

static inline bool ucdr_serialize_config_overrides(const void* data, ucdrBuffer& buf, int64_t time_offset = 0)
{
	const config_overrides_s& topic = *static_cast<const config_overrides_s*>(data);
	static_assert(sizeof(topic.timestamp) == 8, "size mismatch");
	const uint64_t timestamp_adjusted = topic.timestamp + time_offset;
	memcpy(buf.iterator, &timestamp_adjusted, sizeof(topic.timestamp));
	buf.iterator += sizeof(topic.timestamp);
	buf.offset += sizeof(topic.timestamp);
	static_assert(sizeof(topic.disable_auto_disarm) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.disable_auto_disarm, sizeof(topic.disable_auto_disarm));
	buf.iterator += sizeof(topic.disable_auto_disarm);
	buf.offset += sizeof(topic.disable_auto_disarm);
	static_assert(sizeof(topic.defer_failsafes) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.defer_failsafes, sizeof(topic.defer_failsafes));
	buf.iterator += sizeof(topic.defer_failsafes);
	buf.offset += sizeof(topic.defer_failsafes);
	static_assert(sizeof(topic.defer_failsafes_timeout_s) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.defer_failsafes_timeout_s, sizeof(topic.defer_failsafes_timeout_s));
	buf.iterator += sizeof(topic.defer_failsafes_timeout_s);
	buf.offset += sizeof(topic.defer_failsafes_timeout_s);
	static_assert(sizeof(topic.source_type) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.source_type, sizeof(topic.source_type));
	buf.iterator += sizeof(topic.source_type);
	buf.offset += sizeof(topic.source_type);
	static_assert(sizeof(topic.source_id) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.source_id, sizeof(topic.source_id));
	buf.iterator += sizeof(topic.source_id);
	buf.offset += sizeof(topic.source_id);
	return true;
}

static inline bool ucdr_deserialize_config_overrides(ucdrBuffer& buf, config_overrides_s& topic, int64_t time_offset = 0)
{
	static_assert(sizeof(topic.timestamp) == 8, "size mismatch");
	memcpy(&topic.timestamp, buf.iterator, sizeof(topic.timestamp));
	if (topic.timestamp == 0) topic.timestamp = hrt_absolute_time();
	else topic.timestamp = math::min(topic.timestamp - time_offset, hrt_absolute_time());
	buf.iterator += sizeof(topic.timestamp);
	buf.offset += sizeof(topic.timestamp);
	static_assert(sizeof(topic.disable_auto_disarm) == 1, "size mismatch");
	memcpy(&topic.disable_auto_disarm, buf.iterator, sizeof(topic.disable_auto_disarm));
	buf.iterator += sizeof(topic.disable_auto_disarm);
	buf.offset += sizeof(topic.disable_auto_disarm);
	static_assert(sizeof(topic.defer_failsafes) == 1, "size mismatch");
	memcpy(&topic.defer_failsafes, buf.iterator, sizeof(topic.defer_failsafes));
	buf.iterator += sizeof(topic.defer_failsafes);
	buf.offset += sizeof(topic.defer_failsafes);
	static_assert(sizeof(topic.defer_failsafes_timeout_s) == 2, "size mismatch");
	memcpy(&topic.defer_failsafes_timeout_s, buf.iterator, sizeof(topic.defer_failsafes_timeout_s));
	buf.iterator += sizeof(topic.defer_failsafes_timeout_s);
	buf.offset += sizeof(topic.defer_failsafes_timeout_s);
	static_assert(sizeof(topic.source_type) == 1, "size mismatch");
	memcpy(&topic.source_type, buf.iterator, sizeof(topic.source_type));
	buf.iterator += sizeof(topic.source_type);
	buf.offset += sizeof(topic.source_type);
	static_assert(sizeof(topic.source_id) == 1, "size mismatch");
	memcpy(&topic.source_id, buf.iterator, sizeof(topic.source_id));
	buf.iterator += sizeof(topic.source_id);
	buf.offset += sizeof(topic.source_id);
	return true;
}
