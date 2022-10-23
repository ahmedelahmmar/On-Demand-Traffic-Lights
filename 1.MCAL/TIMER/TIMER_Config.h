/*
 * TIMER_CFG.h
 *
 *  Created on: Oct 1, 2022
 *      Author: 4hmed
 */

#ifndef SOURCES_1_MCAL_TIMER_TIMER_CONFIG_H_
#define SOURCES_1_MCAL_TIMER_TIMER_CONFIG_H_

// Configure your processor's speed
#define FCPU_MHz 			16
#define FCPU_Hz				16000000

/******************* PRESCALERS *********************/
// Configuration of TIMER0 prescaler. [256 - 1024]
#define PRESCALER0			1024

// Configuration of TIMER1 prescaler. [256 - 1024]
#define PRESCALER1			256

// Configuration of TIMER2 prescaler. [256 - 1024]
#define PRESCALER2			1024
/****************************************************/


/********************** MODES ***********************************/
// Configuration of TIMER0 mode of operation. [ NORMAL - CTC ]
#define TIMER0_MODE			NORMAL

// Configuration of TIMER1 mode of operation. [ NORMAL - CTC ]
#define TIMER1_MODE			NORMAL

// Configuration of TIMER2 mode of operation. [ NORMAL - CTC ]
#define TIMER2_MODE			NORMAL
/******************************************************************/

// Configuration of PWM0 mode of operation. [ FAST_PWM0 - PHASE_CORRECT_PWM0 ]
#define PWM0_MODE			PHASE_CORRECT_PWM0

// Configuration of FAST_PWM0 COM mode of operation. [ NON_INVERTED - INVERTED ]
#define FAST_PWM0_MODE		NON_INVERTED

// Configuration of PHASE_CORRECT_PWM0 COM mode of operation. [ NON_INVERTED - INVERTED ]
#define PHASE_CORRECT0_MODE	NON_INVERTED

#endif /* SOURCES_1_MCAL_TIMER_TIMER_CONFIG_H_ */
