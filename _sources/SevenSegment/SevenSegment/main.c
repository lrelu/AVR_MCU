/*
 * SevenSegment.c
 *
 * Created: 2019-01-03 오후 2:28:26
 * Author : kccistc
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>  

int main(void)
{
	uint8_t number[] = {0x88, 0xEB, 0x7C, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};
	int count = 0;						// 현재 표시할 숫자
	DDRD = 0xFF;						// 제어 핀 8개를 출력으로 설정
	//DDRA = 0xFF;						// PORTA 출력 핀으로 설정

	PORTA = 0x00;

    /* Replace with your application code */
    while (1) 
    {
		PORTD = 0x88;
		//PORTD = number[count];			// 숫자 데이터 출력
		//count = (count + 1) % 10;		// 다음에 표시할 숫자

		//_delay_ms(1000);
    }

	return 0;
}