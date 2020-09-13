#ifndef VARIABLES_H_
#define VARIABLES_H_

#include <stdint.h>
// -------------------------------------------------Constants--------------------------------------------------------

// CPU Frequency
#define F_CPU				1000000UL	// 1MHz
#define BAUD_RATE			9600		// USART Baud Rate

// Device Parameters
#define BUZZER_DELAY		1000
#define NUM_MOISTURE_S 5				// Number of Moisture Sensors

// -----------------------------------------Global Variables---------------------------------------------------------

uint8_t Temparature;			// Temperature ADC Data
uint8_t Moisture;				// Moisture ADC Data

#endif /* VARIABLES_H_ */