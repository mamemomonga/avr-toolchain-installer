#include "main.h"
#include "config.h"

#include <avr/io.h> 
#include <util/delay.h>

int main(void) {

	// OSC=Int20MHz, Prescaler=None, F_CPU=20000000
	_PROTECTED_WRITE(CLKCTRL_MCLKCTRLA, CLKCTRL_CLKSEL_OSC20M_gc);
	_PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, 0);

	// OSC=Int20MHz, Prescaler=/6, F_CPU=3333333
//	_PROTECTED_WRITE(CLKCTRL_MCLKCTRLA, CLKCTRL_CLKSEL_OSC20M_gc);
//	_PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, CLKCTRL_PDIV_6X_gc | CLKCTRL_PEN_bm);

	// OSC=Int32KHz, Prescaler=None, F_CPU=32000
//	_PROTECTED_WRITE(CLKCTRL_MCLKCTRLA, CLKCTRL_CLKSEL_OSCULP32K_gc);
//	_PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, 0);

	LED_OUT;

    while (1) {
		LED_L;
		_delay_ms(500);
		LED_H;
		_delay_ms(100);
	}

    return 0;
}
