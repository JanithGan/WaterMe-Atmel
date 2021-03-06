#ifndef DATASERVICE_H_
#define DATASERVICE_H_

#include "../Variables.h"
#include "../ADC/ADC.h"
#include "../DataParser/DataParser.h"
#include "../ESP8266/ESP8266_H_file.h"
#include "../NRF/nrf24.h"
#include "../Valve/Valve.h"
#include "../Buzzer/Buzzer.h"
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

void Data_Service_Init();

void RF_Data_Get();
void RF_Data_Send();

void Device_Data_Send();
void Device_Data_Receive();
void Force_Data_Receive();

#endif /* DATASERVICE_H_ */