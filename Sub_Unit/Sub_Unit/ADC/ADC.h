#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

void ADC_Init();						// Initialize ADC
uint16_t ADC_Read(uint8_t ADCChannel);	// Read ADC

#endif /* ADC_H_ */