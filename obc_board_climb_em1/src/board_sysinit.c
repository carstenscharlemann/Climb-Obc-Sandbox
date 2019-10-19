/*
 * @brief NXP LPC1769 LPCXpresso Sysinit file
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2013
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "board.h"

/* The System initialization code is called prior to the application and
   initializes the board for run-time operation. Board initialization
   includes clock setup and default pin muxing configuration. */

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

/* Pin muxing configuration */
STATIC const PINMUX_GRP_T pinmuxing[] = {
	// UARTS
	{0,  2,   IOCON_MODE_INACT | IOCON_FUNC1},	/* TXD0 - UART SP-D	Y+ */
	{0,  3,   IOCON_MODE_INACT | IOCON_FUNC1},	/* RXD0 - UART SP-D Y+ */
	{2,  0,   IOCON_MODE_INACT | IOCON_FUNC2},	/* TXD1 - UART SP-C X- */
	{2,  1,   IOCON_MODE_INACT | IOCON_FUNC2},	/* RXD1 - UART SP-C X- */
	{2,  8,   IOCON_MODE_INACT | IOCON_FUNC2},	/* TXD2 - UART SP-B Y- */
	{2,  9,   IOCON_MODE_INACT | IOCON_FUNC2},	/* RXD2 - UART SP-B Y- */
	{0,  0,   IOCON_MODE_INACT | IOCON_FUNC2},	/* TXD3 - UART SP-A X+ */
	{0,  1,   IOCON_MODE_INACT | IOCON_FUNC2},	/* RXD3 - UART SP-A X+ */

	// LEDS
	{2,  6,  IOCON_MODE_INACT | IOCON_FUNC0},	/* Led 4 Blue - also RGB LED Pin */
	{1, 18,  IOCON_MODE_INACT | IOCON_FUNC0},	/* Led 1 green - Watchdog Feed   */


};

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/* Sets up system pin muxing */
void Board_SetupMuxing(void)
{
	Chip_IOCON_SetPinMuxing(LPC_IOCON, pinmuxing, sizeof(pinmuxing) / sizeof(PINMUX_GRP_T));
}

/* Setup system clocking */
void Board_SetupClocking(void)
{
	Chip_SetupXtalClocking();

	/* Setup FLASH access to 4 clocks (100MHz clock) */			// ??? ok for OBC ???
	Chip_SYSCTL_SetFLASHAccess(FLASHTIM_100MHZ_CPU);
}

/* Set up and initialize hardware prior to call to main */
void Board_SystemInit(void)
{
	Board_SetupMuxing();
	Board_SetupClocking();
}
