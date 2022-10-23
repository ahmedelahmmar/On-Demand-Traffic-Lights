/*
 * LED.h
 *
 *  Created on: Aug 27, 2022
 *      Author: 4hmed
 */

#ifndef SOURCES_2_HAL_LED_INCLUDES_LED_H_
#define SOURCES_2_HAL_LED_INCLUDES_LED_H_

#include "DIO.h"

typedef enum
{
	GREEN_CAR,
	YELLOW_CAR,
	RED_CAR,
	GREEN_PED,
	YELLOW_PED,
	RED_PED

} LEDS_ID_t ;

void LEDS_Init(void);
void LEDS_On(LEDS_ID_t);
void LEDS_Off(LEDS_ID_t);
void LEDS_Toggle(LEDS_ID_t);
bool LEDS_Status(LEDS_ID_t);

#endif /* SOURCES_2_HAL_LED_INCLUDES_LED_H_ */
