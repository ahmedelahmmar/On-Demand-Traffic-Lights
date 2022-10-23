/*
 * DIO.h
 *
 *  Created on: Aug 26, 2022
 *      Author: 4hmed
 */

#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/BitMasking.h"
#include "../../Utilities/StandardTypes.h"

#define DIO_PINA_REG	(*(uint8_t*)0x39)
#define DIO_DDRA_REG	(*(uint8_t*)0x3A)
#define DIO_PORTA_REG 	(*(uint8_t*)0x3B)

#define DIO_PINB_REG	(*(uint8_t*)0x36)
#define DIO_DDRB_REG	(*(uint8_t*)0x37)
#define DIO_PORTB_REG	(*(uint8_t*)0x38)

#define DIO_PINC_REG	(*(uint8_t*)0x33)
#define DIO_DDRC_REG	(*(uint8_t*)0x34)
#define DIO_PORTC_REG	(*(uint8_t*)0x35)

#define DIO_PIND_REG	(*(uint8_t*)0x30)
#define DIO_DDRD_REG	(*(uint8_t*)0x31)
#define DIO_PORTD_REG	(*(uint8_t*)0x32)

typedef enum
{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD

} DIO_Port_t;

typedef enum
{
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7

} DIO_Pin_t;

typedef enum
{
	DIO_INPUT,
	DIO_OUTPUT

} DIO_Dir_t;

typedef enum
{
	DIO_LOW,
	DIO_HIGH

} DIO_Level_t;

void DIO_voidConfig(DIO_Pin_t, DIO_Port_t, DIO_Dir_t);
void DIO_voidWrite(DIO_Pin_t, DIO_Port_t, DIO_Level_t);
void DIO_voidWritePort(uint8_t, uint8_t, DIO_Port_t);
DIO_Level_t DIO_udtRead(DIO_Pin_t, DIO_Port_t);
void DIO_voidToggle(DIO_Pin_t, DIO_Port_t);
void DIO_voidEnablePullUp(DIO_Pin_t, DIO_Port_t);

#endif /* DIO_H_ */
