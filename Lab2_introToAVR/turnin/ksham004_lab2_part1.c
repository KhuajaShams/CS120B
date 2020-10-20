/*	Author: ksham004
 *  Partner(s) Name: Khuaja Shams
 *	Lab Section: 023
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0x00; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA0 = 0x00; // Temporary variable to hold the value of A
	unsigned char tmpA1 = 0x00;
   /* Insert your solution below */
    while (1) {
	// 1) Read input
	tmpA0 = PINA & 0x01;
	tmpA1 = PINA & 0x02;
	// 2) Perform computation
	// if PA0 is 1, set PB1PB0 = 01, else = 10
	 
	if (tmpA0 && !tmpA1) { // True if PA0 is 1
		tmpB = 1; // Sets tmpB to bbbbbb01
					 // (clear rightmost 2 bits, then set to 01)
	} else {
		tmpB = 0; // Sets tmpB to bbbbbb10
					 // (clear rightmost 2 bits, then set to 10)
	}
	// 3) Write output
	 PORTB = tmpB;		
    }
    return 0;
}
