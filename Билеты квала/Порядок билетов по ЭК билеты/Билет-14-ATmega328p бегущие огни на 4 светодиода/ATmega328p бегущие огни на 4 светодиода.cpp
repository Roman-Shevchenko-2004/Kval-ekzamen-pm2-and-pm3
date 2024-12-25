#define F_CPU 1000000Ul
#include <avr/io.h>
//#include <avr/delay.h>
#include <util/delay.h>

int main()
{
	DDRD = 0b00001111;
	PORTD = 0b00000000;
	int i;
	while (1)
	{
		for (i = 0; i<4; i++)
		{
			PORTD |= (1 << i);
			_delay_ms(500);
			PORTD &= ~(1 << i);
			_delay_ms(500);
		}

		for (i = 3; i>-1; i--)
		{
			PORTD |= (1 << i);
			_delay_ms(500);
			PORTD &= ~(1 << i);
			_delay_ms(500);
		}
	}
}