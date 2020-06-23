#define F_CPU 1000000UL  // CPU frequency for proper time calculation in delay function

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD |= (1 << PD7);  // make PD6 an output
	PORTD ^= (1 << PD7);
	
	/* for(;;)
	{
		PORTD ^= (1 << PD7);  // toggle PD6
		_delay_ms(1000);  // delay for a second
	}*/

	return 0;  // the program executed successfully
}