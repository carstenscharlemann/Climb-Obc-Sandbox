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

// TODO: insert other definitions and declarations here

extern "C" {
	extern int wsmain(void);
}


int main(void) {

	// Call the c code main loop
	wsmain();
}
