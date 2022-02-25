/*
* File: crdcs_pq_main_menu.c
* Author: Devinda Srinath
* Description: Main menu design for UI design
* Created on February 18, 2022, 10:20 PM
 */

#include "crdcs_pq_main_menu.h"

/*intialize the main menu by assign the keypad button values and pressing values*/
void menu_init (const uint8_t *key_states_arr,
	const button_value_map_t *button_values_ext)
{
	key_state = key_states_arr;
	button_values = button_values_ext;
}

/* Deal with user to getting arguments for select an option in menu.*/
void menu_select ()
{
	static uint8_t stage = 1;

	if (stage == 1)
	{
		/* Main Menu (display once).*/
		SSD1306_Clear();
		print_inline(10, 10, "A. Adder", &Font_7x10, 1);
		print_inline(10, 30, "B. Counter", &Font_7x10, 1);
		print_inline(10, 50, "C. Stop watch", &Font_7x10, 1);
		SSD1306_UpdateScreen(); // update screen
		stage = 2;
	}
	else if (stage == 2)
	{
		/* Checking menu option selction.*/
		if (key_state[button_values->A] == KEY_PRESSED)
		{
			keypad_clear();
			stage = 1;
			current_mode = ADDER;
		}
		else if (key_state[button_values->B] == KEY_PRESSED)
		{
			keypad_clear();
			stage = 1;
			current_mode = COUNTER;
		}
		else if (key_state[button_values->C] == KEY_PRESSED)
		{
			keypad_clear();
			stage = 1;
			current_mode = TIMER;
		}
	}

}
