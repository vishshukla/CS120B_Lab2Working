/*	Author: vshuk003
 *  Partner(s) Name: Nicole Nguyen
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
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char cntavail = 0x00;
	unsigned char firstSpot = 0x00;
	unsigned char secondSpot = 0x00;
	unsigned char thirdSpot = 0x00;
	unsigned char fourthSpot = 0x00;

	while(1) {
		firstSpot = PINA & 0x01; 
      		secondSpot = PINA & 0x02;
      		thirdSpot = PINA & 0x04;
      		fourthSpot = PINA & 0x08;
      		// shift all the bits so we can just add them up
      		secondSpot = secondSpot >> 1;
      		thirdSpot = thirdSpot >> 2;
      		fourthSpot = fourthSpot >> 3;
     		// add up all the spots 
      		cntavail = firstSpot + secondSpot + thirdSpot + fourthSpot;	
      		PORTC = 0x04 - cntavail;
    	}
	return 0;
}
