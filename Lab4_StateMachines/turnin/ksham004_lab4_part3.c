/* Author: ksham004
 * Partner(s) Name: Khuaja Shams
 * Lab Section: 023
 * Assignment: Lab #4  Exercise #3
 * Exercise Description: [optional - include for your own benefit]
 *           
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char tmpA = 0x00;
unsigned char tmpA0 = 0x00;
unsigned char tmpA1 = 0x00;
unsigned char tmpA2 = 0x00;
unsigned char tmpA7 = 0x00;
unsigned char tmpB = 0x00;


enum SM1_STATES { SM1_SMStart, SM1_Lock, SM1_PressA2, SM1_PressA1, SM1_Open} SM1_STATE;
void Tick_LoHi() { 
   switch(SM1_STATE) { 
      case SM1_SMStart:
         if (1) {
            SM1_STATE = SM1_Lock;
         }
         break;
      case SM1_Lock:
         if ((tmpA0 || tmpA1 || tmpA7)) {
            SM1_STATE = SM1_Lock;
         }
         else if (tmpA2) {
            SM1_STATE = SM1_PressA2;
         }
         else {
            SM1_STATE = SM1_Lock;
         }
         break;
      case SM1_PressA2:
         if (!tmpA2) {
            SM1_STATE = SM1_PressA1;
         }
         else if (tmpA2) {
            SM1_STATE = SM1_PressA2;
         }
         else if ((tmpA0 || tmpA1 || tmpA7)) {
            SM1_STATE = SM1_Lock;
         }
         else {
            SM1_STATE = SM1_PressA2;
         }
         break;
      case SM1_PressA1:
         if ((tmpA0 || tmpA2 || tmpA7)) {
            SM1_STATE = SM1_Lock;
         } 
		 else if (tmpA1) {
            SM1_STATE = SM1_Open;
         }
         else if (!tmpA) {
            SM1_STATE = SM1_PressA1;
         }
         else {
            SM1_STATE = SM1_PressA1;
         }
         break;
      case SM1_Open:
         if (tmpA7) {
            SM1_STATE = SM1_Lock;
         }
         else if (!tmpA7) {
            SM1_STATE = SM1_Open;
         }
         else {
            SM1_STATE = SM1_Open;
         }
         break;
      default:
         SM1_STATE = SM1_Lock;
         break;
   }
   switch(SM1_STATE) { 
      case SM1_SMStart:
         
         break;
      case SM1_Lock:
         tmpB = 0;
         break;
      case SM1_PressA2:
         
         break;
      case SM1_PressA1:
         
         break;
      case SM1_Open:
         tmpB = 1;
         break;
   }
}

int main(){
	DDRA = 0x00; PORTA = 0x00;
    DDRB = 0xFF; PORTB = 0x00;
   while(1){
   	    tmpA = PINA;
		tmpA0 = PINA & 0x01;
		tmpA1 = PINA & 0x02;
		tmpA2 = PINA & 0x04;
		tmpA7 = PINA & 0x80;
		
		Tick_LoHi();	
		
		PORTB = tmpB;
   }
   return 1;
}

