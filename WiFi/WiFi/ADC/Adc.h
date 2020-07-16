#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

void InitADC();
uint16_t ReadADC(uint8_t ADCchannel);
