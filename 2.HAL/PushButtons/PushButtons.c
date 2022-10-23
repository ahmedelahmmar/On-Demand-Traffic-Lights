/*
 * Buttons.c
 *
 *  Created on: Aug 27, 2022
 *      Author: 4hmed
 */

#include "PushButtons.h"

void PB_Init(void)
{
	DIO_voidConfig(DIO_PIN2, DIO_PORTD, DIO_INPUT);
}

PushButton_Status_t PB_Status(PushButton_ID_t PB_ID)
{
	PushButton_Status_t loc_status = RELEASED;

	switch (PB_ID)
	{
	case BUTTON_PED:

		if (DIO_udtRead(DIO_PIN2, DIO_PORTD)) loc_status = PRESSED;
		else loc_status = RELEASED;

		break;
	}

	return loc_status;
}

