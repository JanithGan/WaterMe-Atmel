#include "Variables.h"						// Variable Definitions
#include "Pins.h"							// Pin Definitions
#include "ESP8266/ESP8266_H_file.h"			// Include ESP8266 header file
#include "ADC/ADC.h"
#include <util/delay.h>

void sendDeviceData(char* _buffer, char* write_key, char* Data){
	memset(_buffer, 0, strlen(_buffer));
	sprintf(_buffer, "GET /apps/thinghttp/send_request?api_key=%s&message=%s", write_key, Data);
	ESP8266_Send(_buffer);
	Read_Data(_buffer);
	_delay_ms(2000);						// ThingSpeak server delay
}

void receiveDeviceData(int BufferLength, char* read_key){
	char _buffer[BufferLength];
	memset(_buffer, 0, BufferLength);
	sprintf(_buffer, "GET /apps/thinghttp/send_request?api_key=%s", read_key);
	ESP8266_Send(_buffer);
	Read_Data(_buffer);
	_delay_ms(600);
}

void buzzer_Init(){
	DDRD |= (1 << BUZZER);					// Make buzzer pin an output
}

void buzzer_Beep(){
	PORTD ^= (1 << BUZZER);
	_delay_ms(1000);
	PORTD ^= (1 << BUZZER);
}

int main(void)
{
	uint8_t Connect_Status;

	// Initiations
	buzzer_Init();									// Initiate Buzzer
	InitADC();
	USART_Init(9600);								// Initiate USART with 9600 baud rate
	sei();											// Start global interrupt
	while(!ESP8266_Begin());						// Begin ESP8266 
	
	buzzer_Beep();

	// Setup ESP8266
	ESP8266_WIFIMode(BOTH_STATION_AND_ACCESPOINT);	// 3 = Both (AP and STA)
	ESP8266_ConnectionMode(SINGLE);					// 0 = Single; 1 = Multi
	ESP8266_ApplicationMode(NORMAL);				// 0 = Normal Mode; 1 = Transperant Mode
	
	if(ESP8266_connected() == ESP8266_NOT_CONNECTED_TO_AP)
		ESP8266_JoinAccessPoint(SSID, PASSWORD);	// Join to AP
		
	ESP8266_Start(0, DOMAIN, PORT);					// Setup server connection
	
	while(1)
	{
		Connect_Status = ESP8266_connected();
		
		if(Connect_Status == ESP8266_NOT_CONNECTED_TO_AP)
			ESP8266_JoinAccessPoint(SSID, PASSWORD);
			
		if(Connect_Status == ESP8266_TRANSMISSION_DISCONNECTED)
			ESP8266_Start(0, DOMAIN, PORT);
		
		char value[150];
		memset(value, 0, 150);
		sprintf(value, "{\"Unit 1\":{\"moisture\":1.75,\"temperature\":%u},\"Unit 2\":{\"moisture\":0.15,\"temperature\":20},\"Unit 3\":{\"moisture\":0.05,\"temperature\":15}}", (uint16_t)ReadADC(0));
		
		char buffer[200];
		sendDeviceData(buffer, API_WRITE_KEY, value);
	}
}

