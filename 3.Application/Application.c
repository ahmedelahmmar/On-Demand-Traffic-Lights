/*
 * Application.c
 *
 *  Created on: Oct 22, 2022
 *      Author: 4hmed
 */
#include "Application.h"

EN_Mode_t Mode = NormalMode;
EN_Mode_t PrevMode = NormalMode;

EN_Leds_t currentNormLed;
EN_Leds_t currentPedLed = RED;

EN_Leds_t nextNormLED = GREEN;
EN_Leds_t nextpedLED;

ISR(INT0_vect)
{
	Mode = PedestrianMode;
}

/* 	The following is TIMER0's task which is done every 500ms.
 * 	It checks on the system's global variable 'Mode'
 *
 * 	In Normal and Pedestrian Modes it updates the car lights every 5 seconds
 * 	and toggles the yellow LEDs once every 500ms when desired.
 *
 * 	In Pedestrian Mode it checks on the current car lights and
 * 	takes an action on the pedestrian lights according to the
 * 	system's design requirements.
 */

void TIMER0_Execution(void)
{
	static uint8_t counter;

	switch (Mode)
	{
	case NormalMode:

		if (PrevMode != NormalMode)
		{
			PrevMode = NormalMode;
			counter = 1;
		}

		if (currentNormLed == YELLOW) LEDS_Toggle(YELLOW_CAR);

		if ((counter % 10) == 0)
		{
			switch (nextNormLED)
			{
			case GREEN:

				currentNormLed = GREEN;
				nextNormLED = YELLOW;
				break;

			case YELLOW:

				switch (currentNormLed)
				{
				case RED:
					nextNormLED = GREEN;
					break;

				case GREEN:
					nextNormLED = RED;

				default: break;
				}
				currentNormLed = YELLOW;
				break;

			case RED:
				currentNormLed = RED;
				nextNormLED = YELLOW;
				break;

			default: break;
			}
		}

		break;

	case PedestrianMode:

		if (PrevMode != PedestrianMode)
		{
			PrevMode = PedestrianMode;
			counter = 1;

			switch (currentNormLed)
			{
			case GREEN:
				currentPedLed = RED;
				currentNormLed = YELLOW;
				currentPedLed = YELLOW;

				nextpedLED = GREEN;
				break;

			case YELLOW:
				currentPedLed = RED;
				currentPedLed = YELLOW;

				nextpedLED = GREEN;
				break;

			case RED:
				currentPedLed = GREEN;
				nextpedLED = YELLOW;
				break;
			}
		}

		if (currentPedLed == YELLOW)
		{
			LEDS_Toggle(YELLOW_CAR);
			LEDS_Toggle(YELLOW_PED);
		}

		if ((counter % 10) == 0)
		{
			switch (nextpedLED)
			{
			case GREEN:
				currentNormLed = RED;
				nextNormLED = YELLOW;

				currentPedLed = GREEN;
				nextpedLED = YELLOW;
				break;

			case YELLOW:
				currentNormLed = YELLOW;
				nextNormLED = GREEN;

				currentPedLed = YELLOW;
				nextpedLED = RED;
				break;

			case RED:
				currentNormLed = GREEN;
				nextNormLED = YELLOW;

				currentPedLed = RED;

				Mode = NormalMode;
				break;
			}
		}

		break;

	default: break;
	}

	++counter;
	if (counter == 255) counter = 5;
}

void APP_Start(void)
{
	// PushButton initialization
	PB_Init();

	// LEDs initialization
	LEDS_Init();

	// TIMER0 initialization, setting TIMER0_Execution as the callback function and setting its period as 500ms
	TIMER_Init(TIMER0);
	TIMER_SetCallBack(TIMER0, TIMER0_Execution);
	TIMER_SetTime(TIMER0, 500);
	TIMER_Start(TIMER0);

/* 	The following is the system's infinite running loop
 * 	which constantly checks which LEDs are supposed to
 * 	be on/off according to the system's requirements and
 * 	the implemented decision making algorithm.
 */
	while (True)
	{
		switch (currentNormLed)
		{
		case GREEN:
			LEDS_On(GREEN_CAR);
			LEDS_Off(YELLOW_CAR);
			LEDS_Off(RED_CAR);
			break;

		case RED:
			LEDS_Off(GREEN_CAR);
			LEDS_Off(YELLOW_CAR);
			LEDS_On(RED_CAR);
			break;

		default: break;
		}

		switch (currentPedLed)
		{
		case GREEN:
			LEDS_On(GREEN_PED);
			LEDS_Off(YELLOW_PED);
			LEDS_Off(RED_PED);
			break;

		case RED:
			LEDS_Off(GREEN_PED);
			LEDS_Off(YELLOW_PED);
			LEDS_On(RED_PED);
			break;

		default: break;
		}
	}
}
