/*
* File: crdcs_pq_main_menu.h
* Author: Devinda Srinath
* Description: Main menu design for UI design
* Created on February 18, 2022, 10:20 PM
 */

#ifndef MAIN_MENU_CRDCS_PQ_MAIN_MENU_H_
#define MAIN_MENU_CRDCS_PQ_MAIN_MENU_H_

#define HAL_GPIO_MODULE_ENABLED
#include "stm32f1xx_hal.h"
#include "../OLED Display/crdcs_pq_ssd1306.h"
#include "../OLED Display/crdcs_pq_fonts.h"
#include <crdcs_pq_keypad.h>

#define NO_OF_MODES 3;

// Add new mode names if you want add new options.
typedef enum
{

	MAIN_MENU, ADDER, COUNTER, TIMER

} ui_modes_t;

ui_modes_t current_mode;
static uint8_t * key_state;
static button_value_map_t * button_values;

void menu_init (const uint8_t *key_states_arr,
	const button_value_map_t *button_values_ext);
void menu_select ();

#endif /* MAIN_MENU_CRDCS_PQ_MAIN_MENU_H_ */

