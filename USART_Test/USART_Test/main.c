#define F_CPU 1000000UL				/* Define CPU Frequency e.g. here its Ext. 1MHz */
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
	USART_Init(9600);					/* Initiate USART with 9600 baud rate */
	// sei();							/* Start global interrupt */
	
	while (1)
	{
		USART_SendString("AT");
		USART_SendString("\r\n");
		_delay_ms(3000);
		//USART_TxChar('A');
		//char x = USART_RxChar();
		//if(x=='B'){
			//PORTD ^= (1 << PD7);
		//}
		//_delay_ms(1000);
	}
}
