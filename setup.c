/********************************************************************************
* setup.c: Innehåller initieringsrutiner för det inbyggda systemet.
********************************************************************************/
#include "header.h"

/* Statiska funktioner: */
static inline void init_ports(void);
static inline void init_interrupts(void);

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar samt aktiverar PCI-avbrott för
*        eventdetektering på tryckknappens pin.
********************************************************************************/
void setup(void)
{
   init_ports();
   init_interrupts();
   return;
}

/********************************************************************************
* init_ports: Initierar mikrodatorns I/O-portar. Först sätts lysdiodens pin 8
*             / PORTB0 till utport via ettställning av motsvarande bit i
*             datariktningsregister DDRB.
*
*             Därefter aktiveras den interna pullup-resistorn på tryckknappens
*             pin 13 / PORTB5 via ettställning av motsvarande bit i register
*             PORTB. Detta genomförs för att insignalen alltid ska bli hög (1) 
*             eller låg (0). Som default är insignalen annars flytande mellan
*             0 - 1, ett tillstånd som inom digitaltekniken kallas tri-state.
********************************************************************************/
static inline void init_ports(void)
{
   DDRB = (1 << LED1);
   PORTB = (1 << BUTTON1);
   return;
}

/********************************************************************************
* init_interrupts: Aktiverar PCI-avbrott PCINT5 för eventdetektering på
*                  tryckknappens pin 13 / PORTB5.
*
*                  Först aktiveras avbrott globalt via ettställning av I-flaggan
*                  i CPU:ns statusregister SREG. För att ettställa I-flaggan
*                  används assemblerinstruktionen SEI.
*
*                  Därefter aktiveras avbrott på hela I/O-port B genom att
*                  aktivera avbrottsvektorn för denna I/O-port, PCINT0. Detta
*                  åstadkommes via ettställning av biten PCIE0 i kontrollregister
*                  PCICR. Den avbrottsrutin som då anropas vid PCI-avbrott på
*                  denna I/O-port innehar då avbrottsvektor PCINT0_vect.
*
*                  Slutligen aktiveras avbrott PCINT5 på tryckknappens pin 13 /
*                  PORTB5 via ettställning av biten PCINT5 i maskregister PCMSK0. 
*                  Eftersom denna bit har samma bitposition som tryckknappens
*                  portnummer 5, så används motsvarande makro BUTTON1 i stället,
*                  men det hade också gått att skriva PCINT5.
*
*                  Notering:
*                  - SEI    = Set Interrupt Flag.
*                  - PCICR  = Pin Change Interrupt Control Register.
*                  - PCIE0  = Pin Change Interrupt Enable 0.
*                  - PCMSK0 = PIN Change Mask Register 0.
********************************************************************************/
static inline void init_interrupts(void)
{
   asm("SEI");              
   PCICR = (1 << PCIE0);    
   PCMSK0 = (1 << BUTTON1); 
   return;
}