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

//#define LED_PORT			          LPC_GPIO[1]
#define LED_GPIO_PORT_NUM						1
#define LED0_GPIO_BIT_NUM                      18
#define LED1_GPIO_BIT_NUM                      20
#define LED2_GPIO_BIT_NUM                      21
#define LED3_GPIO_BIT_NUM                      23

#define LED0_MASK	( 1UL << LED0_GPIO_BIT_NUM )
#define LED1_MASK	( 1UL << LED1_GPIO_BIT_NUM )
#define LED2_MASK	( 1UL << LED2_GPIO_BIT_NUM )
#define LED3_MASK	( 1UL << LED3_GPIO_BIT_NUM )


//#define LED_2 ( 1UL << 24UL )
//#define LED_3 ( 1UL << 25UL )
//#define LED_4 ( 1UL << 28UL )
//#define LED_5 ( 1UL << 29UL )
//
#define partstFIO1_BITS			( LED0_MASK | LED1_MASK | LED2_MASK | LED3_MASK )
#define partstNUM_LEDS			( 4 )



static unsigned long ulLEDs[] = { (unsigned long)(LED0_MASK), (unsigned long)(LED1_MASK),(unsigned long)( LED2_MASK),(unsigned long)(LED3_MASK) };

/*-----------------------------------------------------------
 * Simple parallel port IO routines.
 *-----------------------------------------------------------*/

void vParTestInitialise(void) {

	/* LEDs on port 1. */

	//  Init the LED Pin as output
    LPC_GPIO1->FIODIR  = partstFIO1_BITS;

	/* Start will all LEDs off. */
	LPC_GPIO1->FIOCLR = partstFIO1_BITS;

}
/*-----------------------------------------------------------*/

void vParTestSetLED(unsigned portBASE_TYPE uxLED, signed portBASE_TYPE xValue) {
	if( uxLED < partstNUM_LEDS )
	{
		/* Set of clear the output. */
		if( xValue )
		{
			LPC_GPIO1->FIOCLR = ulLEDs[ uxLED ];
		}
		else
		{
			LPC_GPIO1->FIOSET = ulLEDs[ uxLED ];
		}
	}

}
/*-----------------------------------------------------------*/

void vParTestToggleLED(unsigned portBASE_TYPE uxLED) {

	if ( LPC_GPIO1->FIOPIN & ulLEDs[uxLED]) {
		LPC_GPIO1->FIOCLR = ulLEDs[uxLED];
	} else {
		LPC_GPIO1->FIOSET = ulLEDs[uxLED];
	}

}
/*-----------------------------------------------------------*/

unsigned portBASE_TYPE uxParTextGetLED(unsigned portBASE_TYPE uxLED) {
	if (uxLED < partstNUM_LEDS) {
		return ( LPC_GPIO1->FIOPIN & ulLEDs[uxLED]);
	} else {
		return 0;
	}
}
/*-----------------------------------------------------------*/

