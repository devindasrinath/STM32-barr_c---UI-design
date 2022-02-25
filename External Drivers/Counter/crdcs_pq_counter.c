/*
* File: crdcs_pq_counter.c
* Author: Devinda Srinath
* Description: Count of button pressing feature for UI design
* Created on February 18, 2022, 10:20 PM
 */

#include <crd_cs_counter.h>


/* Intialize the counter by assign the keypad button values and pressing values*/
void counter_init (const uint8_t *key_state_arr,
	const button_value_map_t *button_values_ext)
{
	key_state_counter = key_state_arr;
	button_values = button_values_ext;
}

/* Deal with user to getting arguments while performing the counting.*/
void counter ()
{
	static uint8_t stage = 1;
	if (stage == 1)
	{
		/* Enter to the counter mode.
		 * update screen according to no. of counts of button presses.
		 */
		SSD1306_Clear();
		char button_presses[20];
		sprintf(button_presses, "No. presses = %d", button_presses_count);
		print_inline(10, 10, button_presses, &Font_7x10, 1);
		print_inline(10, 30, "B - Reset", &Font_7x10, 1);
		print_inline(10, 50, "D - Main menu", &Font_7x10, 1);
		SSD1306_UpdateScreen();
		keypad_clear();
		stage = 2;
	}
	else if (stage == 2)
	{
		/* Reset the counter*/
		if (key_state_counter[button_values->B] == 1)
		{
			button_presses_count = 0;
			stage = 1;

		}
		/* Exit to main menu*/
		else if (key_state_counter[button_values->D] == 1)
		{
			button_presses_count = 0;
			current_mode = MAIN_MENU;
			stage = 1;
		}
		/* Increment the pressing count while button pressing(without B and D charaters)
		 * B and D are used to naviagtion , so that they dont count.
		 */
		else
		{
			for (uint8_t i = 0; i < 16; i++)
			{
				if ((key_state_counter[button_values->B] == 1)
						|| (key_state_counter[button_values->D] == 1)) // Neglect B,D
				{
					continue;
				}
				if (key_state_counter[i] == 1)
				{
					button_presses_count++;
					stage = 1;
					break;
				}
			}
		}
	}
}
