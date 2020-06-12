#define F_CPU 1000000UL				/* Define CPU Frequency e.g. here its Ext. 12MHz */
#include <avr/io.h>					/* Include AVR std. library file */
#include <util/delay.h>				/* Include Delay header file */
#include <stdbool.h>				/* Include standard boolean library */
#include <string.h>					/* Include string library */
#include <stdio.h>					/* Include standard IO library */
#include <stdlib.h>					/* Include standard library */
#include <avr/interrupt.h>			/* Include avr interrupt header file */
#include "USART_RS232_H_file.h"		/* Include USART header file */

int main(void)
{
	USART_Init(115200);						/* Initiate USART with 115200 baud rate */
	sei();								/* Start global interrupt */
	DDRD |= (1 << PD6);
	
	while (1)
	{
		USART_TxChar('A');
		char x = USART_RxChar();
		if(x=='A'){
			PORTD ^= (1 << PD6);
		}
		_delay_ms(1000);	
	}
}
