#include "DIO.h"

void DIO_voidConfig(DIO_Pin_t pin, DIO_Port_t port, DIO_Dir_t dir)
{
	switch (port)
	{
	case DIO_PORTA:
		if (dir == DIO_INPUT)
		{
			CLEAR_BIT(pin, DIO_DDRA_REG);
		}
		else
		{
			SET_BIT(pin, DIO_DDRA_REG);
		}
		break;

	case DIO_PORTB:
		if (dir == DIO_INPUT)
		{
			CLEAR_BIT(pin, DIO_DDRB_REG);
		}
		else
		{
			SET_BIT(pin, DIO_DDRB_REG);
		}
		break;

	case DIO_PORTC:
		if (dir == DIO_INPUT)
		{
			CLEAR_BIT(pin, DIO_DDRC_REG);
		}
		else
		{
			SET_BIT(pin, DIO_DDRC_REG);
		}
		break;

	case DIO_PORTD:
		if (dir == DIO_INPUT)
		{
			CLEAR_BIT(pin, DIO_DDRD_REG);
		}
		else
		{
			SET_BIT(pin, DIO_DDRD_REG);
		}
		break;
	}
}

void DIO_voidWrite(DIO_Pin_t pin, DIO_Port_t port, DIO_Level_t level)
{
	switch (port)
	{
	case DIO_PORTA:
		if (level == DIO_HIGH)
		{
			SET_BIT(pin, DIO_PORTA_REG);
		}
		else
		{
			CLEAR_BIT(pin, DIO_PORTA_REG);
		}
		break;

	case DIO_PORTB:
		if (level == DIO_HIGH)
		{
			SET_BIT(pin, DIO_PORTB_REG);
		}
		else
		{
			CLEAR_BIT(pin, DIO_PORTB_REG);
		}
		break;

	case DIO_PORTC:
		if (level == DIO_HIGH)
		{
			SET_BIT(pin, DIO_PORTC_REG);
		}
		else
		{
			CLEAR_BIT(pin, DIO_PORTC_REG);
		}
		break;

	case DIO_PORTD:
		if (level == DIO_HIGH)
		{
			SET_BIT(pin, DIO_PORTD_REG);
		}
		else
		{
			CLEAR_BIT(pin, DIO_PORTD_REG);
		}
		break;
	}
}

void DIO_voidWritePort(uint8_t data, uint8_t mask, DIO_Port_t port)
{
	switch (port)
	{
	case DIO_PORTA:
		DIO_PORTA_REG = (DIO_PORTA_REG & mask) | data;
		break;

	case DIO_PORTB:
		DIO_PORTB_REG = (DIO_PORTB_REG & mask) | data;
		break;

	case DIO_PORTC:
		DIO_PORTC_REG = (DIO_PORTC_REG & mask) | data;
		break;

	case DIO_PORTD:
		DIO_PORTD_REG = (DIO_PORTD_REG & mask) | data;
		break;
	}
}

DIO_Level_t DIO_udtRead(DIO_Pin_t pin, DIO_Port_t port)
{
	DIO_Level_t loc_result;

	switch (port)
	{
	case DIO_PORTA:
		if (CHECK_BIT(pin, DIO_PINA_REG))
		{
			loc_result = DIO_HIGH;
		}
		else
		{
			loc_result = DIO_LOW;
		}
		break;

	case DIO_PORTB:
		if (CHECK_BIT(pin, DIO_PINB_REG))
		{
			loc_result = DIO_HIGH;
		}
		else
		{
			loc_result = DIO_LOW;
		}
		break;

	case DIO_PORTC:
		if (CHECK_BIT(pin, DIO_PINC_REG))
		{
			loc_result = DIO_HIGH;
		}
		else
		{
			loc_result = DIO_LOW;
		}
		break;

	case DIO_PORTD:
		if (CHECK_BIT(pin, DIO_PIND_REG))
		{
			loc_result = DIO_HIGH;
		}
		else
		{
			loc_result = DIO_LOW;
		}
		break;
	}
	return loc_result;
}

void DIO_voidToggle(DIO_Pin_t pin, DIO_Port_t port)
{
	switch (port)
	{
	case DIO_PORTA:
		TOGGLE_BIT(pin, DIO_PORTA_REG);
		break;

	case DIO_PORTB:
		TOGGLE_BIT(pin, DIO_PORTB_REG);
		break;

	case DIO_PORTC:
		TOGGLE_BIT(pin, DIO_PORTC_REG);
		break;

	case DIO_PORTD:
		TOGGLE_BIT(pin, DIO_PORTD_REG);
		break;
	}
}

void DIO_voidEnablePullUp(DIO_Pin_t pin, DIO_Port_t port)
{
	switch (port)
	{
	case DIO_PORTA:
		SET_BIT(pin, DIO_PORTA_REG);
		break;

	case DIO_PORTB:
		SET_BIT(pin, DIO_PORTB_REG);
		break;

	case DIO_PORTC:
		SET_BIT(pin, DIO_PORTC_REG);
		break;

	case DIO_PORTD:
		SET_BIT(pin, DIO_PORTD_REG);
		break;
	}
}
