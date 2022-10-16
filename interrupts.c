/********************************************************************************
* interrupts.c: Innehåller diverse avbrottsrutiner.
********************************************************************************/
#include "header.h"

/********************************************************************************
* ISR (PCINT0_vect): Avbrottsrutin som äger rum vid event på tryckknapparnas
*                    pinnar. Eftersom flanken inte kan kontrolleras så genomförs
*                    manuell kontroll för att detektera stigande flank på någon
*                    av tryckknapparnars pinnar (de är då nedtryckta nu när
*                    avbrottsrutinen har kallats och bör därmed ha varit
*                    uppsläppta innan dess). 
*
*                    Om tryckknapp 1 trycks ned så togglas lysdiod 1. 
*                    Annars om tryckknapp 2 trycks ned så togglas lysdiod 2.
********************************************************************************/
ISR (PCINT0_vect)
{
   if (BUTTON1_IS_PRESSED)
   {
      led_toggle(LED1);
   }
   else if (BUTTON2_IS_PRESSED)
   {
      led_toggle(LED2);
   }
   return;
}

