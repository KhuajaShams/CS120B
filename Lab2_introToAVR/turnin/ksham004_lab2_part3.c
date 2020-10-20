/*	Author: ksham004
 *  Partner(s) Name: Khuaja Shams
 *	Lab Section: 023
 *	Assignment: Lab #2  Exercise #2
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
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize as 0
	
	unsigned char tmpC = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA = 0x00;
   /* Insert your solution below */
    while (1) {
	// 1) Read input
	tmpA = PINA & 0x0F;
	unsigned char cntavail = 0x00;
	// 2) Perform computation
	unsigned int i = 0;
	while (i < 4) {
		if ((tmpA & 0x01) == 0x01) {
			cntavail = cntavail + 1;
		}
		tmpA = tmpA >> 1;
		i++;
	}
	tmpC = cntavail;
	if (cntavail == 4) {
		tmpC = tmpC + 0x80;
        }

	// 3) Write output
	PORTC = tmpC;		
    }
    return 0;
}
