#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <avr/io.h>

/*

ATTiny1606 20Pin SOIC300

 VDD | 1    20 | GND
 PA4 | 2    19 | PA3 EXTCLK
 PA5 | 3    18 | PA2
 PA6 | 4    17 | PA1
 PA7 | 5    16 | PA0 /RESET UPDI
 PB5 | 6    15 | PC3
 PB4 | 7    14 | PC2
 PB3 | 8    13 | PC1
 PB2 | 9    12 | PC0
 PB1 | 10   11 | PB0 LED

*/

#define LED_bm     ( 1<<0 ) // PB0
#define LED_CTRL   PORTB.PIN0CTRL |= PORT_PULLUPEN_bm | PORT_ISC_FALLING_gc
#define LED_OUT    PORTB.DIRSET = LED_bm
#define LED_IN     PORTB.DIRCLR = LED_bm
#define LED_H      PORTB.OUTSET = LED_bm
#define LED_L      PORTB.OUTCLR = LED_bm
#define LED_I      PORTB.OUTTGL = LED_bm
#define LED_IS_H    ( PORTB.IN &  LED_bm )
#define LED_IS_L   !( PORTB.IN &  LED_bm )

#endif

