#include "main.h"

#define LED_bp 2 // PA2
#define LED_bm (1<<LED_bp)

int main(void) {
	// 16/20 MHz internal oscillator
	// _PROTECTED_WRITE(CLKCTRL_MCLKCTRLA, 0);

	// Prescaler Division: 2
	_PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, 0);

	// Port Configuration
	PORTA.DIRSET = LED_bm; // equals PORTA.DIR |= LED_bm;
	PORTA.OUTCLR = LED_bm; // equals PORTA.OUT &= ~LED_bm;

    while (1) {
        // Blinking the LED 
        _delay_ms(100);
        if(PORTA.OUT & LED_bm){
			PORTA.OUTCLR = LED_bm;  
        } else {
			PORTA.OUTSET = LED_bm;
		}
	}

    return 0;
}
