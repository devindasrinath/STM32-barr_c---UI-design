/*
* File: crdcs_pq_adder.h
* Author: Devinda Srinath
* Description: Adder feature for UI design
* Created on February 18, 2022, 10:20 PM
 */


#ifndef ADDER_CRDCS_PQ_ADDER_H_
#define ADDER_CRDCS_PQ_ADDER_H_

#include "stm32f1xx_hal.h"
#define HAL_GPIO_MODULE_ENABLED
#include "crdcs_pq_ssd1306.h"
#include "crdcs_pq_fonts.h"
#include "crdcs_pq_keypad.h"
#include "crdcs_pq_main_menu.h"

uint8_t num1;
uint8_t num2;
static uint8_t * key_state_adder;
static button_value_map_t * button_values;


void adder_init(const uint8_t *key_states_arr,
	const button_value_map_t *button_values_ext);
void adder();
static uint8_t request_number_ui(const uint8_t next_stage,
	const uint8_t arg_no, const uint8_t *num);
static uint8_t checking_number_keypad(const uint8_t current_stage,
	const uint8_t next_stage, const uint8_t previous_stage, uint8_t *num);

#endif /* ADDER_CRDCS_PQ_ADDER_H_ */
