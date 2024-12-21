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
#include <uORB/topics/battery_status.h>


static inline constexpr int ucdr_topic_size_battery_status()
{
	return 180;
}

static inline bool ucdr_serialize_battery_status(const void* data, ucdrBuffer& buf, int64_t time_offset = 0)
{
	const battery_status_s& topic = *static_cast<const battery_status_s*>(data);
	static_assert(sizeof(topic.timestamp) == 8, "size mismatch");
	const uint64_t timestamp_adjusted = topic.timestamp + time_offset;
	memcpy(buf.iterator, &timestamp_adjusted, sizeof(topic.timestamp));
	buf.iterator += sizeof(topic.timestamp);
	buf.offset += sizeof(topic.timestamp);
	static_assert(sizeof(topic.connected) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.connected, sizeof(topic.connected));
	buf.iterator += sizeof(topic.connected);
	buf.offset += sizeof(topic.connected);
	buf.iterator += 3; // padding
	buf.offset += 3; // padding
	static_assert(sizeof(topic.voltage_v) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.voltage_v, sizeof(topic.voltage_v));
	buf.iterator += sizeof(topic.voltage_v);
	buf.offset += sizeof(topic.voltage_v);
	static_assert(sizeof(topic.current_a) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.current_a, sizeof(topic.current_a));
	buf.iterator += sizeof(topic.current_a);
	buf.offset += sizeof(topic.current_a);
	static_assert(sizeof(topic.current_average_a) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.current_average_a, sizeof(topic.current_average_a));
	buf.iterator += sizeof(topic.current_average_a);
	buf.offset += sizeof(topic.current_average_a);
	static_assert(sizeof(topic.discharged_mah) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.discharged_mah, sizeof(topic.discharged_mah));
	buf.iterator += sizeof(topic.discharged_mah);
	buf.offset += sizeof(topic.discharged_mah);
	static_assert(sizeof(topic.remaining) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.remaining, sizeof(topic.remaining));
	buf.iterator += sizeof(topic.remaining);
	buf.offset += sizeof(topic.remaining);
	static_assert(sizeof(topic.scale) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.scale, sizeof(topic.scale));
	buf.iterator += sizeof(topic.scale);
	buf.offset += sizeof(topic.scale);
	static_assert(sizeof(topic.time_remaining_s) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.time_remaining_s, sizeof(topic.time_remaining_s));
	buf.iterator += sizeof(topic.time_remaining_s);
	buf.offset += sizeof(topic.time_remaining_s);
	static_assert(sizeof(topic.temperature) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.temperature, sizeof(topic.temperature));
	buf.iterator += sizeof(topic.temperature);
	buf.offset += sizeof(topic.temperature);
	static_assert(sizeof(topic.cell_count) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.cell_count, sizeof(topic.cell_count));
	buf.iterator += sizeof(topic.cell_count);
	buf.offset += sizeof(topic.cell_count);
	static_assert(sizeof(topic.source) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.source, sizeof(topic.source));
	buf.iterator += sizeof(topic.source);
	buf.offset += sizeof(topic.source);
	static_assert(sizeof(topic.priority) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.priority, sizeof(topic.priority));
	buf.iterator += sizeof(topic.priority);
	buf.offset += sizeof(topic.priority);
	buf.iterator += 1; // padding
	buf.offset += 1; // padding
	static_assert(sizeof(topic.capacity) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.capacity, sizeof(topic.capacity));
	buf.iterator += sizeof(topic.capacity);
	buf.offset += sizeof(topic.capacity);
	static_assert(sizeof(topic.cycle_count) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.cycle_count, sizeof(topic.cycle_count));
	buf.iterator += sizeof(topic.cycle_count);
	buf.offset += sizeof(topic.cycle_count);
	static_assert(sizeof(topic.average_time_to_empty) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.average_time_to_empty, sizeof(topic.average_time_to_empty));
	buf.iterator += sizeof(topic.average_time_to_empty);
	buf.offset += sizeof(topic.average_time_to_empty);
	static_assert(sizeof(topic.serial_number) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.serial_number, sizeof(topic.serial_number));
	buf.iterator += sizeof(topic.serial_number);
	buf.offset += sizeof(topic.serial_number);
	static_assert(sizeof(topic.manufacture_date) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.manufacture_date, sizeof(topic.manufacture_date));
	buf.iterator += sizeof(topic.manufacture_date);
	buf.offset += sizeof(topic.manufacture_date);
	static_assert(sizeof(topic.state_of_health) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.state_of_health, sizeof(topic.state_of_health));
	buf.iterator += sizeof(topic.state_of_health);
	buf.offset += sizeof(topic.state_of_health);
	static_assert(sizeof(topic.max_error) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.max_error, sizeof(topic.max_error));
	buf.iterator += sizeof(topic.max_error);
	buf.offset += sizeof(topic.max_error);
	static_assert(sizeof(topic.id) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.id, sizeof(topic.id));
	buf.iterator += sizeof(topic.id);
	buf.offset += sizeof(topic.id);
	buf.iterator += 1; // padding
	buf.offset += 1; // padding
	static_assert(sizeof(topic.interface_error) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.interface_error, sizeof(topic.interface_error));
	buf.iterator += sizeof(topic.interface_error);
	buf.offset += sizeof(topic.interface_error);
	buf.iterator += 2; // padding
	buf.offset += 2; // padding
	static_assert(sizeof(topic.voltage_cell_v) == 56, "size mismatch");
	memcpy(buf.iterator, &topic.voltage_cell_v, sizeof(topic.voltage_cell_v));
	buf.iterator += sizeof(topic.voltage_cell_v);
	buf.offset += sizeof(topic.voltage_cell_v);
	static_assert(sizeof(topic.max_cell_voltage_delta) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.max_cell_voltage_delta, sizeof(topic.max_cell_voltage_delta));
	buf.iterator += sizeof(topic.max_cell_voltage_delta);
	buf.offset += sizeof(topic.max_cell_voltage_delta);
	static_assert(sizeof(topic.is_powering_off) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.is_powering_off, sizeof(topic.is_powering_off));
	buf.iterator += sizeof(topic.is_powering_off);
	buf.offset += sizeof(topic.is_powering_off);
	static_assert(sizeof(topic.is_required) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.is_required, sizeof(topic.is_required));
	buf.iterator += sizeof(topic.is_required);
	buf.offset += sizeof(topic.is_required);
	static_assert(sizeof(topic.faults) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.faults, sizeof(topic.faults));
	buf.iterator += sizeof(topic.faults);
	buf.offset += sizeof(topic.faults);
	static_assert(sizeof(topic.warning) == 1, "size mismatch");
	memcpy(buf.iterator, &topic.warning, sizeof(topic.warning));
	buf.iterator += sizeof(topic.warning);
	buf.offset += sizeof(topic.warning);
	buf.iterator += 3; // padding
	buf.offset += 3; // padding
	static_assert(sizeof(topic.full_charge_capacity_wh) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.full_charge_capacity_wh, sizeof(topic.full_charge_capacity_wh));
	buf.iterator += sizeof(topic.full_charge_capacity_wh);
	buf.offset += sizeof(topic.full_charge_capacity_wh);
	static_assert(sizeof(topic.remaining_capacity_wh) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.remaining_capacity_wh, sizeof(topic.remaining_capacity_wh));
	buf.iterator += sizeof(topic.remaining_capacity_wh);
	buf.offset += sizeof(topic.remaining_capacity_wh);
	static_assert(sizeof(topic.over_discharge_count) == 2, "size mismatch");
	memcpy(buf.iterator, &topic.over_discharge_count, sizeof(topic.over_discharge_count));
	buf.iterator += sizeof(topic.over_discharge_count);
	buf.offset += sizeof(topic.over_discharge_count);
	buf.iterator += 2; // padding
	buf.offset += 2; // padding
	static_assert(sizeof(topic.nominal_voltage) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.nominal_voltage, sizeof(topic.nominal_voltage));
	buf.iterator += sizeof(topic.nominal_voltage);
	buf.offset += sizeof(topic.nominal_voltage);
	static_assert(sizeof(topic.internal_resistance_estimate) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.internal_resistance_estimate, sizeof(topic.internal_resistance_estimate));
	buf.iterator += sizeof(topic.internal_resistance_estimate);
	buf.offset += sizeof(topic.internal_resistance_estimate);
	static_assert(sizeof(topic.ocv_estimate) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.ocv_estimate, sizeof(topic.ocv_estimate));
	buf.iterator += sizeof(topic.ocv_estimate);
	buf.offset += sizeof(topic.ocv_estimate);
	static_assert(sizeof(topic.ocv_estimate_filtered) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.ocv_estimate_filtered, sizeof(topic.ocv_estimate_filtered));
	buf.iterator += sizeof(topic.ocv_estimate_filtered);
	buf.offset += sizeof(topic.ocv_estimate_filtered);
	static_assert(sizeof(topic.volt_based_soc_estimate) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.volt_based_soc_estimate, sizeof(topic.volt_based_soc_estimate));
	buf.iterator += sizeof(topic.volt_based_soc_estimate);
	buf.offset += sizeof(topic.volt_based_soc_estimate);
	static_assert(sizeof(topic.voltage_prediction) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.voltage_prediction, sizeof(topic.voltage_prediction));
	buf.iterator += sizeof(topic.voltage_prediction);
	buf.offset += sizeof(topic.voltage_prediction);
	static_assert(sizeof(topic.prediction_error) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.prediction_error, sizeof(topic.prediction_error));
	buf.iterator += sizeof(topic.prediction_error);
	buf.offset += sizeof(topic.prediction_error);
	static_assert(sizeof(topic.estimation_covariance_norm) == 4, "size mismatch");
	memcpy(buf.iterator, &topic.estimation_covariance_norm, sizeof(topic.estimation_covariance_norm));
	buf.iterator += sizeof(topic.estimation_covariance_norm);
	buf.offset += sizeof(topic.estimation_covariance_norm);
	return true;
}

static inline bool ucdr_deserialize_battery_status(ucdrBuffer& buf, battery_status_s& topic, int64_t time_offset = 0)
{
	static_assert(sizeof(topic.timestamp) == 8, "size mismatch");
	memcpy(&topic.timestamp, buf.iterator, sizeof(topic.timestamp));
	if (topic.timestamp == 0) topic.timestamp = hrt_absolute_time();
	else topic.timestamp = math::min(topic.timestamp - time_offset, hrt_absolute_time());
	buf.iterator += sizeof(topic.timestamp);
	buf.offset += sizeof(topic.timestamp);
	static_assert(sizeof(topic.connected) == 1, "size mismatch");
	memcpy(&topic.connected, buf.iterator, sizeof(topic.connected));
	buf.iterator += sizeof(topic.connected);
	buf.offset += sizeof(topic.connected);
	buf.iterator += 3; // padding
	buf.offset += 3; // padding
	static_assert(sizeof(topic.voltage_v) == 4, "size mismatch");
	memcpy(&topic.voltage_v, buf.iterator, sizeof(topic.voltage_v));
	buf.iterator += sizeof(topic.voltage_v);
	buf.offset += sizeof(topic.voltage_v);
	static_assert(sizeof(topic.current_a) == 4, "size mismatch");
	memcpy(&topic.current_a, buf.iterator, sizeof(topic.current_a));
	buf.iterator += sizeof(topic.current_a);
	buf.offset += sizeof(topic.current_a);
	static_assert(sizeof(topic.current_average_a) == 4, "size mismatch");
	memcpy(&topic.current_average_a, buf.iterator, sizeof(topic.current_average_a));
	buf.iterator += sizeof(topic.current_average_a);
	buf.offset += sizeof(topic.current_average_a);
	static_assert(sizeof(topic.discharged_mah) == 4, "size mismatch");
	memcpy(&topic.discharged_mah, buf.iterator, sizeof(topic.discharged_mah));
	buf.iterator += sizeof(topic.discharged_mah);
	buf.offset += sizeof(topic.discharged_mah);
	static_assert(sizeof(topic.remaining) == 4, "size mismatch");
	memcpy(&topic.remaining, buf.iterator, sizeof(topic.remaining));
	buf.iterator += sizeof(topic.remaining);
	buf.offset += sizeof(topic.remaining);
	static_assert(sizeof(topic.scale) == 4, "size mismatch");
	memcpy(&topic.scale, buf.iterator, sizeof(topic.scale));
	buf.iterator += sizeof(topic.scale);
	buf.offset += sizeof(topic.scale);
	static_assert(sizeof(topic.time_remaining_s) == 4, "size mismatch");
	memcpy(&topic.time_remaining_s, buf.iterator, sizeof(topic.time_remaining_s));
	buf.iterator += sizeof(topic.time_remaining_s);
	buf.offset += sizeof(topic.time_remaining_s);
	static_assert(sizeof(topic.temperature) == 4, "size mismatch");
	memcpy(&topic.temperature, buf.iterator, sizeof(topic.temperature));
	buf.iterator += sizeof(topic.temperature);
	buf.offset += sizeof(topic.temperature);
	static_assert(sizeof(topic.cell_count) == 1, "size mismatch");
	memcpy(&topic.cell_count, buf.iterator, sizeof(topic.cell_count));
	buf.iterator += sizeof(topic.cell_count);
	buf.offset += sizeof(topic.cell_count);
	static_assert(sizeof(topic.source) == 1, "size mismatch");
	memcpy(&topic.source, buf.iterator, sizeof(topic.source));
	buf.iterator += sizeof(topic.source);
	buf.offset += sizeof(topic.source);
	static_assert(sizeof(topic.priority) == 1, "size mismatch");
	memcpy(&topic.priority, buf.iterator, sizeof(topic.priority));
	buf.iterator += sizeof(topic.priority);
	buf.offset += sizeof(topic.priority);
	buf.iterator += 1; // padding
	buf.offset += 1; // padding
	static_assert(sizeof(topic.capacity) == 2, "size mismatch");
	memcpy(&topic.capacity, buf.iterator, sizeof(topic.capacity));
	buf.iterator += sizeof(topic.capacity);
	buf.offset += sizeof(topic.capacity);
	static_assert(sizeof(topic.cycle_count) == 2, "size mismatch");
	memcpy(&topic.cycle_count, buf.iterator, sizeof(topic.cycle_count));
	buf.iterator += sizeof(topic.cycle_count);
	buf.offset += sizeof(topic.cycle_count);
	static_assert(sizeof(topic.average_time_to_empty) == 2, "size mismatch");
	memcpy(&topic.average_time_to_empty, buf.iterator, sizeof(topic.average_time_to_empty));
	buf.iterator += sizeof(topic.average_time_to_empty);
	buf.offset += sizeof(topic.average_time_to_empty);
	static_assert(sizeof(topic.serial_number) == 2, "size mismatch");
	memcpy(&topic.serial_number, buf.iterator, sizeof(topic.serial_number));
	buf.iterator += sizeof(topic.serial_number);
	buf.offset += sizeof(topic.serial_number);
	static_assert(sizeof(topic.manufacture_date) == 2, "size mismatch");
	memcpy(&topic.manufacture_date, buf.iterator, sizeof(topic.manufacture_date));
	buf.iterator += sizeof(topic.manufacture_date);
	buf.offset += sizeof(topic.manufacture_date);
	static_assert(sizeof(topic.state_of_health) == 2, "size mismatch");
	memcpy(&topic.state_of_health, buf.iterator, sizeof(topic.state_of_health));
	buf.iterator += sizeof(topic.state_of_health);
	buf.offset += sizeof(topic.state_of_health);
	static_assert(sizeof(topic.max_error) == 2, "size mismatch");
	memcpy(&topic.max_error, buf.iterator, sizeof(topic.max_error));
	buf.iterator += sizeof(topic.max_error);
	buf.offset += sizeof(topic.max_error);
	static_assert(sizeof(topic.id) == 1, "size mismatch");
	memcpy(&topic.id, buf.iterator, sizeof(topic.id));
	buf.iterator += sizeof(topic.id);
	buf.offset += sizeof(topic.id);
	buf.iterator += 1; // padding
	buf.offset += 1; // padding
	static_assert(sizeof(topic.interface_error) == 2, "size mismatch");
	memcpy(&topic.interface_error, buf.iterator, sizeof(topic.interface_error));
	buf.iterator += sizeof(topic.interface_error);
	buf.offset += sizeof(topic.interface_error);
	buf.iterator += 2; // padding
	buf.offset += 2; // padding
	static_assert(sizeof(topic.voltage_cell_v) == 56, "size mismatch");
	memcpy(&topic.voltage_cell_v, buf.iterator, sizeof(topic.voltage_cell_v));
	buf.iterator += sizeof(topic.voltage_cell_v);
	buf.offset += sizeof(topic.voltage_cell_v);
	static_assert(sizeof(topic.max_cell_voltage_delta) == 4, "size mismatch");
	memcpy(&topic.max_cell_voltage_delta, buf.iterator, sizeof(topic.max_cell_voltage_delta));
	buf.iterator += sizeof(topic.max_cell_voltage_delta);
	buf.offset += sizeof(topic.max_cell_voltage_delta);
	static_assert(sizeof(topic.is_powering_off) == 1, "size mismatch");
	memcpy(&topic.is_powering_off, buf.iterator, sizeof(topic.is_powering_off));
	buf.iterator += sizeof(topic.is_powering_off);
	buf.offset += sizeof(topic.is_powering_off);
	static_assert(sizeof(topic.is_required) == 1, "size mismatch");
	memcpy(&topic.is_required, buf.iterator, sizeof(topic.is_required));
	buf.iterator += sizeof(topic.is_required);
	buf.offset += sizeof(topic.is_required);
	static_assert(sizeof(topic.faults) == 2, "size mismatch");
	memcpy(&topic.faults, buf.iterator, sizeof(topic.faults));
	buf.iterator += sizeof(topic.faults);
	buf.offset += sizeof(topic.faults);
	static_assert(sizeof(topic.warning) == 1, "size mismatch");
	memcpy(&topic.warning, buf.iterator, sizeof(topic.warning));
	buf.iterator += sizeof(topic.warning);
	buf.offset += sizeof(topic.warning);
	buf.iterator += 3; // padding
	buf.offset += 3; // padding
	static_assert(sizeof(topic.full_charge_capacity_wh) == 4, "size mismatch");
	memcpy(&topic.full_charge_capacity_wh, buf.iterator, sizeof(topic.full_charge_capacity_wh));
	buf.iterator += sizeof(topic.full_charge_capacity_wh);
	buf.offset += sizeof(topic.full_charge_capacity_wh);
	static_assert(sizeof(topic.remaining_capacity_wh) == 4, "size mismatch");
	memcpy(&topic.remaining_capacity_wh, buf.iterator, sizeof(topic.remaining_capacity_wh));
	buf.iterator += sizeof(topic.remaining_capacity_wh);
	buf.offset += sizeof(topic.remaining_capacity_wh);
	static_assert(sizeof(topic.over_discharge_count) == 2, "size mismatch");
	memcpy(&topic.over_discharge_count, buf.iterator, sizeof(topic.over_discharge_count));
	buf.iterator += sizeof(topic.over_discharge_count);
	buf.offset += sizeof(topic.over_discharge_count);
	buf.iterator += 2; // padding
	buf.offset += 2; // padding
	static_assert(sizeof(topic.nominal_voltage) == 4, "size mismatch");
	memcpy(&topic.nominal_voltage, buf.iterator, sizeof(topic.nominal_voltage));
	buf.iterator += sizeof(topic.nominal_voltage);
	buf.offset += sizeof(topic.nominal_voltage);
	static_assert(sizeof(topic.internal_resistance_estimate) == 4, "size mismatch");
	memcpy(&topic.internal_resistance_estimate, buf.iterator, sizeof(topic.internal_resistance_estimate));
	buf.iterator += sizeof(topic.internal_resistance_estimate);
	buf.offset += sizeof(topic.internal_resistance_estimate);
	static_assert(sizeof(topic.ocv_estimate) == 4, "size mismatch");
	memcpy(&topic.ocv_estimate, buf.iterator, sizeof(topic.ocv_estimate));
	buf.iterator += sizeof(topic.ocv_estimate);
	buf.offset += sizeof(topic.ocv_estimate);
	static_assert(sizeof(topic.ocv_estimate_filtered) == 4, "size mismatch");
	memcpy(&topic.ocv_estimate_filtered, buf.iterator, sizeof(topic.ocv_estimate_filtered));
	buf.iterator += sizeof(topic.ocv_estimate_filtered);
	buf.offset += sizeof(topic.ocv_estimate_filtered);
	static_assert(sizeof(topic.volt_based_soc_estimate) == 4, "size mismatch");
	memcpy(&topic.volt_based_soc_estimate, buf.iterator, sizeof(topic.volt_based_soc_estimate));
	buf.iterator += sizeof(topic.volt_based_soc_estimate);
	buf.offset += sizeof(topic.volt_based_soc_estimate);
	static_assert(sizeof(topic.voltage_prediction) == 4, "size mismatch");
	memcpy(&topic.voltage_prediction, buf.iterator, sizeof(topic.voltage_prediction));
	buf.iterator += sizeof(topic.voltage_prediction);
	buf.offset += sizeof(topic.voltage_prediction);
	static_assert(sizeof(topic.prediction_error) == 4, "size mismatch");
	memcpy(&topic.prediction_error, buf.iterator, sizeof(topic.prediction_error));
	buf.iterator += sizeof(topic.prediction_error);
	buf.offset += sizeof(topic.prediction_error);
	static_assert(sizeof(topic.estimation_covariance_norm) == 4, "size mismatch");
	memcpy(&topic.estimation_covariance_norm, buf.iterator, sizeof(topic.estimation_covariance_norm));
	buf.iterator += sizeof(topic.estimation_covariance_norm);
	buf.offset += sizeof(topic.estimation_covariance_norm);
	return true;
}
