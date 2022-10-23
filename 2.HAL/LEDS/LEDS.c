/*
 * LED.c
 *
 *  Created on: Aug 27, 2022
 *      Author: 4hmed
 */
#include "LEDS.h"

void LEDS_Init(void)
{
	DIO_voidConfig(DIO_PIN0, DIO_PORTA, DIO_OUTPUT);
	DIO_voidConfig(DIO_PIN1, DIO_PORTA, DIO_OUTPUT);
	DIO_voidConfig(DIO_PIN2, DIO_PORTA, DIO_OUTPUT);
	DIO_voidConfig(DIO_PIN0, DIO_PORTB, DIO_OUTPUT);
	DIO_voidConfig(DIO_PIN1, DIO_PORTB, DIO_OUTPUT);
	DIO_voidConfig(DIO_PIN2, DIO_PORTB, DIO_OUTPUT);
}

void LEDS_On (LEDS_ID_t ledId)
{
	switch (ledId)
	{
	case GREEN_CAR:
		DIO_voidWrite(DIO_PIN0, DIO_PORTA, DIO_HIGH);
		break;

	case YELLOW_CAR:
		DIO_voidWrite(DIO_PIN1, DIO_PORTA, DIO_HIGH);
		break;

	case RED_CAR:
		DIO_voidWrite(DIO_PIN2, DIO_PORTA, DIO_HIGH);
		break;

	case GREEN_PED:
		DIO_voidWrite(DIO_PIN0, DIO_PORTB, DIO_HIGH);
		break;

	case YELLOW_PED:
		DIO_voidWrite(DIO_PIN1, DIO_PORTB, DIO_HIGH);
		break;

	case RED_PED:
		DIO_voidWrite(DIO_PIN2, DIO_PORTB, DIO_HIGH);
		break;
	}
}

void LEDS_Off(LEDS_ID_t ledId)
{
	switch (ledId)
	{
	case GREEN_CAR:
		DIO_voidWrite(DIO_PIN0, DIO_PORTA, DIO_LOW);
		break;

	case YELLOW_CAR:
		DIO_voidWrite(DIO_PIN1, DIO_PORTA, DIO_LOW);
		break;

	case RED_CAR:
		DIO_voidWrite(DIO_PIN2, DIO_PORTA, DIO_LOW);
		break;

	case GREEN_PED:
		DIO_voidWrite(DIO_PIN0, DIO_PORTB, DIO_LOW);
		break;

	case YELLOW_PED:
		DIO_voidWrite(DIO_PIN1, DIO_PORTB, DIO_LOW);
		break;

	case RED_PED:
		DIO_voidWrite(DIO_PIN2, DIO_PORTB, DIO_LOW);
		break;
	}
}

void LEDS_Toggle(LEDS_ID_t ledId)
{
	switch(ledId)
	{
	case GREEN_CAR:
		DIO_voidToggle(DIO_PIN0, DIO_PORTA);
		break;

	case YELLOW_CAR:
		DIO_voidToggle(DIO_PIN1, DIO_PORTA);
		break;

	case RED_CAR:
		DIO_voidToggle(DIO_PIN2, DIO_PORTA);
		break;

	case GREEN_PED:
		DIO_voidToggle(DIO_PIN0, DIO_PORTB);
		break;

	case YELLOW_PED:
		DIO_voidToggle(DIO_PIN1, DIO_PORTB);
		break;

	case RED_PED:
		DIO_voidToggle(DIO_PIN2, DIO_PORTB);
		break;
	}
}

bool LEDS_Status(LEDS_ID_t ledId)
{
	bool loc_status = False;

	switch (ledId)
	{
	case GREEN_CAR:
		if (CHECK_BIT(0, DIO_PORTA_REG)) loc_status = True;
		else loc_status = False;
		break;

	case YELLOW_CAR:
		if (CHECK_BIT(1, DIO_PORTA_REG)) loc_status = True;
		else loc_status = False;
		break;

	case RED_CAR:
		if (CHECK_BIT(2, DIO_PORTA_REG)) loc_status = True;
		else loc_status = False;
		break;

	case GREEN_PED:
		if (CHECK_BIT(0, DIO_PORTB_REG)) loc_status = True;
		else loc_status = False;
		break;

	case YELLOW_PED:
		if (CHECK_BIT(1, DIO_PORTB_REG)) loc_status = True;
		else loc_status = False;
		break;

	case RED_PED:
		if (CHECK_BIT(2, DIO_PORTB_REG)) loc_status = True;
		else loc_status = False;
		break;
	}

	return loc_status;
}
