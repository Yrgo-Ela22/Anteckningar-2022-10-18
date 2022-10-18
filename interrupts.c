/********************************************************************************
* interrupts.c: Innehåller avbrottsrutiner.
********************************************************************************/
#include "header.h"

/********************************************************************************
* ISR (PCINT0_vect): Avbrottsrutin som äger rum vid event på tryckknappens pin
*                    13 / PORTB5. Eftersom flanken inte kan kontrolleras så 
*                    genomförs manuell kontroll för att detektera stigande flank 
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