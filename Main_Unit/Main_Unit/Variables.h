#ifndef VARIABLES_H_
#define VARIABLES_H_

#include <stdio.h>						// Include standard IO library

// -------------------------------------------------Constants--------------------------------------------------------

// CPU Frequency
#define F_CPU				8000000UL	// 8MHz
#define BAUD_RATE			9600		// USART Baud Rate

// Connection Variables
#define DEFAULT_TIMEOUT		10000		// Timeout period

#define DOMAIN				"api.thingspeak.com"
#define PORT				"80"
#define API_READ_KEY		"CE0KEXTAJ7GVRUD0"
#define API_WRITE_KEY		"23ED8M8OOLB2TKH0"
#define API_FORCE_KEY		"FD6789XN4ORD88GF"

#define SSID				"Janith Dialog 4G"
#define PASSWORD			"98713893895"

// Device Parameters
#define NUM_SUB_UNITS		1
#define BUZZER_DELAY		1000

// Sensor Readings
#define TEMP_CONST 120.0				// Tune These
#define MOIST_CONST 50.2				// Tune These
#define NUM_MOISTURE_S 5				// Number of Moisture Sensors

// Buffer Sizes
#define DATA_BUFFER_SIZE		50 * NUM_SUB_UNITS 		// Data Buffer size
#define DEFAULT_BUFFER_SIZE		50 + DATA_BUFFER_SIZE	// ESP8266 Buffer size

// -----------------------------------------Global Variables---------------------------------------------------------

uint8_t Connect_Status;

double TempData[NUM_SUB_UNITS];			// Temperature Data
double MoistureData[NUM_SUB_UNITS];		// Moisture Data

char DataBuffer[DATA_BUFFER_SIZE];		// Data Buffer for JSON

char ForcedBuffer[DATA_BUFFER_SIZE];
char ReadBuffer[DEFAULT_BUFFER_SIZE];
char SettingsBuffer[DEFAULT_BUFFER_SIZE];

char _buffer[DEFAULT_BUFFER_SIZE];		// Buffer for ESP8266

int ValveStatus[NUM_SUB_UNITS];

//volatile uint8_t data_array[3] = {0,1,0};
//volatile uint8_t pot_value[0] = {0};

#endif /* VARIABLES_H_ */