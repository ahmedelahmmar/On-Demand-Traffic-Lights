/*
 * TIMER_Private.h
 *
 *  Created on: Oct 1, 2022
 *      Author: 4hmed
 */

#ifndef SOURCES_1_MCAL_TIMER_TIMER_PRIVATE_H_
#define SOURCES_1_MCAL_TIMER_TIMER_PRIVATE_H_

#define TCCR0_REG               (*(volatile uint8_t*)0x53)
#define TCNT0_REG               (*(volatile uint8_t*)0x52)
#define OCR0_REG                (*(volatile uint8_t*)0x5C)

#define TCNT1_REG				(*(volatile uint16__t*)0x4C)
#define TCCR1A_REG              (*(volatile uint8_t*)0x4F)
#define TCCR1B_REG              (*(volatile uint8_t*)0x4E)
#define ICR1_REG                (*(volatile uint16__t*)0x46)
#define OCR1A_REG              	(*(volatile uint16__t*)0x4A)
#define OCR1B_REG              	(*(volatile uint16__t*)0x48)

#define TIMSK_REG               (*(volatile uint8_t*)0x59)

#define TIMSK_OCIE2				7
#define TIMSK_TOIE2				6
#define TIMSK_TICIE1			5
#define TIMSK_OCIE1A			4
#define TIMSK_OCIE1B			3
#define TIMSK_TOIE1				2
#define TIMSK_OCIE0				1
#define TIMSK_TOIE0				0

#define TCCR0_FOC0				7
#define TCCR0_WGM00				6
#define TCCR0_COM01				5
#define TCCR0_COM00				4
#define TCCR0_WGM01				3
#define TCCR0_CS02				2
#define TCCR0_CS01				1
#define TCCR0_CS00				0

#define TCCR1A_COM1A1			7
#define TCCR1A_COM1A0			6
#define TCCR1A_COM1B1			5
#define TCCR1A_COM1B0			4
#define TCCR1A_FOC1A			3
#define TCCR1A_FOC1B			2
#define TCCR1A_WGM11			1
#define TCCR1A_WGM10			0

#define TCCR1B_ICNC1			7
#define TCCR1B_ICES1			6
#define TCCR1B_WGM13			4
#define TCCR1B_WGM12			3
#define TCCR1B_CS12				2
#define TCCR1B_CS11				1
#define TCCR1B_CS10 			0


#endif /* SOURCES_1_MCAL_TIMER_TIMER_PRIVATE_H_ */
