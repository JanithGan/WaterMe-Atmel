#include "SPI_Slave.h"

void SPI_Init(void)
{
	//Set MOSI, SCK, CE and CSN as output
	DDRB |= (1<<MOSI)|(1<<SCK)|(1<<CE)|(1<<CSN);
	//Set MISO pin as input
	DDRB &= ~(1<<MISO);
	//Enable SPI in master mode with Focs/16 =>>>> WRONG SUB UNIT IS A SLAVE
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
	//Disable speed doubler
	SPSR &= ~(1<<SPI2X);
	//Set CSN HIGH to start, nothing to be sent to nRF yet
	PORTB |= (1<<PB2);
	//Set CE low to start, nothing to send/receive
	PORTB &= ~(1<<PB1);
}

char WriteByteSPI(unsigned char cData)
{
	char flash_buffer;
	//Load byte to Data register
	SPDR = cData;
	//Wait for the transmission to complete
	while(!(SPSR & (1<<SPIF)));
	//Return what's received from the nRF
	flash_buffer = SPDR;
	return SPDR;
}