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
	DDRB = 0xFF; PORTB = 0x00;
	unsigned char doorInput = 0x00;
	unsigned char lightInput = 0x00;	
	while(1) {
		doorInput  = PINA & 0x01;
		lightInput = PINA & 0x02;

		if ((doorInput == 0x01)&& (lightInput == 0x00)) {
			PORTB = 0x01;
		} else {
			PORTB = 0x00;
		}
	}
	return 0;
}
