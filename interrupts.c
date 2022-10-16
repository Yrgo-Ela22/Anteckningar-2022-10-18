/********************************************************************************
* interrupts.c: Inneh�ller diverse avbrottsrutiner.
********************************************************************************/
#include "header.h"

/********************************************************************************
* ISR (PCINT0_vect): Avbrottsrutin som �ger rum vid event p� tryckknapparnas
*                    pinnar. Eftersom flanken inte kan kontrolleras s� genomf�rs
*                    manuell kontroll f�r att detektera stigande flank p� n�gon
*                    av tryckknapparnars pinnar (de �r d� nedtryckta nu n�r
*                    avbrottsrutinen har kallats och b�r d�rmed ha varit
*                    uppsl�ppta innan dess). 
*
*                    Om tryckknapp 1 trycks ned s� togglas lysdiod 1. 
*                    Annars om tryckknapp 2 trycks ned s� togglas lysdiod 2.
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

