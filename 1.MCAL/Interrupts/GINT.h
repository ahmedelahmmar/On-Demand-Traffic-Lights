/*
 * Interrupts.h
 *
 *  Created on: Sep 3, 2022
 *      Author: 4hmed
 */

#ifndef SOURCES_1_MCAL_INTERRUPTS_INTERRUPTS_H_
#define SOURCES_1_MCAL_INTERRUPTS_INTERRUPTS_H_

#include <avr/interrupt.h>

#include "../../Utilities/BitMasking.h"
#include "../../Utilities/StandardTypes.h"

#define GINT_SREG_REG	(*(uint8_t*)0x5F)
#define GINT_GINT_PIN		7

void GINT_Enable(void);
void GINT_Disable(void);

#endif /* SOURCES_1_MCAL_INTERRUPTS_INTERRUPTS_H_ */
