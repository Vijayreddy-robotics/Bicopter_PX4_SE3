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
#include <uORB/topics/open_drone_id_system.h>


static inline constexpr int ucdr_topic_size_open_drone_id_system()
{
	return 60;
}

static inline bool ucdr_serialize_open_drone_id_system(const void* data, ucdrBuffer& buf, int64_t time_offset = 0)
{
	const open_drone_id_system_s& topic = *static_cast<const open_drone_id_system_s*>(data);
	static_assert(sizeof(topic.timestamp) == 8, "size mismatch");
	const uint64_t timestamp_adjusted = topic.timestamp + time_offset;
	memcpy(buf.iterator, &timestamp_adjusted, sizeof(topic.timestamp));
	buf.iterator += sizeof(topic.timestamp);
	buf.offset += sizeof(topic.timestamp);
	static_assert(sizeof(topic.id_or_mac) == 20, "size mismatch");
	memcpy(buf.iterator, &topic.id_or_mac, sizeof(topic.id_or_mac));
	buf.iterator += sizeof(topic.id_or_mac);
	buf.offset += sizeof(topic.id_or_mac);
	static_assert(sizeof(topic.operator_location_type) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.operator_location_type, sizeof(topic.operator_location_type));
	buf.iterator += sizeof(topic.operator_location_type);
	buf.offset += sizeof(topic.operator_location_type);
	static_assert(sizeof(topic.classification_type) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.classification_type, sizeof(topic.classification_type));
	buf.iterator += sizeof(topic.classification_type);
	buf.offset += sizeof(topic.classification_type);
	buf.iterator += 2; // padding
	buf.offset += 2; // padding
	static_assert(sizeof(topic.operator_latitude) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.operator_latitude, sizeof(topic.operator_latitude));
	buf.iterator += sizeof(topic.operator_latitude);
	buf.offset += sizeof(topic.operator_latitude);
	static_assert(sizeof(topic.operator_longitude) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.operator_longitude, sizeof(topic.operator_longitude));
	buf.iterator += sizeof(topic.operator_longitude);
	buf.offset += sizeof(topic.operator_longitude);
	static_assert(sizeof(topic.area_count) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.area_count, sizeof(topic.area_count));
	buf.iterator += sizeof(topic.area_count);
	buf.offset += sizeof(topic.area_count);
	static_assert(sizeof(topic.area_radius) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.area_radius, sizeof(topic.area_radius));
	buf.iterator += sizeof(topic.area_radius);
	buf.offset += sizeof(topic.area_radius);
	static_assert(sizeof(topic.area_ceiling) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.area_ceiling, sizeof(topic.area_ceiling));
	buf.iterator += sizeof(topic.area_ceiling);
	buf.offset += sizeof(topic.area_ceiling);
	static_assert(sizeof(topic.area_floor) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.area_floor, sizeof(topic.area_floor));
	buf.iterator += sizeof(topic.area_floor);
	buf.offset += sizeof(topic.area_floor);
	static_assert(sizeof(topic.category_eu) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.category_eu, sizeof(topic.category_eu));
	buf.iterator += sizeof(topic.category_eu);
	buf.offset += sizeof(topic.category_eu);
	static_assert(sizeof(topic.class_eu) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.class_eu, sizeof(topic.class_eu));
	buf.iterator += sizeof(topic.class_eu);
	buf.offset += sizeof(topic.class_eu);
	buf.iterator += 2; // padding
	buf.offset += 2; // padding
	static_assert(sizeof(topic.operator_altitude_geo) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.operator_altitude_geo, sizeof(topic.operator_altitude_geo));
	buf.iterator += sizeof(topic.operator_altitude_geo);
	buf.offset += sizeof(topic.operator_altitude_geo);
	return true;
}

static inline bool ucdr_deserialize_open_drone_id_system(ucdrBuffer& buf, open_drone_id_system_s& topic, int64_t time_offset = 0)
{
	static_assert(sizeof(topic.timestamp) == 8, "size mismatch");
	memcpy(&topic.timestamp, buf.iterator, sizeof(topic.timestamp));
	if (topic.timestamp == 0) topic.timestamp = hrt_absolute_time();
	else topic.timestamp = math::min(topic.timestamp - time_offset, hrt_absolute_time());
	buf.iterator += sizeof(topic.timestamp);
	buf.offset += sizeof(topic.timestamp);
	static_assert(sizeof(topic.id_or_mac) == 20, "size mismatch");
	memcpy(&topic.id_or_mac, buf.iterator, sizeof(topic.id_or_mac));
	buf.iterator += sizeof(topic.id_or_mac);
	buf.offset += sizeof(topic.id_or_mac);
	static_assert(sizeof(topic.operator_location_type) == 1, "size mismatch");
	memcpy(&topic.operator_location_type, buf.iterator, sizeof(topic.operator_location_type));
	buf.iterator += sizeof(topic.operator_location_type);
	buf.offset += sizeof(topic.operator_location_type);
	static_assert(sizeof(topic.classification_type) == 1, "size mismatch");
	memcpy(&topic.classification_type, buf.iterator, sizeof(topic.classification_type));
	buf.iterator += sizeof(topic.classification_type);
	buf.offset += sizeof(topic.classification_type);
	buf.iterator += 2; // padding
	buf.offset += 2; // padding
	static_assert(sizeof(topic.operator_latitude) == 4, "size mismatch");
	memcpy(&topic.operator_latitude, buf.iterator, sizeof(topic.operator_latitude));
	buf.iterator += sizeof(topic.operator_latitude);
	buf.offset += sizeof(topic.operator_latitude);
	static_assert(sizeof(topic.operator_longitude) == 4, "size mismatch");
	memcpy(&topic.operator_longitude, buf.iterator, sizeof(topic.operator_longitude));
	buf.iterator += sizeof(topic.operator_longitude);
	buf.offset += sizeof(topic.operator_longitude);
	static_assert(sizeof(topic.area_count) == 2, "size mismatch");
	memcpy(&topic.area_count, buf.iterator, sizeof(topic.area_count));
	buf.iterator += sizeof(topic.area_count);
	buf.offset += sizeof(topic.area_count);
	static_assert(sizeof(topic.area_radius) == 2, "size mismatch");
	memcpy(&topic.area_radius, buf.iterator, sizeof(topic.area_radius));
	buf.iterator += sizeof(topic.area_radius);
	buf.offset += sizeof(topic.area_radius);
	static_assert(sizeof(topic.area_ceiling) == 4, "size mismatch");
	memcpy(&topic.area_ceiling, buf.iterator, sizeof(topic.area_ceiling));
	buf.iterator += sizeof(topic.area_ceiling);
	buf.offset += sizeof(topic.area_ceiling);
	static_assert(sizeof(topic.area_floor) == 4, "size mismatch");
	memcpy(&topic.area_floor, buf.iterator, sizeof(topic.area_floor));
	buf.iterator += sizeof(topic.area_floor);
	buf.offset += sizeof(topic.area_floor);
	static_assert(sizeof(topic.category_eu) == 1, "size mismatch");
	memcpy(&topic.category_eu, buf.iterator, sizeof(topic.category_eu));
	buf.iterator += sizeof(topic.category_eu);
	buf.offset += sizeof(topic.category_eu);
	static_assert(sizeof(topic.class_eu) == 1, "size mismatch");
	memcpy(&topic.class_eu, buf.iterator, sizeof(topic.class_eu));
	buf.iterator += sizeof(topic.class_eu);
	buf.offset += sizeof(topic.class_eu);
	buf.iterator += 2; // padding
	buf.offset += 2; // padding
	static_assert(sizeof(topic.operator_altitude_geo) == 4, "size mismatch");
	memcpy(&topic.operator_altitude_geo, buf.iterator, sizeof(topic.operator_altitude_geo));
	buf.iterator += sizeof(topic.operator_altitude_geo);
	buf.offset += sizeof(topic.operator_altitude_geo);
	return true;
}
