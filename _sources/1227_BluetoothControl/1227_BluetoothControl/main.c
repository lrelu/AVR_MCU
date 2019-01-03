#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "UART0.h"
#include "UART1.h"
#include "LCD.h"

FILE OUTPUT = FDEV_SETUP_STREAM(UART0_transmit, NULL, _FDEV_SETUP_WRITE);
FILE INPUT = FDEV_SETUP_STREAM(NULL, UART1_receive, _FDEV_SETUP_READ);

int main(void)
{
	uint8_t data;								// 스마트폰으로 부터 입력받을 변수

	LCD_TurnOn();								// LCD 출력
// LED확인을 위해 디버깅 사용
#if 0
	UART_START();								// UART 통신 준비 (UART0: PUTTY, UART1: 블루투스)
#endif 
	DDRD = 0xFF;								// D포트 LED 출력준비
	PORTD = 0x20;								// 출력 LED 초기화
	

	while(1)
	{
#if 0
		scanf("%c", &data);						// 스마트폰에서 입력 받기
		printf("%c", data);						// PUTTY로 출력
		Keyin(data);							// 입력에 따른 LCD, LED 제어
#endif 
	;
	}

	return 0;
}

void Keyin(uint8_t data)
{
	switch (data)
	{
		case 'S':						//STOP
		LCD_PRINT("STOP......");
		PORTD = 0x30;
		break;
		case 'F':						//FORWARD
		LCD_PRINT("FORWARD...");
		PORTD = 0x21;
		break;
		case'B':						//BACK
		LCD_PRINT("BACK......");
		PORTD = 0x28;
		break;
		case 'L':						//LEFT
		LCD_PRINT("LEFT......");
		PORTD = 0x22;
		break;
		case 'R':						//RIGHT
		LCD_PRINT("RIGHT.....");
		PORTD = 0x24;
		break;
		default:						//default
		PORTD = 0x00;
		break;
	}
}

void UART_START()
{
	UART0_init();
	UART1_init();

	stdout = &OUTPUT;
	stdin = &INPUT;
}

void LCD_TurnOn()
{
	LCD_init();									// 텍스트 LCD 초기화
	LCD_write_string("REMOTE CONTROL!");		// 문자열 출력
	LCD_goto_XY(1, 0);
	LCD_write_string("READY...");				// 문자열 출력
}

void LCD_PRINT(char *str)
{
	LCD_goto_XY(1, 0);
	LCD_write_string(str);				// 문자열 출력
}