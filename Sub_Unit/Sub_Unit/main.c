#include "Variables.h"
#include "NRF/nRF24L01.h"
#include <util/delay.h>

int main(void)
{
	SPI_Init();
	DDRD = 0xFF;
	
	while (1)
	{
		if (GetReg(STATUS)==0x0E)
		{
			PORTD |= (1<<0);
		}
		else
		{
			PORTD |= (1<<1);
		}
	}
}
