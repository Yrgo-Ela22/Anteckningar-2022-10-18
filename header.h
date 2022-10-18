/********************************************************************************
* header.h: Innehåller diverse makrodefinitioner och funktionsdeklarationer
*           för implementering av det inbyggda systemet.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/* Inkluderingsdirektiv: */
#include <avr/io.h>        /* Innehåller information om I/O-portar såsom DDRB och PORTB. */
#include <avr/interrupt.h> /* Innehåller information om avbrottsrutiner såsom INT0_vect. */

#define LED1 0    /* Lysdiod på pin 8 / PORTB0. */
#define BUTTON1 5 /* Tryckknapp på pin 13 / PORTB5. */

#define LED1_ON PORTB |= (1 << LED1)   /* Tänder lysdiod 1. */
#define LED1_OFF PORTB &= ~(1 << LED1) /* Släcker lysdiod 1. */

#define BUTTON1_IS_PRESSED (PINB & (1 << BUTTON1)) /* Indikerar nedtryckning av tryckknapp 1. */

/* Enumerationer: */
typedef enum { false = 0, true = 1 } bool; /* Realiserar datatypen bool. */

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar samt aktiverar PCI-avbrott på 
*        tryckknappens pin.
********************************************************************************/
void setup(void);

/********************************************************************************
* led_toggle: Togglar tillståndet för angiven lysdiod på I/O-port B mellan att
*             vara tänd och släckt.
*
*             - pin: Lysdiodens pin-nummer på I/O-port B.
********************************************************************************/
void led_toggle(const uint8_t pin);

#endif /* HEADER_H_ */