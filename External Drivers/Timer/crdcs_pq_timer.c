/*
* File: crdcs_pq_timer.c
* Author: Devinda Srinath
* Description: Stopwatch timer feature for UI design
* Created on February 18, 2022, 10:20 PM
*/

#include <crdcs_pq_timer.h>


/* Intialize the timer by assign the keypad button values and pressing values*/
void timer_init (const uint8_t *key_state_arr,
	const button_value_map_t *button_values_ext)
{
	key_state_timer = key_state_arr;
	button_values = button_values_ext;
}

/* Deal with user to getting arguments while performing the time count.*/
void timer ()
{
	static uint8_t stage = 1;
	if (stage == 1)
	{
		/* Enter to stop watch mode.
		 * Update screen while working the timer. */
		SSD1306_Clear();
		char ticks[20];
		sprintf(ticks, "%d", timer_time);
		print_inline(50, 10, ticks, &Font_7x10, 1);
		print_inline(10, 30, "A:Start B:Stop", &Font_7x10, 1);
		print_inline(10, 50, "C:Reset D:M.menu", &Font_7x10, 1);
		SSD1306_UpdateScreen();
		keypad_clear();
		stage = 2;
	}
	else if (stage == 2)
	{
		/* Start the timer. */
		if (key_state_timer[button_values->A] == 1)
		{
			timer_ticks = 0;
			timer_state = 1;
			keypad_clear();
		}
		/* Stop the timer. */
		else if (key_state_timer[button_values->B] == 1)
		{
			timer_state = 0;
			keypad_clear();
		}
		/* Reset the timer. */
		else if (key_state_timer[button_values->C] == 1)
		{
			timer_state = 2;
			keypad_clear();
		}
		/* Exit to main menu. */
		else if (key_state_timer[button_values->D] == 1)
		{
			current_mode = MAIN_MENU;
			stage = 1;
			timer_time = 0;
			timer_ticks = 0;
			timer_state = 0;
			keypad_clear();
		}
		/* Timer state :
		 * 0 - timer off
		 * 1 - timer start/counting
		 * 2 - reset the count
		 */
		if (timer_state == 1)
		{
			/* 200 x 0.005 = 1 sec */
			if (timer_ticks >= 200)
			{
				timer_time++;
				timer_ticks = 0;
				stage = 1;
			}
		}
		else if (timer_state == 2)
		{
			timer_time = 0;
			timer_ticks = 0;
			timer_state = 0;
			stage = 1;
		}

	}

}

/* Increment at every 5 milisecond in timer mode. */
void timer_ticks_increment ()
{
	if (timer_state == 1)
	{
		timer_ticks++;
	}
}
