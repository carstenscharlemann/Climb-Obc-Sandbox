/*
===============================================================================
 Name        : BlinkForMbed1768.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>


#define LED_PORT			          LPC_GPIO[1]
#define LED_GPIO_PORT_NUM						1
#define LED0_GPIO_BIT_NUM                      18
#define LED1_GPIO_BIT_NUM                      20
#define LED2_GPIO_BIT_NUM                      21
#define LED3_GPIO_BIT_NUM                      23

#define LED0_MASK	(1UL << LED0_GPIO_BIT_NUM)
#define LED1_MASK	(1UL << LED1_GPIO_BIT_NUM)
#define LED2_MASK	(1UL << LED2_GPIO_BIT_NUM)
#define LED3_MASK	(1UL << LED3_GPIO_BIT_NUM)





// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();

    //  Init the LED Pin as output
    LED_PORT.DIR |= LED0_MASK | LED1_MASK | LED2_MASK | LED3_MASK;

#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);
#endif
#endif

    // TODO: insert code here

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
        if (i % 10000 == 0) { /* Set Port */
        		LED_PORT.SET |= 1UL << LED0_GPIO_BIT_NUM;
			}
			if (i % 20000 == 0) {
				LED_PORT.SET |= 1UL << LED1_GPIO_BIT_NUM;
			}
			if (i % 30000 == 0) { /* Set Port */
				LED_PORT.SET |= 1UL << LED3_GPIO_BIT_NUM;
			}
			if (i % 40000 == 0) {
				LED_PORT.CLR |= 1UL << LED0_GPIO_BIT_NUM;
			}
			if (i % 50000 == 0) { /* Set Port */
				LED_PORT.CLR |= 1UL << LED1_GPIO_BIT_NUM;
			}
			if (i % 60000 == 0) {
				LED_PORT.CLR |= 1UL << LED3_GPIO_BIT_NUM;
			}
    }
    return 0 ;
}


