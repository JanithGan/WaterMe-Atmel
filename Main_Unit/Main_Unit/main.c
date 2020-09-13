#include "Variables.h"					// Variable Definitions
#include "Pins.h"						// Pin Definitions

#include "ESP8266/USART_RS232_H_file.h"	// Include USART header file
#include "ESP8266/ESP8266_H_file.h"		// Include ESP8266 header file
#include "NRF/nrf24.h"

#include "Buzzer/Buzzer.h"				// Include Buzzer header file
#include "Valve/Valve.h"				// Include Valve Control header file
#include "DataService/DataService.h"	// Include Data Service header file

#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	/* Initiations */
	Buzzer_Init();					// Initiate Buzzer
	ADC_Init();						// Initiate ADC
	Valve_Init();					// Initiate Valve Control

	USART_Init(BAUD_RATE);			// Initiate USART with baud
	Data_Service_Init();			// Initiate Data Services
	
	sei();							// Start global interrupt
	while(!ESP8266_Begin());		// Check ESP8266 availability
	Buzzer_Beep();
	
	/* Setup NRF */
	Radio_Setup();
	Buzzer_Beep();

	/* Setup ESP8266*/
	ESP8266_Setup();
	
	/* Loop */
	while(1)
	{
		ESP8266_Refresh();
		Force_Data_Receive();
		Device_Data_Send();
	}
}


//******************************test_junk************************************
//for (int i=0; i<= DEFAULT_BUFFER_SIZE; ++i)
//{
//USART_TxChar(SettingsBuffer[i]);	// Send each char of string till the NULL
//i++;
//}
//USART_TxChar('\n');
//
//USART_SendString(_buffer);
//
//_delay_ms(1000);
//
//_delay_ms(5000);
//
//ValveStatus[0]= 1;
//Valve_Toggle();
//_delay_ms(1000);
//
//ValveStatus[0]= 0;
//Valve_Toggle();
//_delay_ms(1000);