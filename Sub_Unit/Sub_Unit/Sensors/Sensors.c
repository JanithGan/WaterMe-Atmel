#include "Sensors.h"

void Read_Temp(){
	double temp = (double)ADC_Read(5);
	if((temp>0) && (temp<1024)){
		Temparature = temp / TEMP_CONST;
	}
}

void Read_Moisture(){
	double temp;
	
	double sum = 0;
	int count = 0; 
	
	for(int i=0; i<5; i++){
		temp = (double)ADC_Read(i);
		if((temp>0) && (temp<1024)){
			sum = sum + temp;
			count = count + 1;
		}
	}
	
	Moisture = sum / (count * MOIST_CONST);
}