#define F_CPU 1000000UL					// Define CPU Frequency e.g. here its Ext. 1MHz
#include <avr/io.h>						// Include AVR std. library file 
#include <util/delay.h>					// Include Delay header file 
#include <stdbool.h>					// Include standard boolean library 
#include <string.h>						// Include string library 
#include <stdio.h>						// Include standard IO library 
#include <stdlib.h>						// Include standard library 
#include <avr/interrupt.h>				// Include avr interrupt header file 
#include "USART_RS232_H_file.h"			// Include USART header file

#define SREG _SFR_IO8(0x3F)				// USART Read Reg

// -----------------------------------------------------Variables------------------------------------------------------------------------

#define DEFAULT_BUFFER_SIZE		160		// Buffer size 
#define DEFAULT_TIMEOUT			10000	// Timeout period

// Connection Mode
#define SINGLE					0
#define MULTIPLE				1

// Application Mode
#define NORMAL					0
#define TRANSPERANT				1

// WiFi Mode
#define STATION							1
#define ACCESSPOINT						2
#define BOTH_STATION_AND_ACCESPOINT		3

// Server Mode 
#define SERVERPORT			"80"
#define SERVERMODE			"1"

// AT Command Response Status
enum ESP8266_RESPONSE_STATUS{
	ESP8266_RESPONSE_WAITING,
	ESP8266_RESPONSE_FINISHED,
	ESP8266_RESPONSE_TIMEOUT,
	ESP8266_RESPONSE_BUFFER_FULL,
	ESP8266_RESPONSE_STARTING,
	ESP8266_RESPONSE_ERROR
};

// Access Point Status
enum ESP8266_JOINAP_STATUS {
	ESP8266_WIFI_CONNECTED,
	ESP8266_CONNECTION_TIMEOUT,
	ESP8266_WRONG_PASSWORD,
	ESP8266_NOT_FOUND_TARGET_AP,
	ESP8266_CONNECTION_FAILED,
	ESP8266_JOIN_UNKNOWN_ERROR
};

// Server Status
enum ESP8266_SERVER_STATUS {
	ESP8266_SERVER_CONNECTED,
	ESP8266_SERVER_ERROR	
};

// TCP/IP Connection Status
enum ESP8266_CONNECT_STATUS {
	ESP8266_CONNECTED_TO_AP,
	ESP8266_CREATED_TRANSMISSION,
	ESP8266_TRANSMISSION_DISCONNECTED,
	ESP8266_NOT_CONNECTED_TO_AP,
	ESP8266_CONNECT_UNKNOWN_ERROR
};

// ------------------------------------------------------Functions------------------------------------------------------------------------

// ESP8266 Module Setup
bool ESP8266_Begin();														// Check whether is ESP8266 ON (AT Command)
bool ESP8266_WIFIMode(uint8_t _mode);										// Set WiFi mode (STA / AP or Both)
uint8_t ESP8266_JoinAccessPoint(char* _SSID, char* _PASSWORD);				// Join to TCP access point
uint8_t ESP8266_connected();												// Check whether ESP8266 is connected to TCP access point

// AT Commands
bool SendATandExpectResponse(char* ATCommand, char* ExpectedResponse);		// Send AT command and receive the reply
bool WaitForExpectedResponse(char* ExpectedResponse);						// Wait for AT command response
void Read_Response(char* _Expected_Response);								// Read AT command response
void GetResponseBody(char* Response, uint16_t ResponseLength);				// Get AT command response body

// TCP/IP Connection
bool ESP8266_ApplicationMode(uint8_t Mode);									// Set TCP/IP application mode (Transparent / Non Transparent)
bool ESP8266_ConnectionMode(uint8_t Mode);									// Set TCP / UDP connection mode (Single / Multiple)
uint8_t ESP8266_Start(uint8_t _ConnectionNumber, char* Domain, char* Port); // Set up TCP / UDP connection
uint8_t ESP8266_Send(char* Data);											// Send TCP/IP data
int16_t ESP8266_DataAvailable();											// Check for TCP/IP data
uint8_t ESP8266_DataRead();													// Read TCP/IP data
bool ESP8266_Close();														// Close ESP8266 TCP / UDP connection

// USART Read
uint16_t Read_Data(char* _buffer);											// Read USART data and add to buffer
ISR (USART_RXC_vect);														// USART Read with Interrupts

// ---------------------------------------------------------------------------------------------------------------------------------------