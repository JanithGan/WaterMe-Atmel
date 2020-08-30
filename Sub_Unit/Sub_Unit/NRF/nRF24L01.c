#include "nRF24L01.h"

// Reading registers in nRF
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

// Writing to the registers of nRF
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
		reg = W_REGISTER + reg;
	else
		reg = R_REGISTER + reg;
	
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


