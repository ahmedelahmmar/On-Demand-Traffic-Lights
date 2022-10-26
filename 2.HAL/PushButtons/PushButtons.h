/*
 * Buttons.h
 *
 *  Created on: Aug 27, 2022
 *      Author: 4hmed
 */

#ifndef SOURCES_2_HAL_BUTTON_INCLUDES_BUTTON_H_
#define SOURCES_2_HAL_BUTTON_INCLUDES_BUTTON_H_

#include "DIO.h"
#include "../1.MCAL/Interrupts/EXTINT.h"
#include "../1.MCAL/Interrupts/GINT.h"

typedef enum
{
	BUTTON_PED

} PushButton_ID_t;

typedef enum
{
	RELEASED,
	PRESSED

} PushButton_Status_t;

void PB_Init(void);
PushButton_Status_t PB_Status(PushButton_ID_t);

#endif /* SOURCES_2_HAL_BUTTON_INCLUDES_BUTTON_H_ */
