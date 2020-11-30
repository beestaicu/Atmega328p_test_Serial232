/*
 * Atmega328p_test_Serial232.c
 *
 * Created: 26/05/2020 07:39:49
 * Author : hp2
 */ 
/*
 * 
 *
 * Created: 09/02/2019 19:28:06
 * Author : hp2
 */ 
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "USART_M328P.h"
char buffer[20];
volatile uint8_t StrRx_flag=0;

ISR(USART_RX_vect)
{
	buffer[10]=UDR0;         //Read USART data register
	StrRx_flag=1;        //Set String received flag
	      
}//end ISR USART

int main(void)
{
	DDRB = 0b11111111;//PB as output
	USART0Init(); // initialize usart in microcontroller
	sei(); // enable global interrupt
	USART_putstring("A"); // send string to bluetooth
	
	while (1)
	{
		if (StrRx_flag==1 ){
			StrRx_flag =0;
			PORTB |= (1<<PORTB4);
			_delay_ms(500);
			PORTB &=~ (1<<PORTB4);
		}
		
				
		
	} //END WHILE	
}//END MAIN

