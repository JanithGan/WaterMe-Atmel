#include "Adc.h"

void InitADC()
{
	ADMUX |= (1<<REFS0);									// Select Vref=AVcc
	ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN); 	// Set prescaller to 128 and enable ADC
}
uint16_t ReadADC(uint8_t ADCchannel)
{
	ADMUX = (ADMUX & 0xF0) | (ADCchannel & 0x0F);			// Select ADC channel with safety mask
	ADCSRA |= (1<<ADSC);									// Single conversion mode
	while( ADCSRA & (1<<ADSC) );							// Wait until ADC conversion is complete
	return ADC;
}