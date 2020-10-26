/* Author: ksham004
 * Partner(s) Name: Khuaja Shams
 * Lab Section: 023
 * Assignment: Lab #4  Exercise #2
 * Exercise Description: [optional - include for your own benefit]
 *           
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char tmpA0 = 0x00;
unsigned char tmpA1 = 0x00;
unsigned char tmpC = 0x00;

enum SM1_STATES { SM1_SMStart, SM1_Init, SM1_Wait, SM1_Press0, SM1_Press1, SM1_Reset} SM1_STATE;
void Tick_LoHi() { 
   switch(SM1_STATE) { 
      case SM1_SMStart:
         if (1) {
            SM1_STATE = SM1_Init;
         }
         break;
      case SM1_Init:
         if (1) {
            SM1_STATE = SM1_Wait;
         }
         break;
      case SM1_Wait:
         if (!tmpA0 && !tmpA1) {
            SM1_STATE = SM1_Wait;
         }
         else if (tmpA0 && !tmpA1) {
			if (tmpC < 9) {
				tmpC = tmpC + 1;
			}
            SM1_STATE = SM1_Press0;
         }
         else if (tmpA0 && tmpA1) {
            SM1_STATE = SM1_Reset;
         }
         else if (!tmpA0 && tmpA1) {
			if (tmpC > 0) {
				tmpC = tmpC - 1;
			}
            SM1_STATE = SM1_Press1;
         }
         else {
            SM1_STATE = SM1_Wait;
         }
         break;
      case SM1_Press0:
         if (tmpA0 && !tmpA1) {
            SM1_STATE = SM1_Press0;
         }
         else if (!tmpA0 && !tmpA1) {
            SM1_STATE = SM1_Wait;
         }
         else if (tmpA0 && tmpA1) {
            SM1_STATE = SM1_Reset;
         }
         else if (!tmpA0 && tmpA1) {
            SM1_STATE = SM1_Press1;
         }
         else {
            SM1_STATE = SM1_Press0;
         }
         break;
      case SM1_Press1:
         if (!tmpA0 && tmpA1) {
            SM1_STATE = SM1_Press1;
         }
         else if (tmpA0 && tmpA1) {
            SM1_STATE = SM1_Reset;
         }
         else if (tmpA0 && !tmpA1) {
            SM1_STATE = SM1_Press0;
         }
         else if (!tmpA0 && !tmpA1) {
            SM1_STATE = SM1_Wait;
	    }
         else {
            SM1_STATE = SM1_Press1;
         }
         break;
      case SM1_Reset:
         if (1) {
            SM1_STATE = SM1_Wait;
         }
         break;
      default:
         SM1_STATE = SM1_Init;
         break;
   }
   switch(SM1_STATE) { 
      case SM1_SMStart:
         
         break;
      case SM1_Init:
         tmpC = 7;
         break;
      case SM1_Wait:
         
         break;
      case SM1_Press0:
         
         break;
      case SM1_Press1:
         
         break;
      case SM1_Reset:
         tmpC = 0;
         break;
   }
}

int main(){
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0x00;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    while (1) {
		tmpA0 = PINA & 0x01;
		tmpA1 = PINA & 0x02;
		Tick_LoHi();	
		PORTC = tmpC;
    }
    return 1;
}

