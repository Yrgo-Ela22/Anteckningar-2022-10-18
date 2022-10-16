/********************************************************************************
* main.c: Interruptbaserad styrning av två lysdioder anslutna till pin 8 - 9
*         via nedtryckning av tryckknappar anslutna till pin 12 - 13.
*
*         PCI-avbrott PCINT4 - PCINT5 är aktiverade för att toggla lysdioderna 
*         mellan att vara tända eller släckta. Vid nedtryckning av tryckknappen
*         ansluten till pin 12 så togglas lysdioden ansluten till pin 8. 
*         På samma sätt gäller att vid nedtryckning av tryckknappen ansluten  
*         till pin 13 så togglas lysdioden ansluten till pin 9.
********************************************************************************/
#include "header.h"

/********************************************************************************
* led_toggle: Togglar tillståndet för angiven lysdiod på I/O-port B mellan att
*             vara tänd och släckt. Statiska variabler används för att hålla
*             reda på lysdiodernas tillstånd och togglas vid anrop för att
*             ändra tillstånd.
*
*             - pin: Lysdiodens pin-nummber på I/O-port B.
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

