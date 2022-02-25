/*
* File: crdcs_pq_keypad.c
* Author: Devinda Srinath
* Description: 4x4 keypad scanning
* Created on February 18, 2022, 10:20 PM
 */

#include <crdcs_pq_keypad.h>

static keypad_info_t keypad_info = { 0 };

static keypad_cfgtype_t keypad_cfgparam;

/* Change these values according to your keypad*/
static button_value_map_t button_values =
{ .zero = 13, .one = 0, .two = 1, .three = 2, .four = 4, .five = 5, .six = 6,
		.seven = 8, .eight = 9, .nine = 10, .star = 12, .hash = 14, .A = 3, .B =
				7, .C = 11, .D = 15 };

void keypad_init (const uint8_t *au8_KeyStates,
	const keypad_cfgtype_t keypad_cfgparam_ext,
	button_value_map_t *button_values_ext)
{
     /* If there is no global variable use to hold then arrise an error, else
      * continue procedure by assigning the variables.
      */
	if (au8_KeyStates != NULL)
	{
		keypad_info.key_states = au8_KeyStates;
		keypad_cfgparam = keypad_cfgparam_ext;
		*button_values_ext = button_values;
	}
	else
	{
		/* Potentially Should Return An Error */
		return;
	}

}

void keypad_scan ()
{
	uint8_t au8_ReadState[ROWS] =
	{ 0 };
	uint8_t au8_ReadSt;
	uint8_t i = 0;

	/* Steady State: Output The Pattern [1 1 1 1] To The COL Pins */

	for (i = 0; i < COLS; i++)
	{
		HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[i],
				keypad_cfgparam.COL_PIN[i], 1);
	}

	/* Steady State: Read The ROW Pins To Know If Any Key Is Pressed At All or Not */

	for (i = 0; i < ROWS; i++)
	{
		au8_ReadState[i] = HAL_GPIO_ReadPin(keypad_cfgparam.ROW_GPIO[i],
				keypad_cfgparam.ROW_PIN[i]);
	}

	/* If Any member in array au8_ReadState is 1, we know that a key is pressed */
	/* And we'll keep changing the COL pins output pattern until we find the pressed key or keys */
	/* Else: We'll end the scan procedure at this point */

	if ((au8_ReadState[0]) | (au8_ReadState[1]) | (au8_ReadState[2])
			| (au8_ReadState[3]))
	{
		/*--[ First Row Check ]--*/

		if (au8_ReadState[0])
		{
			/* Output To The COL Pins This Pattern: [1 0 0 0] */
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[0],
					keypad_cfgparam.COL_PIN[0], 1);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[1],
					keypad_cfgparam.COL_PIN[1], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[2],
					keypad_cfgparam.COL_PIN[2], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[3],
					keypad_cfgparam.COL_PIN[3], 0);
			/* Read ROW0-COL0 */
			au8_ReadSt = HAL_GPIO_ReadPin(keypad_cfgparam.ROW_GPIO[0],
					keypad_cfgparam.ROW_PIN[0]);

			if (au8_ReadSt)
			{
				keypad_info.key_states[0] = 1;
			}
			else
			{
				keypad_info.key_states[0] = 0;
			}

			/* Output To The COL Pins This Pattern: [0 1 0 0] */
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[0],
					keypad_cfgparam.COL_PIN[0], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[1],
					keypad_cfgparam.COL_PIN[1], 1);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[2],
					keypad_cfgparam.COL_PIN[2], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[3],
					keypad_cfgparam.COL_PIN[3], 0);
			/* Read ROW0-COL1 */
			au8_ReadSt = HAL_GPIO_ReadPin(keypad_cfgparam.ROW_GPIO[0],
					keypad_cfgparam.ROW_PIN[0]);

			if (au8_ReadSt)
			{
				keypad_info.key_states[1] = 1;
			}
			else
			{
				keypad_info.key_states[1] = 0;
			}

			/* Output To The COL Pins This Pattern: [0 0 1 0] */
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[0],
					keypad_cfgparam.COL_PIN[0], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[1],
					keypad_cfgparam.COL_PIN[1], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[2],
					keypad_cfgparam.COL_PIN[2], 1);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[3],
					keypad_cfgparam.COL_PIN[3], 0);
			/* Read ROW0-COL2 */
			au8_ReadSt = HAL_GPIO_ReadPin(keypad_cfgparam.ROW_GPIO[0],
					keypad_cfgparam.ROW_PIN[0]);

			if (au8_ReadSt)
			{
				keypad_info.key_states[2] = 1;
			}
			else
			{
				keypad_info.key_states[2] = 0;
			}

			/* Output To The COL Pins This Pattern: [0 0 0 1] */
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[0],
					keypad_cfgparam.COL_PIN[0], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[1],
					keypad_cfgparam.COL_PIN[1], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[2],
					keypad_cfgparam.COL_PIN[2], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[3],
					keypad_cfgparam.COL_PIN[3], 1);
			/* Read ROW0-COL3 */
			au8_ReadSt = HAL_GPIO_ReadPin(keypad_cfgparam.ROW_GPIO[0],
					keypad_cfgparam.ROW_PIN[0]);

			if (au8_ReadSt)
			{
				keypad_info.key_states[3] = 1;
			}

		}
		else
		{
			keypad_info.key_states[0] = 0;
			keypad_info.key_states[1] = 0;
			keypad_info.key_states[2] = 0;
			keypad_info.key_states[3] = 0;
		}

		/*---------------------[END OF 1st ROW Check ]--------------------*/
		/*--[ Second Row Check ]--*/

		if (au8_ReadState[1])
		{
			/* Output To The COL Pins This Pattern: [1 0 0 0] */
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[0],
					keypad_cfgparam.COL_PIN[0], 1);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[1],
					keypad_cfgparam.COL_PIN[1], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[2],
					keypad_cfgparam.COL_PIN[2], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[3],
					keypad_cfgparam.COL_PIN[3], 0);
			/* Read ROW1-COL0 */
			au8_ReadSt = HAL_GPIO_ReadPin(keypad_cfgparam.ROW_GPIO[1],
					keypad_cfgparam.ROW_PIN[1]);

			if (au8_ReadSt)
			{
				keypad_info.key_states[4] = 1;
			}
			else
			{
				keypad_info.key_states[4] = 0;
			}

			/* Output To The COL Pins This Pattern: [0 1 0 0] */
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[0],
					keypad_cfgparam.COL_PIN[0], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[1],
					keypad_cfgparam.COL_PIN[1], 1);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[2],
					keypad_cfgparam.COL_PIN[2], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[3],
					keypad_cfgparam.COL_PIN[3], 0);
			/* Read ROW1-COL1 */
			au8_ReadSt = HAL_GPIO_ReadPin(keypad_cfgparam.ROW_GPIO[1],
					keypad_cfgparam.ROW_PIN[1]);

			if (au8_ReadSt)
			{
				keypad_info.key_states[5] = 1;
			}
			else
			{
				keypad_info.key_states[5] = 0;
			}

			/* Output To The COL Pins This Pattern: [0 0 1 0] */
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[0],
					keypad_cfgparam.COL_PIN[0], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[1],
					keypad_cfgparam.COL_PIN[1], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[2],
					keypad_cfgparam.COL_PIN[2], 1);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[3],
					keypad_cfgparam.COL_PIN[3], 0);
			/* Read ROW1-COL2 */
			au8_ReadSt = HAL_GPIO_ReadPin(keypad_cfgparam.ROW_GPIO[1],
					keypad_cfgparam.ROW_PIN[1]);

			if (au8_ReadSt)
			{
				keypad_info.key_states[6] = 1;
			}
			else
			{
				keypad_info.key_states[6] = 0;
			}

			/* Output To The COL Pins This Pattern: [0 0 0 1] */
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[0],
					keypad_cfgparam.COL_PIN[0], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[1],
					keypad_cfgparam.COL_PIN[1], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[2],
					keypad_cfgparam.COL_PIN[2], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[3],
					keypad_cfgparam.COL_PIN[3], 1);
			/* Read ROW1-COL3 */
			au8_ReadSt = HAL_GPIO_ReadPin(keypad_cfgparam.ROW_GPIO[1],
					keypad_cfgparam.ROW_PIN[1]);

			if (au8_ReadSt)
			{
				keypad_info.key_states[7] = 1;
			}

		}
		else
		{
			keypad_info.key_states[4] = 0;
			keypad_info.key_states[5] = 0;
			keypad_info.key_states[6] = 0;
			keypad_info.key_states[7] = 0;
		}

		/*---------------------[END OF 2nd ROW Check ]--------------------*/
		/*--[ Third Row Check ]--*/

		if (au8_ReadState[2])
		{
			/* Output To The COL Pins This Pattern: [1 0 0 0] */
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[0],
					keypad_cfgparam.COL_PIN[0], 1);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[1],
					keypad_cfgparam.COL_PIN[1], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[2],
					keypad_cfgparam.COL_PIN[2], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[3],
					keypad_cfgparam.COL_PIN[3], 0);
			/* Read ROW2-COL0 */
			au8_ReadSt = HAL_GPIO_ReadPin(keypad_cfgparam.ROW_GPIO[2],
					keypad_cfgparam.ROW_PIN[2]);

			if (au8_ReadSt)
			{
				keypad_info.key_states[8] = 1;
			}
			else
			{
				keypad_info.key_states[8] = 0;
			}

			/* Output To The COL Pins This Pattern: [0 1 0 0] */
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[0],
					keypad_cfgparam.COL_PIN[0], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[1],
					keypad_cfgparam.COL_PIN[1], 1);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[2],
					keypad_cfgparam.COL_PIN[2], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[3],
					keypad_cfgparam.COL_PIN[3], 0);
			/* Read ROW2-COL1 */
			au8_ReadSt = HAL_GPIO_ReadPin(keypad_cfgparam.ROW_GPIO[2],
					keypad_cfgparam.ROW_PIN[2]);

			if (au8_ReadSt)
			{
				keypad_info.key_states[9] = 1;
			}
			else
			{
				keypad_info.key_states[9] = 0;
			}

			/* Output To The COL Pins This Pattern: [0 0 1 0] */
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[0],
					keypad_cfgparam.COL_PIN[0], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[1],
					keypad_cfgparam.COL_PIN[1], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[2],
					keypad_cfgparam.COL_PIN[2], 1);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[3],
					keypad_cfgparam.COL_PIN[3], 0);
			/* Read ROW2-COL2 */
			au8_ReadSt = HAL_GPIO_ReadPin(keypad_cfgparam.ROW_GPIO[2],
					keypad_cfgparam.ROW_PIN[2]);

			if (au8_ReadSt)
			{
				keypad_info.key_states[10] = 1;
			}
			else
			{
				keypad_info.key_states[10] = 0;
			}

			/* Output To The COL Pins This Pattern: [0 0 0 1] */
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[0],
					keypad_cfgparam.COL_PIN[0], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[1],
					keypad_cfgparam.COL_PIN[1], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[2],
					keypad_cfgparam.COL_PIN[2], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[3],
					keypad_cfgparam.COL_PIN[3], 1);
			/* Read ROW2-COL3 */
			au8_ReadSt = HAL_GPIO_ReadPin(keypad_cfgparam.ROW_GPIO[2],
					keypad_cfgparam.ROW_PIN[2]);

			if (au8_ReadSt)
			{
				keypad_info.key_states[11] = 1;
			}

		}
		else
		{
			keypad_info.key_states[8] = 0;
			keypad_info.key_states[9] = 0;
			keypad_info.key_states[10] = 0;
			keypad_info.key_states[11] = 0;
		}

		/*---------------------[END OF 3rd ROW Check ]--------------------*/
		/*--[ Fourth Row Check ]--*/

		if (au8_ReadState[3])
		{
			/* Output To The COL Pins This Pattern: [1 0 0 0] */
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[0],
					keypad_cfgparam.COL_PIN[0], 1);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[1],
					keypad_cfgparam.COL_PIN[1], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[2],
					keypad_cfgparam.COL_PIN[2], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[3],
					keypad_cfgparam.COL_PIN[3], 0);
			/* Read ROW3-COL0 */
			au8_ReadSt = HAL_GPIO_ReadPin(keypad_cfgparam.ROW_GPIO[3],
					keypad_cfgparam.ROW_PIN[3]);

			if (au8_ReadSt)
			{
				keypad_info.key_states[12] = 1;
			}
			else
			{
				keypad_info.key_states[12] = 0;
			}

			/* Output To The COL Pins This Pattern: [0 1 0 0] */
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[0],
					keypad_cfgparam.COL_PIN[0], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[1],
					keypad_cfgparam.COL_PIN[1], 1);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[2],
					keypad_cfgparam.COL_PIN[2], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[3],
					keypad_cfgparam.COL_PIN[3], 0);
			/* Read ROW3-COL1 */
			au8_ReadSt = HAL_GPIO_ReadPin(keypad_cfgparam.ROW_GPIO[3],
					keypad_cfgparam.ROW_PIN[3]);

			if (au8_ReadSt)
			{
				keypad_info.key_states[13] = 1;
			}
			else
			{
				keypad_info.key_states[13] = 0;
			}

			/* Output To The COL Pins This Pattern: [0 0 1 0] */
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[0],
					keypad_cfgparam.COL_PIN[0], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[1],
					keypad_cfgparam.COL_PIN[1], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[2],
					keypad_cfgparam.COL_PIN[2], 1);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[3],
					keypad_cfgparam.COL_PIN[3], 0);
			/* Read ROW3-COL2 */
			au8_ReadSt = HAL_GPIO_ReadPin(keypad_cfgparam.ROW_GPIO[3],
					keypad_cfgparam.ROW_PIN[3]);

			if (au8_ReadSt)
			{
				keypad_info.key_states[14] = 1;
			}
			else
			{
				keypad_info.key_states[14] = 0;
			}

			/* Output To The COL Pins This Pattern: [0 0 0 1] */
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[0],
					keypad_cfgparam.COL_PIN[0], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[1],
					keypad_cfgparam.COL_PIN[1], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[2],
					keypad_cfgparam.COL_PIN[2], 0);
			HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[3],
					keypad_cfgparam.COL_PIN[3], 1);
			/* Read ROW3-COL3 */
			au8_ReadSt = HAL_GPIO_ReadPin(keypad_cfgparam.ROW_GPIO[3],
					keypad_cfgparam.ROW_PIN[3]);

			if (au8_ReadSt)
			{
				keypad_info.key_states[15] = 1;
			}

		}
		else
		{
			keypad_info.key_states[12] = 0;
			keypad_info.key_states[13] = 0;
			keypad_info.key_states[14] = 0;
			keypad_info.key_states[15] = 0;
		}

		/*---------------------[END OF 4th ROW Check ]--------------------*/
	}
	/* Else If No Key Is Pressed */
	else
	{
		/* Fill The Keys States With 0s */
		keypad_clear();
	}
	/* Back To Steady State: Output The Pattern [1 1 1 1] To The COL Pins */

	for (i = 0; i < COLS; i++)
	{
		HAL_GPIO_WritePin(keypad_cfgparam.COL_GPIO[i],
				keypad_cfgparam.COL_PIN[i], 1);
	}

}

/* clear The Keys States With 0s */
void keypad_clear ()
{

	for (uint8_t i = 0; i < KEYS; i++)
	{
		keypad_info.key_states[i] = 0;
	}

}
