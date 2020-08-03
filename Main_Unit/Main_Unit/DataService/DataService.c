#include "DataService.h"

void Data_Service_Init(){
	memset(TempData, 0, NUM_SUB_UNITS);
	memset(MoistureData, 0, NUM_SUB_UNITS);
	memset(_buffer, 0, DEFAULT_BUFFER_SIZE);
}

void RF_Data_Get(){
	for (int i = 0; i < NUM_SUB_UNITS; i++ ) {
		TempData[i] = 50.52 + i;					// Change This to NFC Comm
		MoistureData[i] = 10.12 + i;
	}
	MoistureData[0] = (float)ADC_Read(0);
}

void Device_Data_Send(){
	JSON_Data_Create();
	sprintf(_buffer, "GET /apps/thinghttp/send_request?api_key=%s&message=%s", API_WRITE_KEY, DataBuffer);
	
	ESP8266_Send(_buffer);
	Read_Data(_buffer);
	_delay_ms(2000);								// ThingSpeak server delay
}

//void receiveDeviceData(int BufferLength, char* read_key){
	//char _buffer[BufferLength];
	//memset(_buffer, 0, BufferLength);
	//sprintf(_buffer, "GET /apps/thinghttp/send_request?api_key=%s", read_key);
	//ESP8266_Send(_buffer);
	//Read_Data(_buffer);
	//_delay_ms(600);
//}