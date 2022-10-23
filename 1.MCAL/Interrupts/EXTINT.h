/*
 * EXTINT.h
 *
 *  Created on: Sep 3, 2022
 *      Author: 4hmed
 */

#ifndef SOURCES_1_MCAL_EXTINT_INCLUDES_EXTINT_H_
#define SOURCES_1_MCAL_EXTINT_INCLUDES_EXTINT_H_

#include <util/delay.h>
#include <avr/interrupt.h>

#include "../../Utilities/BitMasking.h"
#include "../../Utilities/StandardTypes.h"

#define EXTINT_INT0_BIT 	6
#define EXTINT_INT1_BIT 	7
#define EXTINT_INT2_BIT 	5

#define EXTINT_ISC2_BIT		6

#define EXTINT_INT0_MASK	0xFC
#define EXTINT_INT1_MASK	0xF3

#define EXTINT_MCUCR_REG	(*(uint8_t*)0x55)
#define EXTINT_MCUCSR_REG	(*(uint8_t*)0x54)
#define EXTINT_GICR_REG		(*(uint8_t*)0x5B)

typedef enum
{
	EXTINT_INT0,
	EXTINT_INT1,
	EXTINT_INT2

} EXTINT_intID_t;

typedef enum
{
	EXTINT_LOW_LEVEL,
	EXTINT_ANY_EDGE,
	EXTINT_FALLING_EDGE,
	EXTINT_RISING_EDGE

} EXTINT_iscMode_t;

static void EXTINT_voidEnable(EXTINT_intID_t);
static void EXTINT_voidDisable(EXTINT_intID_t);
void EXTINT_voidConfig(EXTINT_intID_t, EXTINT_iscMode_t);

#endif /* SOURCES_1_MCAL_EXTINT_INCLUDES_EXTINT_H_ */
