/*	Author: ksham004
 *  Partner(s) Name: Khuaja Shams
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
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
   DDRA = 0x00; PORTA = 0x00;
   DDRB = 0x00; PORTB = 0x00;
   DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    while (1) {
      unsigned char tmpA = PINA;
      unsigned char tmpB = PINB;
      unsigned char cnt = 0;
      unsigned int i = 0;
      while (i < 8) {
         if ((tmpA & 0x01) == 1) {
            cnt = cnt + 1;
         }
         if ((tmpB & 0x01) == 1) {
            cnt = cnt + 1;
         }
         tmpA = tmpA >> 1;
         tmpB = tmpB >> 1;
         i++;  
      }
      PORTC = cnt;
    }
    return 1;
}
