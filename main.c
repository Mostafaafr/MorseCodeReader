 * Created: 1/27/2023 2:31:43 PM
 * Author : mosta
 */ 

#define F_CPU 16000000UL
#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define BAUD_RATE 9600
#define BAUD_PRESCALER (((F_CPU / (BAUD_RATE * 16UL))) - 1)
#include "uart.h"

char morse_code[5];
int morse[5] = {2, 2, 2, 2, 2};
volatile unsigned int morse_count = 0;
volatile unsigned int count = 0;
char String[25]; 
volatile int button_pressed = 1;
volatile unsigned int should_print = 0;
volatile unsigned int space_count = 0;

void print_char(int morse[]){
   if (morse[0] == 0 && morse[1] == 1 && morse[2] == 2 && morse [3] == 2 && morse [4] == 2){
       sprintf(morse_code,"A\n");
       UART_putstring(morse_code);
   }
   else if (morse[0] == 1 && morse[1] == 0 && morse[2] == 0 && morse[3] == 0 && morse [4] == 2) {
       sprintf(morse_code,"B\n");
       UART_putstring(morse_code);
   }
   else    if (morse[0] == 1 && morse[1] == 0 && morse[2] == 1 && morse [3] == 0 && morse [4] == 2) {
       sprintf(morse_code,"C\n");
       UART_putstring(morse_code);
   }
   else    if (morse[0] == 1 && morse[1] == 0 && morse[2] == 0 && morse [3] == 2 && morse [4] == 2) {
       sprintf(morse_code,"D\n");
       UART_putstring(morse_code);
   }
   else if (morse[0] == 0 && morse[1] == 2 && morse[2] == 2 && morse [3] == 2 && morse [4] == 2) {
       sprintf(morse_code,"E\n");
       UART_putstring(morse_code);
   }
   else if (morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse [3] == 0 && morse [4] == 2) {
       sprintf(morse_code,"F\n");
       UART_putstring(morse_code);
   }
   else if (morse[0] == 1 && morse[1] == 1 && morse[2] == 0 && morse [3] == 2 && morse [4] == 2){
       sprintf(morse_code,"G\n");
       UART_putstring(morse_code);
   }
   else if (morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse [3] == 0 && morse [4] == 2) {
       sprintf(morse_code,"H\n");
       UART_putstring(morse_code);
   }
   else if (morse[0] == 0 && morse[1] == 0 && morse[2] == 2 && morse [3] == 2 && morse [4] == 2) {
       sprintf(morse_code,"I\n");
       UART_putstring(morse_code);
   }
    else if (morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse [3] == 1 && morse [4] == 2) {
       sprintf(morse_code,"J\n");
       UART_putstring(morse_code);
   }
    else if (morse[0] == 1 && morse[1] == 0 && morse[2] == 1 && morse [3] == 2 && morse [4] == 2) {
       sprintf(morse_code,"K\n");
       UART_putstring(morse_code);
   }
    else if (morse[0] == 0 && morse[1] == 1 && morse[2] == 0 && morse [3] == 0 && morse [4] == 2) {
       sprintf(morse_code,"L\n");
       UART_putstring(morse_code);
   }
    else if (morse[0] == 1 && morse[1] == 1 && morse[2] == 2 && morse [3] == 2 && morse [4] == 2) {
       sprintf(morse_code,"M\n");
       UART_putstring(morse_code);
   }
    else if (morse[0] == 1 && morse[1] == 0 && morse[2] == 2 && morse [3] == 2 && morse [4] == 2) {
       sprintf(morse_code,"N\n");
       UART_putstring(morse_code);
   }
    else if (morse[0] == 1 && morse[1] == 1 && morse[2] == 1 && morse [3] == 2 && morse [4] == 2) {
       sprintf(morse_code,"O\n");
       UART_putstring(morse_code);
   }
    else if (morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse [3] == 0 && morse [4] == 2) {
       sprintf(morse_code,"P\n");
       UART_putstring(morse_code);
   }
    else if (morse[0] == 1 && morse[1] == 1 && morse[2] == 0 && morse [3] == 1 && morse [4] == 2) {
       sprintf(morse_code,"Q\n");
       UART_putstring(morse_code);
   }
    else if (morse[0] == 0 && morse[1] == 1 && morse[2] == 0 && morse [3] == 2 && morse [4] == 2) {
       sprintf(morse_code,"R\n");
       UART_putstring(morse_code);
   }
    else if (morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse [3] == 2 && morse [4] == 2) {
       sprintf(morse_code,"S\n");
       UART_putstring(morse_code);
   }
    else if (morse[0] == 1 && morse[1] == 2 && morse[2] == 2 && morse [3] == 2 && morse [4] == 2) {
       sprintf(morse_code,"T\n");
       UART_putstring(morse_code);
   }
   else if (morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse [3] == 2 && morse [4] == 2) {
       sprintf(morse_code,"U\n");
       UART_putstring(morse_code);
   }
    else if (morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse [3] == 1 && morse [4] == 2) {
       sprintf(morse_code,"V\n");
       UART_putstring(morse_code);
   }
    else if (morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse [3] == 2 && morse [4] == 2) {
       sprintf(morse_code,"W\n");
       UART_putstring(morse_code);
   }
    else if (morse[0] == 1 && morse[1] == 0 && morse[2] == 0 && morse [3] == 1 && morse [4] == 2) {
       sprintf(morse_code,"X\n");
       UART_putstring(morse_code);
   }
    else if (morse[0] == 1 && morse[1] == 0 && morse[2] == 1 && morse [3] == 1 && morse [4] == 2) {
       sprintf(morse_code,"Y\n");
       UART_putstring(morse_code);
   }
    else if (morse[0] == 1 && morse[1] == 1 && morse[2] == 0 && morse [3] == 0 && morse [4] == 2) {
       sprintf(morse_code,"Z\n");
       UART_putstring(morse_code);
   }
   else if (morse[0] == 0 && morse[1] == 1 && morse[2] == 1 && morse [3] == 1 && morse [4] == 1) {
       sprintf(morse_code,"1\n");
       UART_putstring(morse_code);
   }
   else if (morse[0] == 0 && morse[1] == 0 && morse[2] == 1 && morse [3] == 1 && morse [4] == 1) {
       sprintf(morse_code,"2\n");
       UART_putstring(morse_code);
   }
   else if (morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse [3] == 1 && morse [4] == 1) {
       sprintf(morse_code,"3\n");
       UART_putstring(morse_code);
   }
   else if (morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse [3] == 0 && morse [4] == 1) {
       sprintf(morse_code,"4\n");
       UART_putstring(morse_code);
   }
   else if (morse[0] == 0 && morse[1] == 0 && morse[2] == 0 && morse [3] == 0 && morse [4] == 0) {
       sprintf(morse_code,"5\n");
       UART_putstring(morse_code);
   }
   else if (morse[0] == 1 && morse[1] == 0 && morse[2] == 0 && morse [3] == 0 && morse [4] == 0) {
       sprintf(morse_code,"6\n");
       UART_putstring(morse_code);
   }
   else if (morse[0] == 1 && morse[1] == 1 && morse[2] == 0 && morse [3] == 0 && morse [4] == 0) {
       sprintf(morse_code,"7\n");
       UART_putstring(morse_code);
   }
   else if (morse[0] == 1 && morse[1] == 1 && morse[2] == 1 && morse [3] == 0 && morse [4] == 0) {
       sprintf(morse_code,"8\n");
       UART_putstring(morse_code);
   }
   else if (morse[0] == 1 && morse[1] == 1 && morse[2] == 1 && morse [3] == 1 && morse [4] == 0) {
       sprintf(morse_code,"9\n");
       UART_putstring(morse_code);
   }
   else if (morse[0] == 1 && morse[1] == 1 && morse[2] == 1 && morse [3] == 1 && morse [4] == 1) {
       sprintf(morse_code,"0\n");
       UART_putstring(morse_code);
   }
}

void Initialize()
{
	cli();

	DDRB &= ~(1<<DDB0); //setting input pin
	DDRB |= (1 << DDB2); // Set yellow LED as output for dashes
	DDRB |= (1 << DDB3); // Blue LED as output for dots
	
	TCCR1B |= (1<<ICES1); // Looking for rising edge
	TIFR1 |= (1<<ICF1); // necessary stuff
	TIMSK1 |= (1<<ICIE1); //Enables input capture on timer 1
	
	TCCR1A = 0x00;
	TCCR1B = 0x00;
	
	TCCR1B = (1<<CS10);
	
	TCCR1A &= ~(1 << WGM10); //start timer 1
	TCCR1A &= ~(1 << WGM11); //start timer 1
	TCCR1B &= ~(1 << WGM12); //start timer 1
	TCCR1B &= ~(1 << WGM13); //start timer 1
	
	TIMSK1 |= (1<<TOIE1); // Enable our overflow interrupt
	TIFR1 |= (1<<TOV1); // Enabling overflow interrupt
	
	UART_init(BAUD_PRESCALER);
	sei();
}
ISR(TIMER1_CAPT_vect)
	{
		button_pressed ^= 1;
		//if (button_pressed == 1){
			//
		TCCR1B ^= (1<<ICES1);
		
}

ISR(TIMER1_OVF_vect)
{
	if (button_pressed == 1){
	count += 1;
	}
	if ((PINB & (1 << PINB0)) == 0){
		//button_pressed = 0;
		space_count += 1;
		should_print = 1;
	}
}




int main(void)
{
	Initialize();
	while (1){
	//sprintf(String, "%d", space_count);
	//UART_putstring(String);
	_delay_ms(750);

	if (should_print == 1){
		if (count > 7 && count < 49){
		//sprintf(String, "dot");
		//UART_putstring(String);
        PORTB |= (1 << PORTB3);
        _delay_ms(50);
        PORTB &= ~(1 << PORTB3);
		morse[morse_count] = 0;
		morse_count += 1;
		should_print = 0;
		count = 0;}
		
		else if (count > 49 && count < 98){
		//sprintf(String, "dash");
		//UART_putstring(String);
		PORTB |= (1 << PORTB2);
		_delay_ms(50);
		PORTB &= ~(1 << PORTB2);
		morse[morse_count] = 1;
		morse_count += 1;
		should_print = 0;
		count = 0;}
		
		else if (count > 98){
		//sprintf(String, " ");
		//UART_putstring(String);
		should_print = 0; 
		count = 0;}
	}
	if (space_count > 98 && should_print == 1){
		//sprintf(String, " ");
		//UART_putstring(String);
		print_char(morse);
		morse[0] = 2;
		morse[1] = 2;
		morse[2] = 2;
		morse[3] = 2;
		morse[4] = 2;
		morse_count = 0;
		}
		space_count = 0;
		
	}
	
	}
