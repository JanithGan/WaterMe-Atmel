#include "Variables.h"
#include "NRF/nRF24L01.h"
#include "DataService/DataService.h"
#include "Buzzer/Buzzer.h"
#include <util/delay.h>

int main(void)
{
	SPI_Init();
	Buzzer_Init();
	
	while (1)
	{
		nRF_Data_Send();
		_delay_ms(100);
	}
}
