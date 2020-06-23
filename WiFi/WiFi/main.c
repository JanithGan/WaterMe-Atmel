#define F_CPU 1000000UL				/* Define CPU Frequency e.g. here its Ext. 12MHz */
#include <avr/io.h>
#include <util/delay.h>
#include "USART_RS232_H_file.h"		
#include "ESP8266_H_file.h"			/* Include ESP8266 header file */

int main(void)
{
	char _buffer[150];
	uint8_t Connect_Status;
	#ifdef SEND_DEMO
	uint8_t Sample = 0;
	#endif
	
	DDRD |= (1 << PD6);

	USART_Init(115200);						/* Initiate USART with 115200 baud rate */
	sei();									/* Start global interrupt */
	
	while(!ESP8266_Begin());
	
	PORTD ^= (1 << PD6);
	
	ESP8266_WIFIMode(BOTH_STATION_AND_ACCESPOINT);/* 3 = Both (AP and STA) */
	ESP8266_ConnectionMode(SINGLE);			/* 0 = Single; 1 = Multi */
	ESP8266_ApplicationMode(NORMAL);		/* 0 = Normal Mode; 1 = Transperant Mode */
	if(ESP8266_connected() == ESP8266_NOT_CONNECTED_TO_AP)
	ESP8266_JoinAccessPoint(SSID, PASSWORD);
	ESP8266_Start(0, DOMAIN, PORT);
	while(1)
	{
		Connect_Status = ESP8266_connected();
		if(Connect_Status == ESP8266_NOT_CONNECTED_TO_AP)
		ESP8266_JoinAccessPoint(SSID, PASSWORD);
		if(Connect_Status == ESP8266_TRANSMISSION_DISCONNECTED)
		ESP8266_Start(0, DOMAIN, PORT);

		#ifdef SEND_DEMO
		memset(_buffer, 0, 150);
		sprintf(_buffer, "GET /update?api_key=%s&field1=%d", API_WRITE_KEY, Sample++);
		ESP8266_Send(_buffer);
		_delay_ms(15000);	/* Thingspeak server delay */
		#endif
		
		#ifdef RECEIVE_DEMO
		memset(_buffer, 0, 150);
		sprintf(_buffer, "GET /channels/%s/feeds/last.txt", CHANNEL_ID);
		ESP8266_Send(_buffer);
		Read_Data(_buffer);
		_delay_ms(600);
		#endif
	}
}
