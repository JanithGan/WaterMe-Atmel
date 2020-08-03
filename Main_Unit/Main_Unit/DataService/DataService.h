#ifndef DATASERVICE_H_
#define DATASERVICE_H_

#include "../Variables.h"
#include "../ADC/ADC.h"
#include "../DataParser/DataParser.h"
#include "../ESP8266/ESP8266_H_file.h"
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

void Data_Service_Init();
void RF_Data_Get();
void Device_Data_Send();

#endif /* DATASERVICE_H_ */