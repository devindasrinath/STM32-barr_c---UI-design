/*
* File: crdcs_pq_counter.h
* Author: Devinda Srinath
* Description: Count of button pressing feature for UI design
* Created on February 18, 2022, 10:20 PM
 */

#ifndef COUNTER_CRD_CS_COUNTER_H_
#define COUNTER_CRD_CS_COUNTER_H_
#include "stm32f1xx_hal.h"
#define HAL_GPIO_MODULE_ENABLED
#include "../OLED Display/crdcs_pq_ssd1306.h"
#include "../OLED Display/crdcs_pq_fonts.h"
#include <crdcs_pq_keypad.h>
#include "../Main menu/crdcs_pq_main_menu.h"

uint16_t button_presses_count;
static uint8_t * key_state_counter;
static button_value_map_t * button_values;

void counter_init (const uint8_t *key_states_arr,
	const button_value_map_t *button_values_ext);
void counter ();

#endif /* COUNTER_CRD_CS_COUNTER_H_ */
