#include <msp430.h>
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
int main(void) {
	WDTCTL = WDTHOLD | WDTPW;
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;

	/* Set anodes */
	P1DIR = 0xff;
	P1OUT = BIT0 | BIT5 | BIT7 | BIT4;

	/* Set Cathodes */
	// P2DIR |= (BIT0 | BIT1 | BIT2 | BIT3);
	P2DIR = 0b00001111;
	// P2OUT &= ~(BIT0 | BIT1 | BIT2 | BIT3);
	P2OUT = 0b00000000;

	_BIS_SR(GIE | LPM1_bits);
}
