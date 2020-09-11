#ifndef VALVE_H_
#define VALVE_H_

#include "../Variables.h"
#include "../Pins.h"
#include <avr/io.h>
#include <util/delay.h>

void Valve_Init();
void Valve_Toggle();

#endif /* VALVE_H_ */