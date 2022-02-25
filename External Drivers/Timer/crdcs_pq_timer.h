/*
* File: crdcs_pq_timer.h
* Author: Devinda Srinath
* Description: Stopwatch timer feature for UI design
* Created on February 18, 2022, 10:20 PM
*/

#ifndef TIMER_CRDCS_PQ_TIMER_H_
#define TIMER_CRDCS_PQ_TIMER_H_
#include "stm32f1xx_hal.h"
#define HAL_GPIO_MODULE_ENABLED
#include "../OLED Display/crdcs_pq_ssd1306.h"
#include "../OLED Display/crdcs_pq_fonts.h"
#include <crdcs_pq_keypad.h>
#include "../Main menu/crdcs_pq_main_menu.h"

volatile uint32_t timer_ticks;
uint8_t timer_state;
uint8_t timer_time;
static uint8_t * key_state_timer;
static button_value_map_t * button_values;

void timer_init (const uint8_t *key_states_arr,
	const button_value_map_t *button_values_ext);
void timer ();
void timer_ticks_increment ();

#endif /* TIMER_CRDCS_PQ_TIMER_H_ */
