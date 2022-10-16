/********************************************************************************
* setup.c: Innehåller initieringsrutiner för det inbyggda systemet.
********************************************************************************/
#include "header.h"

/* Statiska funktioner: */
static inline void init_ports(void);
static inline void init_interrupts(void);

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar samt aktiverar PCI-avbrott PCINT4
*        samt PCINT5 för eventdetektering på tryckknapparnas pinnar.
********************************************************************************/
void setup(void)
{
   init_ports();
   init_interrupts();
   return;
}

/********************************************************************************
* init_ports: Initierar mikrodatorns I/O-portar. Först sätts lysdiodernas pinnar
*             till utportar via ettställning av motsvarandear bitar i
*             datariktningsregister DDRB.
*
*             Därefter aktiveras de interna pullup-resistorna på tryckknapparnas
*             pinnar för att insignalerna alltid ska bli höga (1) eller låga (0).
*             Som default är insignalerna annars flytande mellan 0 - 1, ett
*             tillstånd som inom digitaltekniken kallas tri-state.
********************************************************************************/
static inline void init_ports(void)
{
   DDRB = (1 << LED1) | (1 << LED2);
   PORTD = (1 << BUTTON1) | (1 << BUTTON2);
   return;
}

/********************************************************************************
* init_interrupts: Aktiverar PCI-avbrott PCINT4 - PCINT5 för eventdetektering
*                  på tryckknapparnas pinnar 12 - 13 / PORTB4 - PORTB5.
*
*                  Först aktiveras avbrott globalt via ettställning av I-flaggan
*                  i CPU:ns statusregister SREG. För att ettställa I-flaggan
*                  används assemblerinstruktionen SEI.
*
*                  Därefter aktiveras avbrott på hela I/O-port B genom att
*                  aktivera avbrottsvektorn för denna I/O-port, PCINT0. Detta
*                  åstadkommes via ettställning av biten PCIE0 i kontrollregister
*                  PCICR.
*
*                  Slutligen aktiveras avbrott PCINT4 - PCINT5 på tryckknapparnas
*                  pinnar pin 12 - 13 / PORTB4 - PORTB5 via ettställning av bitar
*                  PCINT4 och PCINT5 i maskregister PCMSK0. Eftersom dessa bitar
*                  har samma position som tryckknapparnas portnummer 4 och 5,
*                  så används motsvarande makron BUTTON1 - BUTTON2 i stället,
*                  men det hade också gått att skriva PCINT4 - PCINT5.
*                 
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
   PCMSK0 = (1 << BUTTON1) | (1 << BUTTON2);
   return;
}