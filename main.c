/********************************************************************************
* main.c: Interruptbaserad styrning av en lysdiod ansluten till pin 8 / PORTB0
*         via nedtryckning av en tryckknapp ansluten till pin 13 / PORTB5.
*         PCI-avbrott PCINT5 är aktiverat på tryckknappens pin för att toggla
*         lysdioden mellan att vara tänd och släckt.
********************************************************************************/
#include "header.h"

/********************************************************************************
* led_toggle: Togglar tillståndet för angiven lysdiod på I/O-port B mellan att
*             vara tänd och släckt. Statiska variabler används för att hålla
*             reda på lysdiodernas tillstånd och togglas vid anrop för att
*             ändra tillstånd. För tillfället har implementering bara genomförts
*             för lysdiod 1 ansluten till pin 8 / PORTB0.
*
*             - pin: Lysdiodens pin-nummer på I/O-port B.
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
* main: Initierar mikrodatorn vid start. Programmet hålls sedan igång så länge
*       matningsspänning tillförs. Toggling av lysdioderna sker via interrupts,
*       därav avsaknad av kod i while-satsen.
********************************************************************************/
int main(void)
{
   setup();

   while (1)
   {
   }

   return 0;
}

