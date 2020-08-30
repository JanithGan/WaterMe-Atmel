#include "Variables.h"					// Variable Definitions
#include "Pins.h"						// Pin Definitions
#include "ESP8266/USART_RS232_H_file.h"	// Include USART header file
#include "ESP8266/ESP8266_H_file.h"		// Include ESP8266 header file
#include "Buzzer/Buzzer.h"				// Include Buzzer header file
#include "DataService/DataService.h"	// Include Data Service header file
#include <util/delay.h>

int main(void)
{
	/* Initiations */
	Buzzer_Init();					// Initiate Buzzer
	ADC_Init();						// Initiate ADC
	USART_Init(BAUD_RATE);			// Initiate USART with baud
	Data_Service_Init();			// Initiate Data Services
	
	sei();							// Start global interrupt
	while(!ESP8266_Begin());		// Check ESP8266 availability
	
	Buzzer_Beep();

	/* Setup ESP8266*/
	ESP8266_Setup();
	
	/* Loop */
	while(1)
	{
		ESP8266_Refresh();
		// Device_Data_Send();
		
		Device_Data_Receive();
		_delay_ms(1000);
		
		for (int i=0; i<= DEFAULT_BUFFER_SIZE; ++i)
		{
			USART_TxChar(SettingsBuffer[i]);						// Send each char of string till the NULL
			i++;
		}
		USART_TxChar('\n');

		// USART_SendString(_buffer);
		
		_delay_ms(1000);
		
		//_delay_ms(5000);
	}
}
