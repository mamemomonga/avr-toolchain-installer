#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <avr/io.h>

/*

ATTiny4809 40Pin DIP

 PC0 | 1     40 | PA7
 PC1 | 2     39 | PA6
 PC2 | 3     38 | PA4
 PC3 | 4     37 | PA4
 VDD | 5     36 | PA3
 GND | 6     35 | PA2
 PC4 | 7     34 | PA1
 PC5 | 8     33 | PA0(EXTCLK)
 PD0 | 9     32 | GND
 PD1 | 10    31 | VDD
 PD2 | 11    30 | UPDI
 PD3 | 12    29 | PF6
 PD4 | 13    28 | PF5
 PD5 | 14    27 | PF3
 PD6 | 15    26 | PF3
 PD7 | 16    25 | PF2
AVDD | 17    24 | PF1(TOSC2)
 GND | 18    23 | PF0(TOSC1)
 PE0 | 19    22 | PE3 
 PE1 | 20    21 | PE2 LED

*/

#define LED_bm     ( 1<<2 ) // PE2
#define LED_CTRL   PORTE.PIN2CTRL |= PORT_PULLUPEN_bm | PORT_ISC_FALLING_gc
#define LED_OUT    PORTE.DIRSET = LED_bm
#define LED_IN     PORTE.DIRCLR = LED_bm
#define LED_H      PORTE.OUTSET = LED_bm
#define LED_L      PORTE.OUTCLR = LED_bm
#define LED_I      PORTE.OUTTGL = LED_bm
#define LED_IS_H    ( PORTE.IN &  LED_bm )
#define LED_IS_L   !( PORTE.IN &  LED_bm )

#endif

