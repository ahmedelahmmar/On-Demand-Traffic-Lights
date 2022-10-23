/*
 * Interrupts.c
 *
 *  Created on: Sep 3, 2022
 *      Author: 4hmed
 */

#include "GINT.h"

void GINT_Enable(void)
{
	SET_BIT(GINT_GINT_PIN, GINT_SREG_REG);
}

void GINT_Disable(void)
{
	CLEAR_BIT(GINT_GINT_PIN, GINT_SREG_REG);
}
