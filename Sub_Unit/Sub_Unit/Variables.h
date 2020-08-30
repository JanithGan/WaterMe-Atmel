#ifndef VARIABLES_H_
#define VARIABLES_H_

// -------------------------------------------------Constants--------------------------------------------------------

// CPU Frequency
#define F_CPU				1000000UL	// 1MHz

// Device Parameters
#define BUZZER_DELAY		1000
#define NUM_MOISTURE_S 5				// Number of Moisture Sensors

// -----------------------------------------Global Variables---------------------------------------------------------

int Temparature;			// Temperature ADC Data
int Moisture;				// Moisture ADC Data

#endif /* VARIABLES_H_ */