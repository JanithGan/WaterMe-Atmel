#include "DataService.h"

uint8_t data_array[2] = {0,0};

void Data_Service_Init(){
	memset(TempData, 0, NUM_SUB_UNITS);
	memset(MoistureData, 0, NUM_SUB_UNITS);
	memset(_buffer, 0, DEFAULT_BUFFER_SIZE);
	memset(SettingsBuffer, 0, SETTINGS_BUFFER_SIZE);
	memset(ForcedBuffer,0 ,DATA_BUFFER_SIZE);
}

void RF_Data_Get(){
	// RF Get Data
	for(int i=0;i<3;i++){
		if(nrf24_dataReady())
		{
			nrf24_getData(data_array);
			TempData[0] = data_array[0] / TEMP_CONST;
			MoistureData[0] = data_array[1] / MOIST_CONST;
			_delay_ms(10);
		}
	}
	// Get temperature and moisture data. divide by constants to scale down
}

void RF_Data_Send(){
	// RF Send Data
}

void Device_Data_Send(){
	JSON_Data_Create();
	sprintf(_buffer, "GET /apps/thinghttp/send_request?api_key=%s&message=%s", API_WRITE_KEY, DataBuffer);
	
	ESP8266_Send(_buffer);
	Read_Data(_buffer);
	_delay_ms(500);								// ThingSpeak server delay
}

void Device_Data_Receive(){
	sprintf(_buffer, "GET /apps/thinghttp/send_request?api_key=%s", API_READ_KEY);
	
	ESP8266_Send(_buffer);
	Read_Data(SettingsBuffer);
	_delay_ms(3000);								// ThingSpeak server delay
	
	// USART_SendString(_buffer);
	// strcpy(SettingsBuffer, _buffer);
	
	//for (int i = 0; _buffer[i] != '\0'; ++i) {
	//SettingsBuffer[i] = _buffer[i];
	//}
}

void Force_Data_Receive(){
	sprintf(_buffer, "GET /apps/thinghttp/send_request?api_key=%s", API_FORCE_KEY);
	
	ESP8266_Send(_buffer);
	Read_Data(_buffer);
	_delay_ms(750);								// ThingSpeak server delay
	
	char *IPD_pointer = strstr(_buffer, "+IPD,");
	
	if(IPD_pointer) {
		Buzzer_Beep();
		
		IPD_pointer+=7;		// ****
		strncpy(ForcedBuffer, IPD_pointer, 1);
		
		int status;
		sscanf(ForcedBuffer, "%d", &status);
		
		if(status == 1)
		ValveStatus[0] = 1;
		if (status == 0)
		ValveStatus[0] = 0;

		Valve_Toggle();
	}
}

//void IPD_Reader(){
//char num_of_bits[5];	// ****
//int i=0;	char temp = '0';
//
//while(temp != ':') {
//num_of_bits[i] = temp;
//temp = IPD_pointer[0];
//IPD_pointer++;
//i++;
//}
//
//int x;
//sscanf(num_of_bits, "%d", &x);
//
//char buf[5];
//sprintf(buf, "Num = %d", x);
//USART_SendString(buf);
//}