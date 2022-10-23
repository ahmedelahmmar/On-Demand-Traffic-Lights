/*
 * EXTINT.c
 *
 *  Created on: Sep 3, 2022
 *      Author: 4hmed
 */
#include "EXTINT.h"

static void EXTINT_voidEnable(EXTINT_intID_t intID)
{
	switch (intID)
	{
	case EXTINT_INT0:
		SET_BIT(EXTINT_INT0_BIT, EXTINT_GICR_REG);
		break;

	case EXTINT_INT1:
		SET_BIT(EXTINT_INT1_BIT, EXTINT_GICR_REG);
		break;

	case EXTINT_INT2:
		SET_BIT(EXTINT_INT2_BIT, EXTINT_GICR_REG);
		break;
	}
}

static void EXTINT_voidDisable(EXTINT_intID_t intID)
{
	switch (intID)
	{
	case EXTINT_INT0:
		CLEAR_BIT(EXTINT_INT0_BIT, EXTINT_GICR_REG);
		break;

	case EXTINT_INT1:
		CLEAR_BIT(EXTINT_INT1_BIT, EXTINT_GICR_REG);
		break;

	case EXTINT_INT2:
		CLEAR_BIT(EXTINT_INT2_BIT, EXTINT_GICR_REG);
		break;
	}
}

void EXTINT_voidConfig(EXTINT_intID_t interrupt, EXTINT_iscMode_t mode)
{
	switch (interrupt)
	{
	case EXTINT_INT0:

		EXTINT_voidDisable(EXTINT_INT0);
		_delay_ms(1);

		EXTINT_MCUCR_REG = (EXTINT_MCUCR_REG & EXTINT_INT0_MASK) | (mode << 0);

		_delay_ms(1);
		EXTINT_voidEnable(EXTINT_INT0);
		break;

	case EXTINT_INT1:

		EXTINT_voidDisable(EXTINT_INT1);
		_delay_ms(1);

		EXTINT_MCUCR_REG = (EXTINT_MCUCR_REG & EXTINT_INT1_MASK) | (mode << 2);

		_delay_ms(1);
		EXTINT_voidEnable(EXTINT_INT1);
		break;

	case EXTINT_INT2:

		if (mode == EXTINT_RISING_EDGE)
		{
			EXTINT_voidDisable(EXTINT_INT2);
			_delay_ms(1);

			SET_BIT(EXTINT_ISC2_BIT, EXTINT_MCUCSR_REG);

			_delay_ms(1);
			EXTINT_voidEnable(EXTINT_INT2);
		}
		else if (mode == EXTINT_FALLING_EDGE)
		{
			EXTINT_voidDisable(EXTINT_INT2);
			_delay_ms(1);

			CLEAR_BIT(EXTINT_ISC2_BIT, EXTINT_MCUCSR_REG);

			_delay_ms(1);
			EXTINT_voidEnable(EXTINT_INT2);
		}
		else
		{
			// Do nothing.
		}
		break;
	}
}
