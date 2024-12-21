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
#include <uORB/topics/fuel_tank_status.h>


static inline constexpr int ucdr_topic_size_fuel_tank_status()
{
	return 40;
}

static inline bool ucdr_serialize_fuel_tank_status(const void* data, ucdrBuffer& buf, int64_t time_offset = 0)
{
	const fuel_tank_status_s& topic = *static_cast<const fuel_tank_status_s*>(data);
	static_assert(sizeof(topic.timestamp) == 8, "size mismatch");
	const uint64_t timestamp_adjusted = topic.timestamp + time_offset;
	memcpy(buf.iterator, &timestamp_adjusted, sizeof(topic.timestamp));
	buf.iterator += sizeof(topic.timestamp);
	buf.offset += sizeof(topic.timestamp);
	static_assert(sizeof(topic.maximum_fuel_capacity) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.maximum_fuel_capacity, sizeof(topic.maximum_fuel_capacity));
	buf.iterator += sizeof(topic.maximum_fuel_capacity);
	buf.offset += sizeof(topic.maximum_fuel_capacity);
	static_assert(sizeof(topic.consumed_fuel) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.consumed_fuel, sizeof(topic.consumed_fuel));
	buf.iterator += sizeof(topic.consumed_fuel);
	buf.offset += sizeof(topic.consumed_fuel);
	static_assert(sizeof(topic.fuel_consumption_rate) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.fuel_consumption_rate, sizeof(topic.fuel_consumption_rate));
	buf.iterator += sizeof(topic.fuel_consumption_rate);
	buf.offset += sizeof(topic.fuel_consumption_rate);
	static_assert(sizeof(topic.percent_remaining) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.percent_remaining, sizeof(topic.percent_remaining));
	buf.iterator += sizeof(topic.percent_remaining);
	buf.offset += sizeof(topic.percent_remaining);
	buf.iterator += 3; // padding
	buf.offset += 3; // padding
	static_assert(sizeof(topic.remaining_fuel) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.remaining_fuel, sizeof(topic.remaining_fuel));
	buf.iterator += sizeof(topic.remaining_fuel);
	buf.offset += sizeof(topic.remaining_fuel);
	static_assert(sizeof(topic.fuel_tank_id) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.fuel_tank_id, sizeof(topic.fuel_tank_id));
	buf.iterator += sizeof(topic.fuel_tank_id);
	buf.offset += sizeof(topic.fuel_tank_id);
	buf.iterator += 3; // padding
	buf.offset += 3; // padding
	static_assert(sizeof(topic.fuel_type) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.fuel_type, sizeof(topic.fuel_type));
	buf.iterator += sizeof(topic.fuel_type);
	buf.offset += sizeof(topic.fuel_type);
	static_assert(sizeof(topic.temperature) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.temperature, sizeof(topic.temperature));
	buf.iterator += sizeof(topic.temperature);
	buf.offset += sizeof(topic.temperature);
	return true;
}

static inline bool ucdr_deserialize_fuel_tank_status(ucdrBuffer& buf, fuel_tank_status_s& topic, int64_t time_offset = 0)
{
	static_assert(sizeof(topic.timestamp) == 8, "size mismatch");
	memcpy(&topic.timestamp, buf.iterator, sizeof(topic.timestamp));
	if (topic.timestamp == 0) topic.timestamp = hrt_absolute_time();
	else topic.timestamp = math::min(topic.timestamp - time_offset, hrt_absolute_time());
	buf.iterator += sizeof(topic.timestamp);
	buf.offset += sizeof(topic.timestamp);
	static_assert(sizeof(topic.maximum_fuel_capacity) == 4, "size mismatch");
	memcpy(&topic.maximum_fuel_capacity, buf.iterator, sizeof(topic.maximum_fuel_capacity));
	buf.iterator += sizeof(topic.maximum_fuel_capacity);
	buf.offset += sizeof(topic.maximum_fuel_capacity);
	static_assert(sizeof(topic.consumed_fuel) == 4, "size mismatch");
	memcpy(&topic.consumed_fuel, buf.iterator, sizeof(topic.consumed_fuel));
	buf.iterator += sizeof(topic.consumed_fuel);
	buf.offset += sizeof(topic.consumed_fuel);
	static_assert(sizeof(topic.fuel_consumption_rate) == 4, "size mismatch");
	memcpy(&topic.fuel_consumption_rate, buf.iterator, sizeof(topic.fuel_consumption_rate));
	buf.iterator += sizeof(topic.fuel_consumption_rate);
	buf.offset += sizeof(topic.fuel_consumption_rate);
	static_assert(sizeof(topic.percent_remaining) == 1, "size mismatch");
	memcpy(&topic.percent_remaining, buf.iterator, sizeof(topic.percent_remaining));
	buf.iterator += sizeof(topic.percent_remaining);
	buf.offset += sizeof(topic.percent_remaining);
	buf.iterator += 3; // padding
	buf.offset += 3; // padding
	static_assert(sizeof(topic.remaining_fuel) == 4, "size mismatch");
	memcpy(&topic.remaining_fuel, buf.iterator, sizeof(topic.remaining_fuel));
	buf.iterator += sizeof(topic.remaining_fuel);
	buf.offset += sizeof(topic.remaining_fuel);
	static_assert(sizeof(topic.fuel_tank_id) == 1, "size mismatch");
	memcpy(&topic.fuel_tank_id, buf.iterator, sizeof(topic.fuel_tank_id));
	buf.iterator += sizeof(topic.fuel_tank_id);
	buf.offset += sizeof(topic.fuel_tank_id);
	buf.iterator += 3; // padding
	buf.offset += 3; // padding
	static_assert(sizeof(topic.fuel_type) == 4, "size mismatch");
	memcpy(&topic.fuel_type, buf.iterator, sizeof(topic.fuel_type));
	buf.iterator += sizeof(topic.fuel_type);
	buf.offset += sizeof(topic.fuel_type);
	static_assert(sizeof(topic.temperature) == 4, "size mismatch");
	memcpy(&topic.temperature, buf.iterator, sizeof(topic.temperature));
	buf.iterator += sizeof(topic.temperature);
	buf.offset += sizeof(topic.temperature);
	return true;
}
