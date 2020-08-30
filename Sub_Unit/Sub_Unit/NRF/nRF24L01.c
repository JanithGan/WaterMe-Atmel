#include "nRF24L01.h"						// Include NRF Header File

void SPI_Init(void)
{
	//Set MOSI, SCK, CE and CSN as output
	DDRB |= (1<<MOSI)|(1<<SCK)|(1<<CE)|(1<<CSN);
	//Set MISO pin as input
	DDRB &= ~(1<<MISO);
	//Enable SPI in master mode with Focs/16
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

//Reading registers in nRF
uint8_t GetReg(uint8_t reg)
{
	_delay_us(10);
	//Set CSN LOW, nRF starts to listen for command
	PORTB &= ~(1<<PB2);
	_delay_us(10);
	//R_REGISTER = set the nRF to reading mode
	WriteByteSPI(R_REGISTER | (REGISTER_MASK & reg));
	//PORTD |= (1<<0);
	_delay_us(10);
	//Send the dummy byte once to receive back the first byte in reg
	uint8_t ret;
	ret = WriteByteSPI(NOP);
	//PORTD |= (1<<1);
	_delay_us(10);
	//Set CSN HIGH
	PORTB |= (1<<PB2);
	//PORTD &= ~(1<<0);
	//Return the read register
	return ret;
}

//Writing to the registers of nRF
void WriteToNrf(uint8_t reg, uint8_t Package)
{
	_delay_us(10);
	//Set CSN LOW, nRF starts to listen for command
	PORTB &= ~(1<<PB2);
	_delay_us(10);
	//R_REGISTER = set the nRF to reading mode
	WriteByteSPI(W_REGISTER + reg);
	//PORTD |= (1<<0);
	_delay_us(10);
	//Send the dummy byte once to receive back the first byte in reg
	WriteByteSPI(Package);
	//PORTD |= (1<<1);
	_delay_us(10);
	//Set CSN HIGH
	PORTB |= (1<<PB2);
}

uint8_t *WritetoNRF(uint8_t ReadWrite, uint8_t reg, uint8_t *val, uint8_t antVal)
{
	if (ReadWrite == W)
	{
		reg = W_REGISTER + reg;
	}
	else
	{
		reg = R_REGISTER + reg;
	}
	
	static uint8_t ret[32];
	
	_delay_us(10);
	PORTB &= ~(1<<2);
	_delay_us(10);
	WriteByteSPI(reg);
	_delay_us(10);
	
	int i;
	for (i=0; i<antVal; i++)
	{
		if (ReadWrite == R && reg != W_TX_PAYLOAD)
		{
			ret[i] = WriteByteSPI(NOP);
			_delay_us(10);
		} 
		else
		{
			WriteByteSPI(val[i]);
			_delay_us(10);
		}
	}
	
	PORTB |= (1<<2);
	
	return ret;
}

void reset(void)
{
	_delay_us(10);
	PORTB &= ~(1<<2);
	_delay_us(10);
	WriteByteSPI(W_REGISTER + STATUS);
	_delay_us(10);
	WriteByteSPI(0x70);
	_delay_us(10);
	PORTB |= (1<<2);
}


