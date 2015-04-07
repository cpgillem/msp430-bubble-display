#include <msp430.h>
/*
 * QDSP-6064
 * 4-Digit Micro Numeric Indicator
 * (7 Segment Monolithic)
 *
 * Pinout:
 *  1:  Cathode 1
 *  2:  Anode e
 *  3:  Anode c
 *  4:  Cathode 3
 *  5:  Anode dp
 *  6:  Cathode 4
 *  7:  Anode g
 *  8:  Anode d
 *  9:  Anode f
 * 10:  Cathode 2
 * 11:  Anode b
 * 12:  Anode a
 */
int main(void) {
	WDTCTL = WDTHOLD | WDTPW;
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;

	/* Set anodes */
	P1DIR = 0xff;
	P1OUT = 0x00;

	/* Set Cathodes */
	P2DIR |= (BIT0 | BIT1 | BIT2 | BIT3);
	P2OUT &= ~(BIT0 | BIT1 | BIT2 | BIT3);

	_BIS_SR(GIE | LPM1_bits);
}
