#include "Buzzer.h"

void Buzzer_Init()
{
	DDRD |= (1 << BUZZER);					// Make buzzer pin an output
}

void Buzzer_Beep()
{
	PORTD ^= (1 << BUZZER);
	_delay_ms(BUZZER_DELAY);
	PORTD ^= (1 << BUZZER);
}