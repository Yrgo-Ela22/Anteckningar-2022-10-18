/********************************************************************************
* interrupts.c: Inneh�ller avbrottsrutiner.
********************************************************************************/
#include "header.h"

/********************************************************************************
* ISR (PCINT0_vect): Avbrottsrutin som �ger rum vid event p� tryckknappens pin
*                    13 / PORTB5. Eftersom flanken inte kan kontrolleras s� 
*                    genomf�rs manuell kontroll f�r att detektera stigande flank 
*                    (nedtryckning av tryckknappen).
********************************************************************************/
ISR (PCINT0_vect)
{
   if (BUTTON1_IS_PRESSED)
   {
      led_toggle(LED1);
   }
   return;
}