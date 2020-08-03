#include "DataParser.h"

void JSON_Data_Create()
{
	RF_Data_Get();
	
	cJSON *deviceData = cJSON_CreateObject();

	for (int x = 0; x < NUM_SUB_UNITS; x++)
	{
		char subX[10];
		snprintf(subX, 10, "Unit %d", x+1);

		cJSON *subUnit = cJSON_AddObjectToObject(deviceData, subX);
		
		cJSON_AddNumberToObject(subUnit, "moisture", MoistureData[x]);
		cJSON_AddNumberToObject(subUnit, "temperature", TempData[x]);
	}
	
	cJSON_PrintPreallocated(deviceData, DataBuffer, DATA_BUFFER_SIZE, 0);
	cJSON_Delete(deviceData);

	// char* string = cJSON_PrintUnformatted(deviceData);
	// return string;
}