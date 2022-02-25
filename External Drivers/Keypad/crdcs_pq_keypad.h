/*
* File: crdcs_pq_keypad.h
* Author: Devinda Srinath
* Description: 4x4 keypad scanning
* Created on February 18, 2022, 10:20 PM
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "stm32f1xx_hal.h"

// The Number OF KeyPAD Units To Be Used In The Project
#define KEYPAD_UNITS  1
#define ROWS          4
#define COLS          4
#define KEYS          16

#define KEY_PRESSED   1
#define KEY_RELEASED  0

// Keypad pin configuration
typedef struct
{

	GPIO_TypeDef * ROW_GPIO[ROWS];
	uint16_t ROW_PIN[ROWS];
	GPIO_TypeDef * COL_GPIO[COLS];
	uint16_t COL_PIN[COLS];

} keypad_cfgtype_t;

typedef struct
{

	uint8_t zero;
	uint8_t one;
	uint8_t two;
	uint8_t three;
	uint8_t four;
	uint8_t five;
	uint8_t six;
	uint8_t seven;
	uint8_t eight;
	uint8_t nine;
	uint8_t star;
	uint8_t hash;
	uint8_t A;
	uint8_t B;
	uint8_t C;
	uint8_t D;

} button_value_map_t;

/* Keypad current data */
typedef struct
{

	uint8_t * key_states;

} keypad_info_t;

void keypad_init (const uint8_t *au8_KeyStates,
	const keypad_cfgtype_t KEYPAD_CfgParam,
	button_value_map_t *button_values_ext);
void keypad_Scan ();
void keypad_clear ();

#endif /* KEYPAD_H_ */
