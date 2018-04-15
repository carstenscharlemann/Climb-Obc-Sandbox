#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here
//#include "CmdLine.h"
#include "arch/lpc_arch.h" 	//  SysTick_Enable() from lwip/arch/lpc17xx_40xx_systick_arch.c

// TODO: insert other definitions and declarations here



extern "C" {
	extern int wsmain(void);
}


/* Sets up system hardware */


void prvSetupHardware(void)
{
	/* LED0 is used for the link status, on = PHY cable detected */
	SystemCoreClockUpdate();
	Board_Init();

	/* Initial LED state is off to show an unconnected cable state */
	Board_LED_Set(0, false);
	Board_LED_Set(1, false);
	Board_LED_Set(2, false);

	/* Setup a 1mS sysTick for the primary time base */
	SysTick_Enable(1);

}


int main(void) {

	prvSetupHardware();

	// Call the c code main loop
	wsmain();
}
