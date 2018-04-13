#include "board.h"

// For using newlib (C++ Project) we have to override _write/_read to get correct UART output when linking against nohost library!

int _write (int fd, const void *buf, size_t count)
{
  int i;
  for (i=0; i<count; i++){
	  Board_UARTPutChar(((char*)buf)[i]);
  }
  return i;
}

int _read (int fd, const void *buf, size_t count)
{
	int i = 0;
	char c = ' ';
	while ((c != '\n') && i<count){
		c = Board_UARTGetChar();
		if (c != (char)EOF) {
			((char *)buf)[i++] = c;
		}
	}
	return i;
}

