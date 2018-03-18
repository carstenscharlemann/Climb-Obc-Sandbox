/*
 ===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
 ===============================================================================
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>

// Minimum imports and defines copied from .... (never mind) -> make a better project/workspace for getting NXP-LPC includes and dependencies  .....
#include <stdint.h>
#define     __IO    volatile             /*!< Defines 'read / write' permissions              */
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

int main(void) {

	//  Init the LED Pin as output
	LPC_GPIO[LED0_GPIO_PORT_NUM].DIR |= 1UL << LED0_GPIO_BIT_NUM;

	// Force the counter to be placed into memory
	volatile static int i = 0;
	// Enter an infinite loop, just incrementing a counter
	while (1) {
		i++;
		if (i % 10000 == 0) { /* Set Port */
			LPC_GPIO[LED0_GPIO_PORT_NUM].SET |= 1UL << LED0_GPIO_BIT_NUM;
		}
		if (i % 20000 == 0) {
			LPC_GPIO[LED0_GPIO_PORT_NUM].CLR |= 1UL << LED0_GPIO_BIT_NUM;
		}
	}
	return 0;
}
