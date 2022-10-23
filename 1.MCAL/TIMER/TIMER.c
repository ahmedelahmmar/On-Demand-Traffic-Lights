/*
 * TIMER.c
 *
 *  Created on: Oct 1, 2022
 *      Author: 4hmed
 */
#include "TIMER_Private.h"
#include "TIMER_Config.h"
#include "TIMER.h"

static uint32_t TIMER_nOVF;
static uint32_t TIMER_nCompMatch;
static uint32_t TIMER_intialPreload;

void static (*CallBack0) (void);
void static (*CallBack1) (void);
void static (*CallBack2) (void);

void TIMER_Init(TIMER_Channel_t channel)
{
	GINT_Enable();
	switch (channel)
	{
	case TIMER0:
		#if (TIMER0_MODE == NORMAL)
			// Normal mode.
			CLEAR_BIT(TCCR0_WGM00, TCCR0_REG);
			CLEAR_BIT(TCCR0_WGM01, TCCR0_REG);
			// Overflow interrupt.
			SET_BIT(TIMSK_TOIE0, TIMSK_REG);


		#elif (TIMER0_MODE == CTC)
			// CTC mode.
			CLEAR_BIT(TCCR0_WGM00, TCCR0_REG);
			SET_BIT(TCCR0_WGM01, TCCR0_REG);
			// Output compare match interrupt.
			SET_BIT(TIMSK_OCIE0, TIMSK_REG);

		#else
			#error " 'TIMER.c' Please configure TIMER0 mode in TIMER_Config.h "
		#endif
		break;

	case TIMER1:
		break;

	case TIMER2:
		break;
	}
}

void TIMER_SetTime(TIMER_Channel_t channel, uint32_t desiredTime_ms)
{
	switch (channel)
	{
	case TIMER0:;
			uint8_t tickTime = PRESCALER0 / FCPU_MHz; 					// in microseconds
			uint32_t totalTicks = (desiredTime_ms * 1000) / tickTime;

		#if	(TIMER0_MODE == NORMAL)

				TIMER_nOVF = totalTicks / 256;
				TIMER_intialPreload = 256 - (totalTicks % 256);

				if ((totalTicks % 256) != 0)
				{
					TIMER_SetTCNT(TIMER0, TIMER_intialPreload);
					++TIMER_nOVF;
				}
		#elif (TIMER0_MODE == CTC)
				uint8_t divFactor = 255;

				while (totalTicks % divFactor) --divFactor;

				TIMER_nCompMatch = totalTicks / divFactor;
				TIMER_SetOCR(TIMER0, (divFactor - 1));
		#endif
		break;

	case TIMER1:
		break;

	case TIMER2:
		break;
	}
}

void TIMER_Start(TIMER_Channel_t channel)
{
	switch (channel)
	{
	case TIMER0:
		#if (PRESCALER0 == 1024)

				SET_BIT(TCCR0_CS00, TCCR0_REG);
				CLEAR_BIT(TCCR0_CS01, TCCR0_REG);
				SET_BIT(TCCR0_CS02, TCCR0_REG);

		#elif (PRESCALER0 == 256)

				CLEAR_BIT(TCCR0_CS00, TCCR0_REG);
				CLEAR_BIT(TCCR0_CS01, TCCR0_REG);
				SET_BIT(TCCR0_CS02, TCCR0_REG);
		#else
			#error " 'TIMER0' Please configure PRESCALER0 in TIMER_Config.h "
		#endif
		break;

	case TIMER1:
		#if (PRESCALER1 == 256)

			SET_BIT(TCCR1B_CS12, TCCR1B_REG);
			CLEAR_BIT(TCCR1B_CS11, TCCR1B_REG);
			CLEAR_BIT(TCCR1B_CS10, TCCR1B_REG);

		#endif
		break;

	case TIMER2:
		break;
	}
}

void TIMER_Stop(TIMER_Channel_t channel)
{
	switch (channel)
	{
	case TIMER0:
		CLEAR_BIT(TCCR0_CS02, TCCR0_REG);
		CLEAR_BIT(TCCR0_CS01, TCCR0_REG);
		CLEAR_BIT(TCCR0_CS00, TCCR0_REG);

		TIMER_SetTCNT(TIMER0, 0);
		break;

	case TIMER1:
		CLEAR_BIT(TCCR1B_CS12, TCCR1B_REG);
		CLEAR_BIT(TCCR1B_CS11, TCCR1B_REG);
		CLEAR_BIT(TCCR1B_CS10, TCCR1B_REG);
		break;

	case TIMER2:
		break;
	}
}

void TIMER_SetCallBack(TIMER_Channel_t channel, void (*CallBack)(void))
{
	switch (channel)
	{
	case TIMER0:
		CallBack0 = CallBack;
		break;

	case TIMER1:
		CallBack1 = CallBack;
		break;

	case TIMER2:
		CallBack2 = CallBack;
		break;
	}
}

static void TIMER_SetTCNT(TIMER_Channel_t channel, uint16__t preLoad)
{
	switch (channel)
	{
	case TIMER0:
		TCNT0_REG = preLoad;
		break;

	case TIMER1:
		break;

	case TIMER2:
		break;
	}
}

static void TIMER_SetOCR(TIMER_Channel_t channel, uint16__t ocrValue)
{
	switch (channel)
	{
	case TIMER0:
		OCR0_REG = ocrValue;
		break;

	case TIMER1:
		break;

	case TIMER2:
		break;
	}
}

void TIMER_PWM_Init(TIMER_Channel_t channel)
{
	switch (channel)
	{
	case TIMER0:
		DIO_voidConfig(DIO_PIN3, DIO_PORTB, DIO_OUTPUT);
		#if (PWM0_MODE == FAST_PWM0)

			SET_BIT(TCCR0_WGM00, TCCR0_REG);
			SET_BIT(TCCR0_WGM01, TCCR0_REG);


			#if (FAST_PWM0_MODE == NON_INVERTED)

					CLEAR_BIT(TCCR0_COM00, TCCR0_REG);
					SET_BIT(TCCR0_COM01, TCCR0_REG);

			#elif (FAST_PWM0_MODE == INVERTED)

					SET_BIT(TCCR0_COM00, TCCR0_REG);
					SET_BIT(TCCR0_COM01, TCCR0_REG);

			#else
				#error " 'TIMER.c' Please configure FAST_PWM0_MODE in TIMER_Config.h "
			#endif

		#elif (PWM0_MODE == PHASE_CORRECT_PWM0)

			SET_BIT(TCCR0_WGM00, TCCR0_REG);
			CLEAR_BIT(TCCR0_WGM01, TCCR0_REG);


			#if (PHASE_CORRECT0_MODE == NON_INVERTED)

					CLEAR_BIT(TCCR0_COM00, TCCR0_REG);
					SET_BIT(TCCR0_COM01, TCCR0_REG);

			#elif (PHASE_CORRECT0_MODE == INVERTED)

					SET_BIT(TCCR0_COM00, TCCR0_REG);
					SET_BIT(TCCR0_COM01, TCCR0_REG);

			#else
				#error " 'TIMER.c' Please configure PHASE_CORRECT0_MODE in TIMER_Config.h "
			#endif

		#else
			#error " 'PWM0' Please configure PWM0 mode in TIMER_Config.h "
		#endif
		break;

	case TIMER1:
		// To select mode 14
		CLEAR_BIT(TCCR1A_WGM10, TCCR1A_REG);
		SET_BIT(TCCR1A_WGM11, TCCR1A_REG);
		SET_BIT(TCCR1B_WGM12, TCCR1B_REG);
		SET_BIT(TCCR1B_WGM13, TCCR1B_REG);

		DIO_voidConfig(DIO_PIN5, DIO_PORTD, DIO_OUTPUT);

		// To select non inverted on OC1A pin
		SET_BIT(TCCR1A_COM1A1, TCCR1A_REG);
		CLEAR_BIT(TCCR1A_COM1A0, TCCR1A_REG);

		break;

	case TIMER2:
		break;
	}
}

void TIMER_PWM1_SetFrequency(uint32_t frequency_Hz)
{
	ICR1_REG = (FCPU_Hz / (frequency_Hz * PRESCALER1));
}

void TIMER_PWM_Start(TIMER_Channel_t channel)
{
	switch (channel)
	{
	case TIMER0:
		TIMER_Start(TIMER0);
		break;

	case TIMER1:
		TIMER_Start(TIMER1);
		break;

	case TIMER2:
		TIMER_Start(TIMER2);
		break;
	}
}

void TIMER_PWM_Stop(TIMER_Channel_t channel)
{
	switch (channel)
	{
	case TIMER0:
		TIMER_Stop(TIMER0);
		break;

	case TIMER1:
		TIMER_Stop(TIMER1);
		break;

	case TIMER2:
		TIMER_Stop(TIMER2);
		break;
	}
}

void TIMER_PWM_SetDutyCycle(TIMER_Channel_t channel, uint8_t dutyCycle)
{
	switch (channel)
	{
	case TIMER0:
		#if (PWM0_MODE == FAST_PWM0)

			#if (FAST_PWM0_MODE == NON_INVERTED)

				TIMER_SetOCR(TIMER0, (((dutyCycle * 256) / 100) - 1));

			#elif (FAST_PWM0_MODE == INVERTED)

				TIMER_SetOCR(TIMER0, (255 - ((dutyCycle * 256) / 100)))

			#endif

		#elif (PWM0_MODE == PHASE_CORRECT_PWM0)

			#if (PHASE_CORRECT0_MODE == NON_INVERTED)

				TIMER_SetOCR(TIMER0, ((dutyCycle * 255) / 100));

			#elif (PHASE_CORRECT0_MODE == INVERTED)

				TIMER_SetOCR(TIMER0, (255 - ((dutyCycle * 255) / 100)))

			#endif

		#endif
		break;

	case TIMER1:
		OCR1A_REG = (((dutyCycle * (ICR1_REG + 1)) / 100) - 1);
		break;

	case TIMER2:
		break;
	}
}

#if (TIMER0_MODE == NORMAL)
ISR(TIMER0_OVF_vect)
{
	static uint32_t counter = 0;
	++counter;

	if (counter == TIMER_nOVF)
	{
		CallBack0();
		TIMER_SetTCNT(TIMER0, TIMER_intialPreload);
		counter = 0;
	}
}
#elif (TIMER0_MODE == CTC)
ISR(TIMER0_COMP_vect)
{
	static uint8_t counter;
	++counter;

	if (counter == TIMER_nCompMatch)
	{
		CallBack0();
		counter = 0;
	}
}
#endif
