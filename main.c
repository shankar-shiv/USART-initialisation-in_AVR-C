/* An example that shows how to use the above USART functions */

/*
 * main.c
 * Links for Further learning : 
 * 1) https://www.youtube.com/watch?v=1mmkA-m4aKU&list=PLtQdQmNK_0DRhBWYZ32BEILOykXLpJ8tP&index=21
 * 2) https://www.avrfreaks.net/forum/tut-soft-using-usart-serial-communications?page=all
 * 3) https://www.avrfreaks.net/forum/how-use-printf-uart
 * 4) https://stackoverflow.com/questions/42744280/error-unknown-type-name-file/42744341
 * Author : Shankar
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include <stdio.h>
#include "USART.h"

// ********************************************************************************
// Global Variables
// ********************************************************************************
static FILE mystdout = FDEV_SETUP_STREAM(usart_putchar_printf, NULL, _FDEV_SETUP_WRITE);

int main(void)
{
    initUSART();

	  // setup our stdio stream
	  stdout = &mystdout;
    
    uint8_t var = 10;

    while (1) 
    {
		  printf("HI %u\r\n", var);
		  _delay_ms(100);
    }
}