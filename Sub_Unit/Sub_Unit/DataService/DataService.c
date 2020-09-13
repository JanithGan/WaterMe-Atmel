#include "DataService.h"

uint8_t data_array[2] = {0,0};

void sendBytes(){
	data_array[0]=Temparature;
	data_array[1]=Moisture;

	nrf24_send(data_array);
	while(nrf24_isSending()) { /* */ }
	
	// uint8_t status;
	// status = nrf24_lastMessageStatus();
	// if(status == NRF24_TRANSMISSON_OK) {setLights(1,0);}
	// else if(status == NRF24_MESSAGE_LOST) {setLights(0,1);}
}

void nRF_Data_Send(){
	Read_Temp();
	Read_Moisture();
	sendBytes();
	// Send moisture and temp integers to SPI Master
}