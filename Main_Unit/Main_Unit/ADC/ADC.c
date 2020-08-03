#include "ADC.h"

void ADC_Init()
{
	ADMUX |= (1<<REFS0);									// Select V ref=AVcc
	ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN); 	// Set prescaller to 128 and enable ADC
}

uint16_t ADC_Read(uint8_t ADCChannel)
{
	ADMUX = (ADMUX & 0xF0) | (ADCChannel & 0x0F);			// Select ADC channel with safety mask
	ADCSRA |= (1<<ADSC);									// Single conversion mode
	while( ADCSRA & (1<<ADSC) );							// Wait until ADC conversion is complete
	return (uint16_t)ADC;
}