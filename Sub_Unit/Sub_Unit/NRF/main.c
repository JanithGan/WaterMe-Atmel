/*
    TRANSMITTER - use a nrf24L01 to send data to the RX.
    Two LEDs are connected to PD6 (green) and PD7 (red) which indicate
    if the transmitted message was delivered successfully.
    The nrf24L01 [CE, CSN, SCK, MOSI, MISO] connects to [PD0, PD1, PD2, PD3, PD4]
*/

#define F_CPU 8000000UL

#include <avr/io.h>
//#include <stdint.h>
#include <util/delay.h>
#include "radioPinFunctions.h"
#include "nrf24.h"
//#include "nrf24.c"

void waitMs1(){_delay_ms(1);}
void waitMs(int ms){while (ms-->0){waitMs1();}}
void waitSec(int sec){while (sec-->0){waitMs(1000);}}

volatile uint8_t data_array[3] = {1,1,1};
volatile uint8_t pot_value[1] = {0};



void setLights(uint8_t green, uint8_t red){
    DDRC|=(1<<PORTC5)|(1<<PORTC4);
    if (green>0) {PORTC|=(1<<PORTC5);} else {PORTC &=~(1<<PORTC5);}
    if (red>0) {PORTC|=(1<<PORTC4);} else {PORTC&=~(1<<PORTC4);}
}

void ADC_init()
{
	DDRC &= ~(1<<DDC0);
	ADCSRA = 0x87;			//ADC - Enabled, Prescalar = 128
	ADMUX = 0x40;			//Vref = AVcc, ADC channel = 0
}

int ADC_Read(char channel)
{
	int Ain, AinLow;
	
	ADMUX |= (channel & 0x0F);
	ADCSRA |= (1<<ADSC);
	while((ADCSRA & (1<<ADIF)) == 0);
	
	_delay_us(10);
	AinLow = (int)ADCL;
	Ain = (int)ADCH*256;
	Ain = Ain + AinLow;
	return(Ain);
}

int main()
{


	ADC_init();    

    setLights(1,1); waitMs(500);

    while(1)
    {
        /*sendBytes(0,0,0); waitMs(500);
        sendBytes(1,0,0); waitMs(500);
        sendBytes(0,1,0); waitMs(500);
        sendBytes(0,0,1); waitMs(500);
        sendBytes(1,1,1); waitMs(500);*/
		pot_value[0] = ADC_Read(0);

		sendBytes(pot_value[0],0,0); waitMs(100);
    }
}