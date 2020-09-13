#include "Sensors.h"

void Read_Temp(){
	int temp = (int)ADC_Read(5);
	if((temp>0) && (temp<1024)){
		Temparature = temp / 4;
	}
}

void Read_Moisture(){
	int sum = 0;
	int count = 0; 
	
	for(int i = 0; i < NUM_MOISTURE_S; i++){
		int temp = (double)ADC_Read(i);
		if((temp>0) && (temp<1024)){
			sum = sum + temp;
			count = count + 1;
		}
	}
	Moisture = sum / (count * 4);
}