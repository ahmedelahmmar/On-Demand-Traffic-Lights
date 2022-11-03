/*
 * Application.h
 *
 *  Created on: Oct 22, 2022
 *      Author: 4hmed
 */

#ifndef _APPLICATION_APPLICATION_H_
#define _APPLICATION_APPLICATION_H_

#include "../2.HAL/PushButtons/PushButtons.h"
#include "../2.HAL/LEDS/LEDS.h"

typedef enum
{
	PedestrianMode,
	NormalMode

} EN_Mode_t ;

typedef enum
{
	GREEN,
	RED,
	YELLOW,

} EN_Leds_t ;

void APP_Start(void);

#endif /* _APPLICATION_APPLICATION_H_ */
