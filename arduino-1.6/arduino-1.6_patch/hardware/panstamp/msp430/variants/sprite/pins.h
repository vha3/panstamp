/**
 * Copyright (c) 2015 panStamp <contact@panstamp.com>
 * 
 * This file is part of the panStamp project.
 * 
 * panStamp  is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * any later version.
 * 
 * panStamp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with panStamp; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 
 * USA
 * 
 * Author: Daniel Berenguer
 * Creation date: 02/27/2015
 */

#ifndef _PINS_H
#define _PINS_H

#include <stdint.h>

#define __SPRITE_VERSION_1__  1

// Enable pseudo-pin interrupts on P3
#define __ENABLE_P3_PIN_INTERRUPTS__  1

// UART
#define pinUARTmap()      P1MAP6 = PM_UCA0TXD; P1MAP5 = PM_UCA0RXD
#define pinUARTconfig()   P1SEL |= BIT6 | BIT5      // Set P1.6 and P1.5 to USCI Mode
// I2C
#define pinI2Cmap()       P1MAP4 = PM_UCB0SDA; P1MAP7 = PM_UCB0SCL
#define pinI2Cconfig()    P1SEL |= BIT4 | BIT7      // Set P1.4 and P1.7 to USCI function
// SPI
#define pinSPImap()       P1MAP1 = PM_UCB0SIMO; P1MAP2 = PM_UCB0SOMI; P1MAP3 = PM_UCB0CLK
#define pinSPIconfig()    P1SEL |= BIT1 | BIT2 | BIT3  // Set P1.1, P1.2 and P1.3 to USCI function

#define NOT_A_PORT 0
#define NOT_A_PIN 0
#define NOT_ON_TIMER 0
#define NOT_ON_ADC 0xFF

// Ports
enum{
  P1 = 1,
  P2,
  P3,
  PJ
};

// Timers
enum{
  T0A0,
  T0A1,
  T0A2,
  T0A3,
  T0A4,
  T1A0,
  T1A1,
  T1A2
};

// ADC channels
static const uint8_t A0 = 8;
static const uint8_t A1 = 9;
static const uint8_t A2 = 10;
static const uint8_t A3 = 11;
static const uint8_t A4 = 12;
static const uint8_t A5 = 13;        // Connected to NTC
static const uint8_t A10 = 128 + 10; // special. This is the internal temp sensor
static const uint8_t A11 = 128 + 11; // special. This is Vcc/2

// On-board LED
#define ONBOARD_LED 5
#define LED      ONBOARD_LED
#define INIT_ONBOARD_LED()    P1DIR |= BIT6; P1OUT &= ~BIT6
// Acc INT pin
#define ACC_INT 3
// Acc power pin
#define ACC_POWER_PIN 21
#define INIT_ACC_POWER()     P3DIR |= BIT7; P3OUT &= ~BIT7
// Preferred analog pin to measure battery voltage
#define BATT_VOLT_PIN   A0
// NTC power pin
#define NTC_POWER_PIN   20
// NTC ADC pin
#define NTC_PIN    A5
// ADC resolution
#define ADC_RESOLUTION  0xFFF

//                      +---\/---+
//         (A2)  P2.2  1|        |48  P2.3  (A3)
//         (A1)  P2.1  2|        |47  P2.4  (A4)
//         (A0)  P2.0  3|        |46  P2.5  (A5)
//               P1.7  4|        |45  AVCC
//               P1.6  5|        |44  P5.0/XIN
//               P1.5  6|        |43  P5.1/XOUT
//               VCORE 7|        |42  AVSS
//               DVCC  8|        |41  DVCC
//               P1.4  9|        |40  RST
//               P1.3 10|        |39  TEST
//               P1.2 11|        |38  PJ.3
//               P1.1 12|        |37  PJ.2
//               P1.0 13|        |36  PJ.1
//               P3.7 14|        |35  PJ.0
//               P3.6 15|        |34  GUARD
//               P3.5 16|        |33  RBIAS
//               P3.4 17|        |32  AVCCRF
//               P3.3 18|        |31  AVCCRF
//               P3.2 19|        |30  RFN
//               P3.1 20|        |29  RFP
//               P3.0 21|        |28  AVCCRF
//               DVCC 22|        |27  AVCCRF
//               P2.7 23|        |26  RFXOUT
//               P2.6 24|        |25  RFXIN
//                      +--------+
//


//#ifdef ARDUINO_MAIN
const uint16_t digital_pin_to_pmap[] = {
	(uint16_t) &P1MAP0, 
	(uint16_t) &P1MAP1,
  (uint16_t) &P1MAP2,
  (uint16_t) &P1MAP3,
  (uint16_t) &P1MAP4,
  (uint16_t) &P1MAP7,
  (uint16_t) &P1MAP6,
  (uint16_t) &P1MAP5,
	(uint16_t) &P2MAP0,
  (uint16_t) &P2MAP1,
  (uint16_t) &P2MAP2,
  (uint16_t) &P2MAP3,
  (uint16_t) &P2MAP4,
  (uint16_t) &P2MAP5,
  (uint16_t) &P2MAP6,
  (uint16_t) &P2MAP7,
	(uint16_t) &P3MAP0,
  (uint16_t) &P3MAP1,
  (uint16_t) &P3MAP2,
	NOT_A_PIN,
  (uint16_t) &P3MAP6,
  (uint16_t) &P3MAP7
};

const uint16_t port_to_input[] = {
	NOT_A_PORT,
	(uint16_t) &P1IN,
	(uint16_t) &P2IN,
	(uint16_t) &P3IN,
	(uint16_t) &PJIN
};

const uint16_t port_to_output[] = {
	NOT_A_PORT,
	(uint16_t) &P1OUT,
	(uint16_t) &P2OUT,
	(uint16_t) &P3OUT,
	(uint16_t) &PJOUT
};

const uint16_t port_to_dir[] = {
	NOT_A_PORT,
	(uint16_t) &P1DIR,
	(uint16_t) &P2DIR,
	(uint16_t) &P3DIR,
	(uint16_t) &PJDIR
};

const uint16_t port_to_ren[] = {
	NOT_A_PORT,
	(uint16_t) &P1REN,
	(uint16_t) &P2REN,
	(uint16_t) &P3REN,
	(uint16_t) NOT_A_PORT  //No PJREN
};

const uint16_t port_to_sel[] = {
	NOT_A_PORT,
	(uint16_t) &P1SEL,
	(uint16_t) &P2SEL,
	(uint16_t) &P3SEL,
	(uint16_t) NOT_A_PORT  // No PJSEL,
};

const uint16_t port_to_pmap[] = {
	NOT_A_PORT,	/* PMAP starts at port P1 */
	(uint16_t) &P1MAP0,
	(uint16_t) &P2MAP0,
	(uint16_t) &P3MAP0,
	NOT_A_PORT  // No PJMAP0
};

const uint8_t digital_pin_to_timer[] = {
	NOT_ON_TIMER, /* P1.0 */
	T0A0,         /* P1.1 - note: A0 output cannot be used with analogWrite */
	T0A1,         /* P1.2 */
	T0A2,         /* P1.3 */
	T0A3,         /* P1.4 */
	T0A4,         /* P1.7 */
	NOT_ON_TIMER, /* P1.6 */
	NOT_ON_TIMER, /* P1.5 */
	NOT_ON_TIMER, /* P2.0 */
	NOT_ON_TIMER, /* P2.1 */
	NOT_ON_TIMER, /* P2.2 */
	NOT_ON_TIMER, /* P2.3 */
	NOT_ON_TIMER, /* P2.4 */
	NOT_ON_TIMER, /* TEMPSENSOR */
	NOT_ON_TIMER, /* P2.6 */
	NOT_ON_TIMER, /* P2.7 */
	T1A0,         /* P3.0 - note: A0 output cannot be used with analogWrite */
	T1A1,         /* P3.1 */
	T1A2,         /* P3.2 */
	NOT_ON_TIMER, /* PJ.1 -> ONBOARD_LED */
  NOT_ON_TIMER, /* P3.6 -> Acc INT pin */
  NOT_ON_TIMER  /* P3.7 -> Acc power pin */
};

const uint8_t digital_pin_to_port[] = {
	P1,           /* P1.0 */
	P1,           /* P1.1 */
	P1,           /* P1.2 */
	P1,           /* P1.3 */
	P1,           /* P1.4 */
	P1,           /* P1.7 */
	P1,           /* P1.6 */
	P1,           /* P1.5 */
	P2,           /* P2.0 */
	P2,           /* P2.1 */
	P2,           /* P2.2 */
	P2,           /* P2.3 */
	P2,           /* P2.4 */
	P2,           /* P2.5 -> NTC ADC pin */
	P2,           /* P2.6 */
	P2,           /* P2.7 */
	P3,           /* P3.0 */
	P3,           /* P3.1 */
	P3,           /* P3.2 */
	PJ,           /* PJ.1 -> ONBOARD_LED */
	P3,           /* P3.6 -> NTC power pin */
	P3            /* P3.7 -> Acc power pin */
};

const uint8_t digital_pin_to_bit_mask[] = {
	BIT0,        /* P1.0 */
	BIT1,        /* P1.1 */
	BIT2,        /* P1.2 */
	BIT3,        /* P1.3 */
	BIT4,        /* P1.4 */
	BIT7,        /* P1.7 */
	BIT6,        /* P1.6 */
	BIT5,        /* P1.5 */
	BIT0,        /* P2.0 */
	BIT1,        /* P2.1 */
	BIT2,        /* P2.2 */
	BIT3,        /* P2.3 */
	BIT4,        /* P2.4 */
	BIT5,        /* P2.5 -> NTC ADC pin */
	BIT6,        /* P2.6 */
	BIT7,        /* P2.7 */
	BIT0,        /* P3.0 */
	BIT1,        /* P3.1 */
	BIT2,        /* P3.2 */
	BIT1,        /* PJ.1 -> ONBOARD_LED */
	BIT6,        /* P3.6 -> NTC power pin */
	BIT7         /* P3.7 -> Acc power pin */
};

const uint16_t digital_pin_to_analog_in[] = {
	NOT_ON_ADC,   /* P1.0 */
	NOT_ON_ADC,   /* P1.1 */
	NOT_ON_ADC,   /* P1.2 */
	NOT_ON_ADC,   /* P1.3 */
	NOT_ON_ADC,   /* P1.4 */
	NOT_ON_ADC,   /* P1.7 */
	NOT_ON_ADC,   /* P1.6 */
	NOT_ON_ADC,   /* P1.5 */
	0,            /* P2.0 */
	1,            /* P2.1 */
	2,            /* P2.2 */
	3,            /* P2.3 */
	4,            /* P2.4 */
	5,            /* P2.5 -> NTC ADC pin */
	NOT_ON_ADC,   /* P2.6 */
	NOT_ON_ADC,   /* P2.7 */
	NOT_ON_ADC,   /* P3.0 */
	NOT_ON_ADC,   /* P3.1 */
	NOT_ON_ADC,   /* P3.2 */
	NOT_ON_ADC,   /* PJ.1 -> ONBOARD_LED */
	NOT_ON_ADC,   /* P3.6 -> NTC power pin */
	NOT_ON_ADC    /* P3.7 -> Acc power pin */
};

#endif
