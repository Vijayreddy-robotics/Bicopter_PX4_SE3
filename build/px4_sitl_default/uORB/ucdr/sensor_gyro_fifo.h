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
#include <uORB/topics/sensor_gyro_fifo.h>


static inline constexpr int ucdr_topic_size_sensor_gyro_fifo()
{
	return 222;
}

static inline bool ucdr_serialize_sensor_gyro_fifo(const void* data, ucdrBuffer& buf, int64_t time_offset = 0)
{
	const sensor_gyro_fifo_s& topic = *static_cast<const sensor_gyro_fifo_s*>(data);
	static_assert(sizeof(topic.timestamp) == 8, "size mismatch");
	const uint64_t timestamp_adjusted = topic.timestamp + time_offset;
	memcpy(buf.iterator, &timestamp_adjusted, sizeof(topic.timestamp));
	buf.iterator += sizeof(topic.timestamp);
	buf.offset += sizeof(topic.timestamp);
	static_assert(sizeof(topic.timestamp_sample) == 8, "size mismatch");
	const uint64_t timestamp_sample_adjusted = topic.timestamp_sample + time_offset;
	memcpy(buf.iterator, &timestamp_sample_adjusted, sizeof(topic.timestamp_sample));
	buf.iterator += sizeof(topic.timestamp_sample);
	buf.offset += sizeof(topic.timestamp_sample);
	static_assert(sizeof(topic.device_id) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.device_id, sizeof(topic.device_id));
	buf.iterator += sizeof(topic.device_id);
	buf.offset += sizeof(topic.device_id);
	static_assert(sizeof(topic.dt) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.dt, sizeof(topic.dt));
	buf.iterator += sizeof(topic.dt);
	buf.offset += sizeof(topic.dt);
	static_assert(sizeof(topic.scale) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.scale, sizeof(topic.scale));
	buf.iterator += sizeof(topic.scale);
	buf.offset += sizeof(topic.scale);
	static_assert(sizeof(topic.samples) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.samples, sizeof(topic.samples));
	buf.iterator += sizeof(topic.samples);
	buf.offset += sizeof(topic.samples);
	buf.iterator += 1; // padding
	buf.offset += 1; // padding
	static_assert(sizeof(topic.x) == 64, "size mismatch");
	memcpy(buf.iterator, &topic.x, sizeof(topic.x));
	buf.iterator += sizeof(topic.x);
	buf.offset += sizeof(topic.x);
	static_assert(sizeof(topic.y) == 64, "size mismatch");
	memcpy(buf.iterator, &topic.y, sizeof(topic.y));
	buf.iterator += sizeof(topic.y);
	buf.offset += sizeof(topic.y);
	static_assert(sizeof(topic.z) == 64, "size mismatch");
	memcpy(buf.iterator, &topic.z, sizeof(topic.z));
	buf.iterator += sizeof(topic.z);
	buf.offset += sizeof(topic.z);
	return true;
}

static inline bool ucdr_deserialize_sensor_gyro_fifo(ucdrBuffer& buf, sensor_gyro_fifo_s& topic, int64_t time_offset = 0)
{
	static_assert(sizeof(topic.timestamp) == 8, "size mismatch");
	memcpy(&topic.timestamp, buf.iterator, sizeof(topic.timestamp));
	if (topic.timestamp == 0) topic.timestamp = hrt_absolute_time();
	else topic.timestamp = math::min(topic.timestamp - time_offset, hrt_absolute_time());
	buf.iterator += sizeof(topic.timestamp);
	buf.offset += sizeof(topic.timestamp);
	static_assert(sizeof(topic.timestamp_sample) == 8, "size mismatch");
	memcpy(&topic.timestamp_sample, buf.iterator, sizeof(topic.timestamp_sample));
	if (topic.timestamp_sample == 0) topic.timestamp_sample = hrt_absolute_time();
	else topic.timestamp_sample = math::min(topic.timestamp_sample - time_offset, hrt_absolute_time());
	buf.iterator += sizeof(topic.timestamp_sample);
	buf.offset += sizeof(topic.timestamp_sample);
	static_assert(sizeof(topic.device_id) == 4, "size mismatch");
	memcpy(&topic.device_id, buf.iterator, sizeof(topic.device_id));
	buf.iterator += sizeof(topic.device_id);
	buf.offset += sizeof(topic.device_id);
	static_assert(sizeof(topic.dt) == 4, "size mismatch");
	memcpy(&topic.dt, buf.iterator, sizeof(topic.dt));
	buf.iterator += sizeof(topic.dt);
	buf.offset += sizeof(topic.dt);
	static_assert(sizeof(topic.scale) == 4, "size mismatch");
	memcpy(&topic.scale, buf.iterator, sizeof(topic.scale));
	buf.iterator += sizeof(topic.scale);
	buf.offset += sizeof(topic.scale);
	static_assert(sizeof(topic.samples) == 1, "size mismatch");
	memcpy(&topic.samples, buf.iterator, sizeof(topic.samples));
	buf.iterator += sizeof(topic.samples);
	buf.offset += sizeof(topic.samples);
	buf.iterator += 1; // padding
	buf.offset += 1; // padding
	static_assert(sizeof(topic.x) == 64, "size mismatch");
	memcpy(&topic.x, buf.iterator, sizeof(topic.x));
	buf.iterator += sizeof(topic.x);
	buf.offset += sizeof(topic.x);
	static_assert(sizeof(topic.y) == 64, "size mismatch");
	memcpy(&topic.y, buf.iterator, sizeof(topic.y));
	buf.iterator += sizeof(topic.y);
	buf.offset += sizeof(topic.y);
	static_assert(sizeof(topic.z) == 64, "size mismatch");
	memcpy(&topic.z, buf.iterator, sizeof(topic.z));
	buf.iterator += sizeof(topic.z);
	buf.offset += sizeof(topic.z);
	return true;
}
