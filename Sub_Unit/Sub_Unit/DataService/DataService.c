#include "DataService.h"

void nRF_Data_Send(){
	Read_Temp();
	Read_Moisture();
	// Send moisture and temp integers to SPI Master
}