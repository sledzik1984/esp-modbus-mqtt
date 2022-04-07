/*
 modbus_registers.h - Modbus Registers Structure
 Copyright (C) 2020 Germain Masse

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef SRC_MODBUS_REGISTERS_H_
#define SRC_MODBUS_REGISTERS_H_

#include "Arduino.h"

typedef enum {
    MODBUS_TYPE_HOLDING = 0x00,         /*!< Modbus Holding register. */
//    MODBUS_TYPE_INPUT,                  /*!< Modbus Input register. */
//    MODBUS_TYPE_COIL,                   /*!< Modbus Coils. */
//    MODBUS_TYPE_DISCRETE,               /*!< Modbus Discrete bits. */
//    MODBUS_TYPE_COUNT,
//    MODBUS_TYPE_UNKNOWN = 0xFF
} modbus_entity_t;

typedef enum {
//    REGISTER_TYPE_U8 = 0x00,                   /*!< Unsigned 8 */
    REGISTER_TYPE_U16 = 0x01,                  /*!< Unsigned 16 */
//    REGISTER_TYPE_U32 = 0x02,                  /*!< Unsigned 32 */
//    REGISTER_TYPE_FLOAT = 0x03,                /*!< Float type */
//    REGISTER_TYPE_ASCII = 0x04,                 /*!< ASCII type */
    REGISTER_TYPE_DIEMATIC_ONE_DECIMAL = 0x05,
    REGISTER_TYPE_BITFIELD = 0x06,
    REGISTER_TYPE_DEBUG = 0x07
} register_type_t;

typedef union {
    const char* bitfield[16];
} optional_param_t;

typedef struct {
    uint16_t            id;
    modbus_entity_t     modbus_entity;      /*!< Type of modbus parameter */
    register_type_t     type;               /*!< Float, U8, U16, U32, ASCII, etc. */
    const char*         name;
    optional_param_t    optional_param;
} modbus_register_t;

const modbus_register_t registers[] = {
    { 251, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DEBUG, "pulse_1_1" },
    { 252, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DEBUG, "operating_1_1" },
    { 253, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DEBUG, "pulse_1_2" },
    { 254, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DEBUG, "operating_1_2" },
    { 255, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DEBUG, "pulse_2_1" },
    { 256, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DEBUG, "operating_2_1" },
    { 257, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DEBUG, "pulse_2_2" },
    { 258, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DEBUG, "operating_2_2" },
    { 259, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DEBUG, "pulse_3_1" },
    { 260, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DEBUG, "operating_3_1" },
    { 261, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DEBUG, "pulse_3_2" },
    { 262, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DEBUG, "operating_3_2" },
    { 474, MODBUS_TYPE_HOLDING, REGISTER_TYPE_BITFIELD, "bits_primary_status", { .bitfield = {
            "io_burner_1",
            "io_burner_2",
            "io_valve_isolation_open",
            "io_valve_isolation_closed",
            "io_pump_boiler"
    } } },
    { 475, MODBUS_TYPE_HOLDING, REGISTER_TYPE_BITFIELD, "bits_secondary_status", { .bitfield = {
            "io_pump_dhw",  // Domestic Hot Water
            "io_pump_a",
            "io_valve_a_open",
            "io_valve_a_closed",
            "io_pump_b",
            "io_valve_b_open",
            "io_valve_b_closed",
            "io_pump_c",
            "io_valve_c_open",
            "io_valve_c_closed",
            "io_pump_aux_1",
            "io_pump_aux_2",
            "io_pump_aux_3"
    } } },
    { 500, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "alarm_critical" },  // red
    { 501, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "alarm_major" },  // orange
    { 502, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "alarm_minor" },  // momentary
    { 503, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DEBUG, "power_instantaneous" },  // ##.# kW
    { 504, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DEBUG, "power_average" },  // ##.# kW/h
    { 505, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DEBUG, "power_average_dhw" },  // ##.# kW/h
    { 507, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "pulse_unit" },
    { 508, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "pulse_ten" },
    { 509, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DEBUG, "operating_unit" },
    { 510, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DEBUG, "operating_ten" },
    { 601, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DIEMATIC_ONE_DECIMAL, "temperature_external" },
    { 602, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DIEMATIC_ONE_DECIMAL, "temperature_boiler" },
    { 603, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DIEMATIC_ONE_DECIMAL, "temperature_tank" },
    { 605, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DIEMATIC_ONE_DECIMAL, "temperature_circuit_b" },
    { 606, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DIEMATIC_ONE_DECIMAL, "temperature_circuit_c" },
    { 610, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DIEMATIC_ONE_DECIMAL, "pressure" },
    { 614, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DIEMATIC_ONE_DECIMAL, "temperature_ambiant_circuit_a" },
    { 615, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DIEMATIC_ONE_DECIMAL, "temperature_computed_circuit_a" },
    { 616, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DIEMATIC_ONE_DECIMAL, "temperature_ambiant_circuit_b" },
    { 617, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DIEMATIC_ONE_DECIMAL, "temperature_computed_circuit_b" },
    { 618, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DIEMATIC_ONE_DECIMAL, "temperature_ambiant_circuit_c" },
    { 619, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DIEMATIC_ONE_DECIMAL, "temperature_computed_circuit_c" },
    { 620, MODBUS_TYPE_HOLDING, REGISTER_TYPE_DIEMATIC_ONE_DECIMAL, "temperature_computed_boiler" },
    { 700, MODBUS_TYPE_HOLDING, REGISTER_TYPE_BITFIELD, "bits_base", { .bitfield = {
            "io_pump_aux",
            "io_pump_boiler_1",
            "io_burner_1_2",
            "io_burner_1_1",
            "io_pump_a_xxx",
            "io_pump_dhw_xxx",
            "io_alarm_burner_1",
            "io_diematic",
            "io_valve_isolation_1",
            "io_boiler_mod_1",
            "io_burner_6_2",
            "io_burner_6_1",
            "io_burner_5_2",
            "io_burner_5_1",
            "io_burner_4_2",
            "io_burner_4_1"
    } } },
    { 701, MODBUS_TYPE_HOLDING, REGISTER_TYPE_BITFIELD, "bits_terminal_2", { .bitfield = {
            "io_burner_2_1",
            "io_burner_2_2",
            "io_pump_boiler_2",
            "io_alarm_burner_2",
            "io_duration_2_1",
            "io_duration_2_2",
            "io_duration_1_1",
            "io_board_detected_k11",
            "io_valve_isolation_2",
            "io_boiler_mod_2",
            "io_burner_9_2",
            "io_burner_9_1",
            "io_burner_8_2",
            "io_burner_8_1",
            "io_burner_7_2",
            "io_burner_7_1"
    } } },
    
    {6000, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "voltage_l1" },
    {6002, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "current_l1" },
    {6004, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "power_active_l1" },
    {6006, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "power_reactive_l1" },
    {6008, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "power_apparent_l1" },
    {6010, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "powerfactorf_l1" },

    {6014, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "voltage_l2" },
    {6016, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "current_l2" },
    {6018, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "power_active_l2" },
    {6020, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "power_reactive_l2" },
    {6022, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "power_apparent_l2" },
    {6024, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "powerfactorf_l2" },

    {6028, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "voltage_l3" },
    {6030, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "current_l3" },
    {6032, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "power_active_l3" },
    {6034, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "power_reactive_l3" },
    {6036, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "power_apparent_l3" },
    {6038, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "powerfactorf_l3" },

    {6042, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "voltage_3phase_mean" },
    {6044, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "current_3phase_mean" },
    {6046, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "power_active_3phase" },
    {6048, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "power_reactive_3phase" },
    {6050, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "power_apparent_3phase" },
    {6052, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "powerfactor_mean" },
    {6056, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "freq" },
    {6058, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "voltage_l1-l2" },
    {6060, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "voltage_l2-l2" },
    {6062, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "voltage_l3-l1" },



    {6094, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "neutral_current" }
};

#endif  // SRC_MODBUS_REGISTERS_H_
