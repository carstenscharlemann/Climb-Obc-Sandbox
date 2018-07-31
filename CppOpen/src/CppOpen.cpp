/*
===============================================================================
 Name        : main.c
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

// TODO: insert other include files here
#include "CmdLine.h"

// TODO: insert other definitions and declarations here

int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);

    Board_UARTPutSTR("Hallo LPC (type 'm' for manuel LEDs (r/R g/G b/B) and 'x' to be back in blinking.\r");

#endif
#endif

    // TODO: insert code here

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    volatile static int l = 0 ;

    // Enter an infinite loop, just incrementing a counter
    while(1) {


    	if (Board_UARTGetChar() == 'm') {
    		CmdLine ml;// = new CmdLine();
    		ml.MainLoop();
    	}
    	i++;
        if (i % 1000000 == 0) {
        	l++;
        	if (l & 0x01) {
        		Board_LED_Set(0,false);
        	} else {
        		Board_LED_Set(0,true);
        	}
        	if (l & 0x02) {
				Board_LED_Set(1,false);
			} else {
				Board_LED_Set(1,true);
			}if (l & 0x04) {
				Board_LED_Set(2,false);
			} else {
				Board_LED_Set(2,true);
			}

        }
    }
    return 0 ;

}
