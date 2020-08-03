#ifndef BUZZER_H_
#define BUZZER_H_

#include "../Variables.h"
#include "../Pins.h"
#include <avr/io.h>
#include <util/delay.h>

void Buzzer_Init();
void Buzzer_Beep();

#endif /* BUZZER_H_ */