#include <avr/io.h>
#include <util/delay.h>

int main (void)
{
	DDRD = 0xFF;
	PORTD = 0x00;
	
	/*** Настройка АЦП ***/
	ADCSRA |= (1 << ADEN) // Включение АЦП
	|(1 << ADPS1)|(1 << ADPS0);    // предделитель преобразователя на 8
	ADMUX |= (0 << REFS1)|(0 << REFS0) // внешний ИОН
	|(0 << MUX0)|(0 << MUX1)|(0 << MUX2)|(0 << MUX3); // вход PC0
	
	while(1)
	{
		unsigned int u;
		ADCSRA |= (1 << ADSC);    // Начинаем преобразование
		while ((ADCSRA&(1 << ADIF))== 0); // Ждем флага окончания преобразования
		
		u = (ADCL|ADCH << 8); // Считываем  ADC
		
		if (u > 128) // 0.625V
		PORTD = 0b00000001;
		else
		PORTD = 0b00000000;
		
		if (u > 256) // 1.25V
		PORTD = 0b00000011;
		if (u > 384) // 1.875V
		PORTD = 0b00000111;
		if (u > 512) // 2.5V
		PORTD = 0b00001111;
		if (u > 640) // 3.125V
		PORTD = 0b00011111;
		if (u > 768) // 3.75V
		PORTD = 0b00111111;
		if (u > 896) // 4.375V
		PORTD = 0b01111111;
		if (u > 1020) // 5V
		PORTD = 0b11111111;
		
		_delay_ms(30);
	}
}
