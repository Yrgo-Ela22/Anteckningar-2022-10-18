/********************************************************************************
* header.h: Inneh�ller diverse makrodefinitioner och funktionsdeklarationer
*           f�r implementering av det inbyggda systemet. 
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/* Inkluderingsdirektiv: */
#include <avr/io.h>        /* Inneh�ller information om I/O-portar s�som DDRB och PORTB. */
#include <avr/interrupt.h> /* Inneh�ller information om avbrottsrutiner s�som INT0_vect. */

/* Makrodefinitioner: */
#define LED1 0    /* Lysdiod 1 ansluten till pin 8 / PORTB0. */
#define LED2 1    /* Lysdiod 2 ansluten till pin 9 / PORTB1. */

#define BUTTON1 4 /* Tryckknapp 1 ansluten till pin 12 / PORTB4. */
#define BUTTON2 5 /* Tryckknapp 2 ansluten till pin 13 / PORTB5. */

#define LED1_ON PORTB |= (1 << LED1)   /* T�nder lysdiod 1. */
#define LED2_ON PORTB |= (1 << LED2)   /* T�nder lysdiod 2. */

#define LED1_OFF PORTB &= ~(1 << LED1) /* Sl�cker lysdiod 1. */
#define LED2_OFF PORTB &= ~(1 << LED2) /* Sl�cker lysdiod 2. */

#define LEDS_ON PORTB |= (1 << LED1) | (1 << LED2)     /* T�nder lysdioderna. */
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2)) /* Sl�cker lysdioderna. */

#define BUTTON1_IS_PRESSED (PINB & (1 << BUTTON1)) /* Indikerar nedtryckning av tryckknapp 1. */
#define BUTTON2_IS_PRESSED (PINB & (1 << BUTTON2)) /* Indikerar nedtryckning av tryckknapp 2. */

/* Enumerationer: */
typedef enum { false = 0, true = 1 } bool; /* Realisear datatypen bool. */

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar samt PCI-avbrott p� tryckknapparnas
*        pinnar.
********************************************************************************/
void setup(void);

/********************************************************************************
* led_toggle: Togglar tillst�ndet f�r angiven lysdiod p� I/O-port B mellan att
*             vara t�nd och sl�ckt. Statiska variabler anv�nds f�r att h�lla
*             reda p� lysdiodernas tillst�nd och togglas vid anrop f�r att
*             �ndra tillst�nd.
*
*             - pin: Lysdiodens pin-nummber p� I/O-port B.
********************************************************************************/
void led_toggle(const uint8_t pin);

#endif /* HEADER_H_ */