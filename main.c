/********************************************************************************
* main.c: Interruptbaserad styrning av tv� lysdioder anslutna till pin 8 - 9
*         via nedtryckning av tryckknappar anslutna till pin 12 - 13.
*
*         PCI-avbrott PCINT4 - PCINT5 �r aktiverade f�r att toggla lysdioderna 
*         mellan att vara t�nda eller sl�ckta. Vid nedtryckning av tryckknappen
*         ansluten till pin 12 s� togglas lysdioden ansluten till pin 8. 
*         P� samma s�tt g�ller att vid nedtryckning av tryckknappen ansluten  
*         till pin 13 s� togglas lysdioden ansluten till pin 9.
********************************************************************************/
#include "header.h"

/********************************************************************************
* led_toggle: Togglar tillst�ndet f�r angiven lysdiod p� I/O-port B mellan att
*             vara t�nd och sl�ckt. Statiska variabler anv�nds f�r att h�lla
*             reda p� lysdiodernas tillst�nd och togglas vid anrop f�r att
*             �ndra tillst�nd.
*
*             - pin: Lysdiodens pin-nummber p� I/O-port B.
********************************************************************************/
void led_toggle(const uint8_t pin)
{
   static bool led1_enabled = false;
   static bool led2_enabled = false;

   if (pin == LED1)
   {
      led1_enabled = !led1_enabled;

      if (led1_enabled) LED1_ON;
      else LED1_OFF;
   }
   else if (pin == LED2)
   {
      led2_enabled = !led2_enabled;

      if (led2_enabled) LED2_ON;
      else LED2_OFF;
   }

   return;
}

/********************************************************************************
* main: Initierar mikrodatorn vid start. Programmet h�lls sedan ig�ng s� l�nge
*       matningssp�nning tillf�rs. Toggling av lysdioderna sker via interrupts,
*       d�rav avsaknad av kod i while-satsen.
********************************************************************************/
int main(void)
{
   setup();

   while (1)
   {
   }

   return 0;
}

