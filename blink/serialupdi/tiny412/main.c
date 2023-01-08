#include "main.h"
#include "config.h"

int main(void) {
	// 16/20 MHz internal oscillator
	// _PROTECTED_WRITE(CLKCTRL_MCLKCTRLA, 0);

	// Prescaler Division: 2
	_PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, 0);

	LED_OUT;

    while (1) {
		LED_L;
		_delay_ms(100);
		LED_H;
		_delay_ms(50);
	}

    return 0;
}
