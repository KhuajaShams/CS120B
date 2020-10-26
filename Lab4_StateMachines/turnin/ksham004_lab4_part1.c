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
unsigned char tmpA = 0x00;
unsigned char tmpB = 0x00;

enum SM1_STATES { SM1_SMStart, SM1_Init, SM1_LightB1, SM1_Wait1, SM1_LightB0, SM1_Wait2} SM1_STATE;
void Tick_LoHi() { 
   switch(SM1_STATE) { 
      case SM1_SMStart:
         SM1_STATE = SM1_Init;
         break;
      case SM1_Init:
         if (tmpA) {
            SM1_STATE = SM1_LightB1;
         }
         else if (!tmpA) {
            SM1_STATE = SM1_Init;
         }
         else {
            SM1_STATE = SM1_Init;
         }
         break;
      case SM1_LightB1:
         if (tmpA) {
            SM1_STATE = SM1_LightB1;
         }
         else if (!tmpA) {
            SM1_STATE = SM1_Wait1;
         }
         else {
            SM1_STATE = SM1_LightB1;
         }
         break;
      case SM1_Wait1:
         if (!tmpA) {
            SM1_STATE = SM1_Wait1;
         }
         else if (tmpA) {
            SM1_STATE = SM1_LightB0;
         }
         else {
            SM1_STATE = SM1_Wait1;
         }
         break;
      case SM1_LightB0:
         if (tmpA) {
            SM1_STATE = SM1_LightB0;
         }
         else if (!tmpA) {
            SM1_STATE = SM1_Wait2;
         }
         else {
            SM1_STATE = SM1_LightB0;
         }
         break;
      case SM1_Wait2:
         if (!tmpA) {
            SM1_STATE = SM1_Wait2;
         }
         else if (tmpA) {
            SM1_STATE = SM1_LightB1;
         }
         else {
            SM1_STATE = SM1_Wait2;
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
		 tmpB = 0x01;
         break;
      case SM1_LightB1:
         tmpB = 0x02;
         break;
      case SM1_Wait1:
         
         break;
      case SM1_LightB0:
         tmpB = 0x01;
         break;
      case SM1_Wait2:
         
         break;
   }
}



int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0x00;
    DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
    while (1) {
	tmpA = PINA & 0x01;
	Tick_LoHi();	
	PORTB = tmpB;
    }
    return 1;
}
