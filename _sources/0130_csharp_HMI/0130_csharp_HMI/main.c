/*
 * 0130_csharp_HMI.c
 *
 * Created: 2019-01-30 오전 11:24:59
 * Author : kccistc
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// 인터럽트 사용
// 현재 LED 상태
volatile int _state = 0;

ISR(INT0_vect)
{
	_state = (_state + 1) % 2;
}

void INIT_PORT(void)
{
	DDRA |= 0x01;			// LED 포트 A의 1개핀만 출력으로 설정

	DDRD &= ~0x01;			// 버튼 포트 D의 1개핀만 입력으로 설정
	PORTD |= 0x01;			// 버튼 포트 D의 PD0은 내부 풀업 저항을 사용하도록 설정
}

void INIT_INT0(void)
{
	EIMSK |= (1 << INT0);			// INT0 인터럽트 활성화
	EICRA |= (1 << ISC01);			// 하강 에지에서 인터럽트 발생
	sei();							// 전역적으로 인터럽트 허용
}

int main(void)
{
	INIT_PORT();
	INIT_INT0();

    /* Replace with your application code */
    while (1) 
    {
		// 버튼이 눌렀을때 LED 켜기 (풀업저항이기 때문에 LOW가 왔을때 처리)
		// if ((PIND & 0x01) >> 0 == 0){
		// 인터럽트로 처리
		if (_state == 1){
			PORTA = 0x01;
		}else{
			PORTA = 0x00;
		}
    }

	return 0;
}

