/********************************************************************************
* header.h: Inneh�ller diverse makrodefinitioner och funktionsdeklarationer
*           f�r implementering av det inbyggda systemet.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/* Inkluderingsdirektiv: */
#include <avr/io.h>        /* Inneh�ller information om I/O-portar s�som DDRB och PORTB. */
#include <avr/interrupt.h> /* Inneh�ller information om avbrottsrutiner s�som INT0_vect. */

#define LED1 0    /* Lysdiod p� pin 8 / PORTB0. */
#define BUTTON1 5 /* Tryckknapp p� pin 13 / PORTB5. */

#define LED1_ON PORTB |= (1 << LED1)   /* T�nder lysdiod 1. */
#define LED1_OFF PORTB &= ~(1 << LED1) /* Sl�cker lysdiod 1. */

#define BUTTON1_IS_PRESSED (PINB & (1 << BUTTON1)) /* Indikerar nedtryckning av tryckknapp 1. */

/* Enumerationer: */
typedef enum { false = 0, true = 1 } bool; /* Realiserar datatypen bool. */

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar samt aktiverar PCI-avbrott p� 
*        tryckknappens pin.
********************************************************************************/
void setup(void);

/********************************************************************************
* led_toggle: Togglar tillst�ndet f�r angiven lysdiod p� I/O-port B mellan att
*             vara t�nd och sl�ckt.
*
*             - pin: Lysdiodens pin-nummer p� I/O-port B.
********************************************************************************/
void led_toggle(const uint8_t pin);

#endif /* HEADER_H_ */