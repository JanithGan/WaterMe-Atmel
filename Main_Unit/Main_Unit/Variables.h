#ifndef VARIABLES_H_
#define VARIABLES_H_

#include <stdio.h>						// Include standard IO library

// -------------------------------------------------Constants--------------------------------------------------------

// CPU Frequency
#define F_CPU				1000000UL	// 1MHz
#define BAUD_RATE			9600		// USART Baud Rate

// Connection Variables
#define DEFAULT_TIMEOUT		10000		// Timeout period

#define DOMAIN				"api.thingspeak.com"
#define PORT				"80"
#define API_READ_KEY		"CE0KEXTAJ7GVRUD0"
#define API_WRITE_KEY		"23ED8M8OOLB2TKH0"

#define SSID				"Janith Dialog 4G"
#define PASSWORD			"98713893895"

// Device Parameters
#define NUM_SUB_UNITS		1
#define BUZZER_DELAY		1000

// Buffer Sizes
#define DATA_BUFFER_SIZE		50 * NUM_SUB_UNITS 		// Data Buffer size
#define SETTINGS_BUFFER_SIZE	50 + DATA_BUFFER_SIZE
#define DEFAULT_BUFFER_SIZE		50 + DATA_BUFFER_SIZE	// ESP8266 Buffer size

// -----------------------------------------Global Variables---------------------------------------------------------

uint8_t Connect_Status;

float TempData[NUM_SUB_UNITS];			// Temperature Data
float MoistureData[NUM_SUB_UNITS];		// Moisture Data

char DataBuffer[DATA_BUFFER_SIZE];		// Data Buffer for JSON
char SettingsBuffer[SETTINGS_BUFFER_SIZE];
char _buffer[DEFAULT_BUFFER_SIZE];		// Buffer for ESP8266

#endif /* VARIABLES_H_ */