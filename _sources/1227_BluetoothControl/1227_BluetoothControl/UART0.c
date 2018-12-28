#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

void UART0_init(void)
{
	UBRR0H = 0x00;
	UBRR0L = 207;
	
	UCSR0A |= _BV(U2X0);
	UCSR0C |= 0x06;
	
	UCSR0B |= _BV(RXEN0);
	UCSR0B |= _BV(TXEN0);
}

void UART0_transmit(char data)
{
	while( !(UCSR0A & (1 << UDRE0)) );
	UDR0 = data;
}

unsigned char UART0_receive(void)
{
	while( !(UCSR0A & (1<<RXC0)) );
	return UDR0;
}

void UART0_print_string(char *str)
{
	for (int i = 0; str[i]; i++)
		UART0_transmit(str[i]);
}