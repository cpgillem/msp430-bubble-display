#include <msp430.h>
#include "alphabet.h"

/*
 * QDSP-6064
 * 4-Digit Micro Numeric Indicator
 * (7 Segment Monolithic)
 *
 * Pinout:
 *  1:  Cathode 1: P2.0
 *  2:  Anode e: P1.0
 *  3:  Anode c: P1.1
 *  4:  Cathode 3: P2.2
 *  5:  Anode dp: P1.2
 *  6:  Cathode 4: P2.3
 *  7:  Anode g: P1.3
 *  8:  Anode d: P1.4
 *  9:  Anode f: P1.5
 * 10:  Cathode 2: P2.1
 * 11:  Anode b: P1.6
 * 12:  Anode a: P1.7

ANODES
a ---
f | | b
g ---
e | | c
d --- . dp

PINS
12 ---
9  | | 11
7  ---
2  | | 3
8  --- . 5

Project Specific Pinout - MSP430 Side
1.7 ---        Cathode 1: 2.0
1.5 | | 1.6    Cathode 2: 2.1
1.3 ---        Cathode 3: 2.2
1.0 | | 1.1    Cathode 4: 2.3
1.4 --- . 1.2

 */

/* Define positions for a character */
#define POS_1 0b00000111
#define POS_2 0b00001011
#define POS_3 0b00001101
#define POS_4 0b00001110

int main(void) {
	WDTCTL = WDTHOLD | WDTPW;
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;

	/* Set anodes */
	P1DIR = 0xff;
	P1OUT = G;

	/* Set Cathodes */
	// P2DIR |= (BIT0 | BIT1 | BIT2 | BIT3);
	P2DIR = 0b00001111;
	// P2OUT &= ~(BIT0 | BIT1 | BIT2 | BIT3);
	P2OUT = 0b00000000;

	while (1) {
		P2OUT = POS_3;
		P1OUT = C;
		__delay_cycles(100);
		P2OUT = POS_2;
		P1OUT = P;
		__delay_cycles(100);
		P2OUT = POS_1;
		P1OUT = G;
		__delay_cycles(100);
	}
}
