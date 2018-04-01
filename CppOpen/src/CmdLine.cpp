/*
 * CmdLine.cpp
 *
 *  Created on: 1 Apr 2018
 *      Author: Robert
 */

#include "CmdLine.h"

#include "Board.h"


CmdLine::CmdLine() {
	// TODO Auto-generated constructor stub

}

CmdLine::~CmdLine() {
	// TODO Auto-generated destructor stub
}


void CmdLine::MainLoop() {
	char c;
	while((c = Board_UARTGetChar()) != 'x' ) {
		switch (c) {
		case 'G':
			Board_LED_Set(LED_GREEN, false);
			break;
		case 'g':
			Board_LED_Set(LED_GREEN, true);
			break;
		case 'R':
			Board_LED_Set(LED_RED, false);
			break;
		case 'r':
			Board_LED_Set(LED_RED, true);
			break;
		case 'B':
			Board_LED_Set(LED_BLUE, false);
			break;
		case 'b':
			Board_LED_Set(LED_BLUE, true);
			break;
		}

	}
}
