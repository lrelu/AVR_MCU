/*
 * 0104_SevenSegment.c
 *
 * Created: 2019-01-04 오전 11:56:12
 * Author : kccistc
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int get_button_state(void)
{
	if ((PINA & 0x01) >> 0 == 1)
	{
		_delay_ms(10);
		if ((PINA & 0x01) >> 0 == 1)
			return 1;
	}

	return 0;
}

int main(void)
{
	uint8_t number[] = {0x88, 0xEB, 0x4C};
	int count = 0;
	DDRD = 0xFF;				//D포트를 출력포트로 설정
	DDRA &= ~0x01;				//A포트(PF01만)를 입력포트로 설정
	DDRC = 0xFF;				//C포트를 출력포트로 설정

	PORTD = 0x4C;
	PORTC = 0x01;

	char state_previous = 0, state_current;

    /* Replace with your application code */
    while (1) 
    {
		state_current = get_button_state();
		if (state_current == 1 && state_previous == 0)
		{
			PORTC = 0x01;
			count = ++count % 3;
		}
		else
		{
			PORTC = 0x00;
		}

		PORTD = number[count];
		state_previous = state_current;
    }

	return 0;
}

