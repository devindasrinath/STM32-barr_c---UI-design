/*
* File: crdcs_pq_adder.c
* Author: Devinda Srinath
* Description: Adder feature for UI design
* Created on February 18, 2022, 10:20 PM
 */

#include <crdcs_pq_adder.h>


static uint8_t num_values[] = { 1, 2, 3, 0, 4, 5, 6, 0, 7, 8, 9, 0 };

/* Intialize the adder by assign the keypad button values and pressing values*/
void adder_init (const uint8_t *key_state_arr,
	const button_value_map_t *button_values_ext)
{
	key_state_adder = key_state_arr;
	button_values = button_values_ext;
}

/* Deal with user to getting arguments while performing the addition.*/
void adder ()
{

	static uint8_t stage = 1;
	if (stage == 1)
	{
		/* Enter to the Adder mode.
		 * Requesting to enter the first input from user.
		 */
		stage = request_number_ui(2, 1, &num1);
	}
	else if (stage == 2)
	{
		/*Checking the number pad. */
		stage = checking_number_keypad(2, 3, 1, &num1);
	}
	else if (stage == 3)
	{
		/* Requesting to enter the sencond input from user.*/
		stage = request_number_ui(4, 2, &num2);
	}
	else if (stage == 4)
	{
		/* Checking the number pad */
		stage = checking_number_keypad(4, 5, 3, &num2);
	}
	else if (stage == 5)
	{
		/* Show the summation of two values (show once).*/
		char summation[10];
		sprintf(summation, "Ans = %d", (num1 + num2));
		SSD1306_Clear();
		print_inline(10, 10, summation, &Font_7x10, 1);
		print_inline(10, 30, "A - Adder", &Font_7x10, 1);
		print_inline(10, 50, "D - Main menu", &Font_7x10, 1);
		SSD1306_UpdateScreen();
		num1 = num2 = 0;
		stage = 6;

	}
	else if (stage == 6)
	{
		/* Navigate to adder or main menu, */
		if (key_state_adder[button_values->A] == KEY_PRESSED)
		{
			keypad_clear();
			stage = 1; // Direct to adder mode

		}
		else if (key_state_adder[button_values->D] == KEY_PRESSED)
		{
			keypad_clear();
			current_mode = MAIN_MENU;
			stage = 1;
		}
	}

}

/* Request and showing the inputs of addition.*/
static uint8_t request_number_ui (const uint8_t next_stage,
	const uint8_t arg_no, const uint8_t *num)
{
	uint8_t str[15];

	if (*num > 0 && *num < 10)
	{
		sprintf(str, "NUM%d = %d", arg_no, *num);
	}
	else
	{
		sprintf(str, "NUM%d = ", arg_no);
	}

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
	SSD1306_Clear();
	print_inline(10, 10, str, &Font_7x10, 1);
	print_inline(10, 30, "D: Ok", &Font_7x10, 1);
	SSD1306_UpdateScreen();
	return next_stage;
}

/* Checking the number pad for getting adding inputs.*/
static uint8_t checking_number_keypad (const uint8_t current_stage,
	const uint8_t next_stage, const uint8_t previous_stage, uint8_t *num)
{
	for (uint8_t i = 0; i < (KEYS - 4); i++)
	{
		/* Filterout english characters and symbols*/

		if ((i + 1) % 4 == 0)
		{
			continue;
		}

		/* Getting integer from buttom index*/

		if (key_state_adder[i] == KEY_PRESSED)
		{
			keypad_clear();
			*num = num_values[i];
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1); //turn on LED
			return previous_stage;
		}
	}

	/* Exit from num1 enter to second number request(num2)*/

	if (key_state_adder[button_values->D] == KEY_PRESSED)
	{
		keypad_clear();
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0); //turn off LED

		return next_stage;
	}

	return current_stage;

}
