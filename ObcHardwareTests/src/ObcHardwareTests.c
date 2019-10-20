/*
===============================================================================
 Name        : ObcHardwareTests.c
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

// TODO: insert other definitions and declarations here

int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
#endif
#endif

    Board_LED_Set(LED_GREEN_WD, true);		// Eine Flanke für den 1. Trigger - der HW - Power Up trigger funkt nicht richtig .....
    //Board_LED_Set(LED_GREEN_WD, true);

    Board_LED_Set(LED_BLUE, false);
	printf("Hallo Bootmode: %s [%d]\n", GetBootmodeStr(), GetBootmode());
	// Board_UARTPutSTR("Hallo\n"); // this line is exactly the same as above because
    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
        if (i % 1000000 == 0) {
        	//Board_LED_Toggle(LED_GREEN_WD);
        	Board_LED_Toggle(LED_BLUE);
        	//Board_LED_Set(LED_GREEN_WD, false);	// For ever

        	printf(".");
        }
    }
    return 0 ;
}
