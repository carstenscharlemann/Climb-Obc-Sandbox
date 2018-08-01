/*
 * FreeRTOS Kernel V10.0.1
 * Copyright (C) 2017 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"

/* Demo application includes. */
#include "partest.h"

//#define LED_2 ( 1UL << 24UL )
//#define LED_3 ( 1UL << 25UL )
//#define LED_4 ( 1UL << 28UL )
//#define LED_5 ( 1UL << 29UL )
//
//#define partstFIO1_BITS			( LED_2 | LED_3 | LED_4 | LED_5 )
#define partstNUM_LEDS			( 3 )
//
//static unsigned long ulLEDs[] = { LED_3, LED_2, LED_5, LED_4 };


typedef struct { /* GPIO_PORT Structure */
	__IO uint32_t DIR; /*!< Offset 0x0000: GPIO Port Direction control register */
	uint32_t RESERVED0[3];__IO uint32_t MASK; /*!< Offset 0x0010: GPIO Mask register */
	__IO uint32_t PIN; /*!< Offset 0x0014: Pin value register using FIOMASK */
	__IO uint32_t SET; /*!< Offset 0x0018: Output Set register using FIOMASK */
	__IO uint32_t CLR; /*!< Offset 0x001C: Output Clear register using FIOMASK */
} LPC_GPIO_T;
#define LPC_GPIO0_BASE            0x2009C000
#define LPC_GPIO                  ((LPC_GPIO_T             *) LPC_GPIO0_BASE)

#define LED0_GPIO_PORT_NUM                      0
#define LED0_GPIO_BIT_NUM                       22

#define LED1_GPIO_PORT_NUM                      3
#define LED1_GPIO_BIT_NUM                       25

#define LED2_GPIO_PORT_NUM                      3
#define LED2_GPIO_BIT_NUM                       26

/*-----------------------------------------------------------
 * Simple parallel port IO routines.
 *-----------------------------------------------------------*/

void vParTestInitialise(void) {

	/* LEDs on port 1. */
	// LPC_GPIO1->FIODIR  = partstFIO1_BITS;
	//  Init the LED Pin as output
	LPC_GPIO[LED0_GPIO_PORT_NUM].DIR |= 1UL << LED0_GPIO_BIT_NUM;
	LPC_GPIO[LED1_GPIO_PORT_NUM].DIR |= 1UL << LED1_GPIO_BIT_NUM;
	LPC_GPIO[LED2_GPIO_PORT_NUM].DIR |= 1UL << LED2_GPIO_BIT_NUM;

	/* Start will all LEDs off. */
	// LPC_GPIO1->FIOCLR = partstFIO1_BITS;
	LPC_GPIO[LED0_GPIO_PORT_NUM].CLR |= 1UL << LED0_GPIO_BIT_NUM;
	LPC_GPIO[LED1_GPIO_PORT_NUM].CLR |= 1UL << LED1_GPIO_BIT_NUM;
	LPC_GPIO[LED2_GPIO_PORT_NUM].CLR |= 1UL << LED2_GPIO_BIT_NUM;

}
/*-----------------------------------------------------------*/

void vParTestSetLED(unsigned portBASE_TYPE uxLED, signed portBASE_TYPE xValue) {
//	if( uxLED < partstNUM_LEDS )
//	{
//		/* Set of clear the output. */
//		if( xValue )
//		{
//			LPC_GPIO1->FIOCLR = ulLEDs[ uxLED ];
//		}
//		else
//		{
//			LPC_GPIO1->FIOSET = ulLEDs[ uxLED ];
//		}
//	}
	switch (uxLED) {
	case 0:
		if (xValue) {
			LPC_GPIO[LED0_GPIO_PORT_NUM].SET |= 1UL << LED0_GPIO_BIT_NUM;
		} else {
			LPC_GPIO[LED0_GPIO_PORT_NUM].CLR |= 1UL << LED0_GPIO_BIT_NUM;
		}
		break;
	case 1:
		if (xValue) {
			LPC_GPIO[LED1_GPIO_PORT_NUM].SET |= 1UL << LED1_GPIO_BIT_NUM;
		} else {
			LPC_GPIO[LED1_GPIO_PORT_NUM].CLR |= 1UL << LED1_GPIO_BIT_NUM;
		}
		break;
	case 2:
		if (xValue) {
			LPC_GPIO[LED2_GPIO_PORT_NUM].SET |= 1UL << LED2_GPIO_BIT_NUM;
		} else {
			LPC_GPIO[LED2_GPIO_PORT_NUM].CLR |= 1UL << LED2_GPIO_BIT_NUM;
		}
		break;
	default:
		break;
	}
}
/*-----------------------------------------------------------*/

void vParTestToggleLED(unsigned portBASE_TYPE uxLED) {
	if (uxLED < partstNUM_LEDS) {

		switch (uxLED) {
			case 0:
				if (LPC_GPIO[LED0_GPIO_PORT_NUM].PIN & ( 1UL << LED0_GPIO_BIT_NUM)) {
					LPC_GPIO[LED0_GPIO_PORT_NUM].CLR |= 1UL << LED0_GPIO_BIT_NUM;
				} else {
					LPC_GPIO[LED0_GPIO_PORT_NUM].SET |= 1UL << LED0_GPIO_BIT_NUM;
				}
				break;
			case 1:
				if (LPC_GPIO[LED1_GPIO_PORT_NUM].PIN & ( 1UL << LED1_GPIO_BIT_NUM)) {
					LPC_GPIO[LED1_GPIO_PORT_NUM].CLR |= 1UL << LED1_GPIO_BIT_NUM;
				} else {
					LPC_GPIO[LED1_GPIO_PORT_NUM].SET |= 1UL << LED1_GPIO_BIT_NUM;
				}
				break;
			case 2:
				if (LPC_GPIO[LED2_GPIO_PORT_NUM].PIN & ( 1UL << LED2_GPIO_BIT_NUM)) {
					LPC_GPIO[LED2_GPIO_PORT_NUM].CLR |= 1UL << LED2_GPIO_BIT_NUM;
				} else {
					LPC_GPIO[LED2_GPIO_PORT_NUM].SET |= 1UL << LED2_GPIO_BIT_NUM;
				}
				break;
			default:
				break;
			}
	}
//		if ( LPC_GPIO1->FIOPIN & ulLEDs[uxLED]) {
//			LPC_GPIO1->FIOCLR = ulLEDs[uxLED];
//		} else {
//			LPC_GPIO1->FIOSET = ulLEDs[uxLED];
//		}
//	}
}
/*-----------------------------------------------------------*/

unsigned portBASE_TYPE uxParTextGetLED(unsigned portBASE_TYPE uxLED) {
	if (uxLED < partstNUM_LEDS) {

		switch (uxLED) {
			case 0:
				return LPC_GPIO[LED0_GPIO_PORT_NUM].PIN & ( 1UL << LED0_GPIO_BIT_NUM);
				break;
			case 1:
				return LPC_GPIO[LED1_GPIO_PORT_NUM].PIN & ( 1UL << LED1_GPIO_BIT_NUM);
				break;
			case 2:
				return LPC_GPIO[LED2_GPIO_PORT_NUM].PIN & ( 1UL << LED2_GPIO_BIT_NUM);
				break;
			default:
				return 0;
				break;
			}
	}

}
//	if (uxLED < partstNUM_LEDS) {
//		return ( LPC_GPIO1->FIOPIN & ulLEDs[uxLED]);
//	} else {
//		return 0;
//	}
//}
/*-----------------------------------------------------------*/

