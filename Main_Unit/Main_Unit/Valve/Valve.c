#include "Valve.h"

void Valve_Init()
{
	DDRC |= (1 << VALVE1);					// Make buzzer pin an output
	DDRC |= (1 << VALVE2);
	
	for (int i=0; i<NUM_SUB_UNITS; i++)
	{
		ValveStatus[i] = 0;
	}
}

void Valve_Toggle()
{
	if(ValveStatus[0] == 1)
		PORTC |= (1 << VALVE1);
		
	else
		PORTC &= ~(1 << VALVE1);
	
	// if(ValveStatus[1] == 1)
		// PORTC ^= (1 << VALVE2);
	//else
		// PORTC ^= ~(1 << VALVE2);
}