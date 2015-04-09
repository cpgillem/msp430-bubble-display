compile: main.c
	msp430-gcc -mmcu=msp430g2553 -g main.c alphabet.h -o main.elf

flash: main.elf
	mspdebug rf2500 'prog main.elf'
