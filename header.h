/********************************************************************************
* header.h: Innehåller diverse makrodefinitioner och funktionsdeklarationer
*           för implementering av det inbyggda systemet. 
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/* Inkluderingsdirektiv: */
#include <avr/io.h>        /* Innehåller information om I/O-portar såsom DDRB och PORTB. */
#include <avr/interrupt.h> /* Innehåller information om avbrottsrutiner såsom INT0_vect. */

/* Makrodefinitioner: */
#define LED1 0    /* Lysdiod 1 ansluten till pin 8 / PORTB0. */
#define LED2 1    /* Lysdiod 2 ansluten till pin 9 / PORTB1. */

#define BUTTON1 4 /* Tryckknapp 1 ansluten till pin 12 / PORTB4. */
#define BUTTON2 5 /* Tryckknapp 2 ansluten till pin 13 / PORTB5. */

#define LED1_ON PORTB |= (1 << LED1)   /* Tänder lysdiod 1. */
#define LED2_ON PORTB |= (1 << LED2)   /* Tänder lysdiod 2. */

#define LED1_OFF PORTB &= ~(1 << LED1) /* Släcker lysdiod 1. */
#define LED2_OFF PORTB &= ~(1 << LED2) /* Släcker lysdiod 2. */

#define LEDS_ON PORTB |= (1 << LED1) | (1 << LED2)     /* Tänder lysdioderna. */
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2)) /* Släcker lysdioderna. */

#define BUTTON1_IS_PRESSED (PINB & (1 << BUTTON1)) /* Indikerar nedtryckning av tryckknapp 1. */
#define BUTTON2_IS_PRESSED (PINB & (1 << BUTTON2)) /* Indikerar nedtryckning av tryckknapp 2. */

/* Enumerationer: */
typedef enum { false = 0, true = 1 } bool; /* Realisear datatypen bool. */

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar samt PCI-avbrott på tryckknapparnas
*        pinnar.
********************************************************************************/
void setup(void);

/********************************************************************************
* led_toggle: Togglar tillståndet för angiven lysdiod på I/O-port B mellan att
*             vara tänd och släckt. Statiska variabler används för att hålla
*             reda på lysdiodernas tillstånd och togglas vid anrop för att
*             ändra tillstånd.
*
*             - pin: Lysdiodens pin-nummber på I/O-port B.
********************************************************************************/
void led_toggle(const uint8_t pin);

#endif /* HEADER_H_ */