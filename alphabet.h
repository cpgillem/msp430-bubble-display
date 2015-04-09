/* This is a header declaring a P1OUT configuration for each character you would want to display on the bubble display. 
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

#define C 0b10110001
#define P 0b11101001
#define G 0b10111011
