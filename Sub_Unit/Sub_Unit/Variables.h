#ifndef VARIABLES_H_
#define VARIABLES_H_

// -------------------------------------------------Constants--------------------------------------------------------

// CPU Frequency
#define F_CPU				1000000UL	// 1MHz

// Sensor Readings
#define TEMP_CONST 120.0				// Tune These
#define MOIST_CONST 50.2				// Tune These
#define NUM_MOISTURE_S 5				// Number of Moisture Sensors

// Device Parameters
#define BUZZER_DELAY		1000

// -----------------------------------------Global Variables---------------------------------------------------------

float Temparature;			// Temperature Data
float Moisture;				// Moisture Data

#endif /* VARIABLES_H_ */