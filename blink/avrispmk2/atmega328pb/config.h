#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <avr/io.h>

#define LED       ( 1<<PB5 )
#define LED_OUT     DDRB  |=  LED 
#define LED_IN    { DDRB  &=~ LED; PORTB &=~ LED; }
#define LED_INPU  { DDRB  &=~ LED; PORTB |=  LED; }
#define LED_H       PORTB |=  LED 
#define LED_L       PORTB &=~ LED 
#define LED_I       PORTB ^=  LED 
#define LED_IS_H  ( PINB &    LED )
#define LED_IS_L !( PINB &    LED )

#endif

