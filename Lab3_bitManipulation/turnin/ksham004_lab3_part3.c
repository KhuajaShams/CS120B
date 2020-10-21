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
   DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
   while(1) {
      unsigned char tmpA = PINA & 0x0F;
      unsigned char tmpB = 0x00;
      
      unsigned char ignition = 0x00;
      unsigned char seated = 0x00;
      unsigned char seatbelt = 0x00;
      
      if ((tmpA & 0x10) == 0x10) {ignition = 0x01;} 
      if ((tmpA & 0x20) == 0x20) {seated = 0x01;}
      if ((tmpA & 0x40) == 0x40) {seatbelt = 0x01;} 
      
      if (tmpA <=0) {
         tmpB = 0x00;  
      }
      else if (tmpA <= 2) {
         tmpB = 0x20;  
      }
      else if (tmpA <= 4) {
         tmpB = 0x30;
      }
      else if (tmpA <= 6) {
         tmpB = 0x38;
      }
      else if (tmpA <= 9) {
         tmpB = 0x3C;
      }
      else if (tmpA <= 12) {
         tmpB = 0x3E;
      }
      else if (tmpA <= 15) {
         tmpB = 0x3F;
      }
      else {
         tmpB = 0x00;
      }
      
      if (tmpA <= 4) {
         tmpB = tmpB | 0x40;
      }

      if (ignition && seated && !seatbelt) {
         tmpB = tmpB | 0x80;  
      }
      
      PORTC = tmpB;
   }    
 
 return 1;
}
