#include "Variables.h"

#include "ADC/ADC.h"
#include "NRF/nrf24.h"
#include "USART/USART_RS232_H_file.h"

#include "DataService/DataService.h"
#include "Sensors/Sensors.h"
#include "Buzzer/Buzzer.h"

#include <util/delay.h>
#include <string.h>
#include <stdio.h>

void ADC_test(){
	Read_Temp();
	Read_Moisture();
	
	char _buff[10];
	memset(_buff, 0, 10);
	sprintf(_buff, "%d %d \r\n", Temparature, Moisture);
	USART_SendString(_buff);
}

int main(void)
{
	Radio_Setup();
	Buzzer_Init();
	ADC_Init();
	
	while (1)
	{
		// nRF_Data_Send();
		ADC_test();
		_delay_ms(100);
	}
}
