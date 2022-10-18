/********************************************************************************
* main.c: Interruptbaserad styrning av en lysdiod ansluten till pin 8 / PORTB0
*         via nedtryckning av en tryckknapp ansluten till pin 13 / PORTB5.
*         PCI-avbrott PCINT5 �r aktiverat p� tryckknappens pin f�r att toggla
*         lysdioden mellan att vara t�nd och sl�ckt.
********************************************************************************/
#include "header.h"

/********************************************************************************
* led_toggle: Togglar tillst�ndet f�r angiven lysdiod p� I/O-port B mellan att
*             vara t�nd och sl�ckt. Statiska variabler anv�nds f�r att h�lla
*             reda p� lysdiodernas tillst�nd och togglas vid anrop f�r att
*             �ndra tillst�nd. F�r tillf�llet har implementering bara genomf�rts
*             f�r lysdiod 1 ansluten till pin 8 / PORTB0.
*
*             - pin: Lysdiodens pin-nummer p� I/O-port B.
********************************************************************************/
void led_toggle(const uint8_t pin)
{
   static bool led1_enabled = false;

   if (pin == LED1)
   {
      led1_enabled = !led1_enabled;

      if (led1_enabled) LED1_ON;
      else LED1_OFF;
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

