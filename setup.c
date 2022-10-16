/********************************************************************************
* setup.c: Inneh�ller initieringsrutiner f�r det inbyggda systemet.
********************************************************************************/
#include "header.h"

/* Statiska funktioner: */
static inline void init_ports(void);
static inline void init_interrupts(void);

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar samt aktiverar PCI-avbrott PCINT4
*        samt PCINT5 f�r eventdetektering p� tryckknapparnas pinnar.
********************************************************************************/
void setup(void)
{
   init_ports();
   init_interrupts();
   return;
}

/********************************************************************************
* init_ports: Initierar mikrodatorns I/O-portar. F�rst s�tts lysdiodernas pinnar
*             till utportar via ettst�llning av motsvarandear bitar i
*             datariktningsregister DDRB.
*
*             D�refter aktiveras de interna pullup-resistorna p� tryckknapparnas
*             pinnar f�r att insignalerna alltid ska bli h�ga (1) eller l�ga (0).
*             Som default �r insignalerna annars flytande mellan 0 - 1, ett
*             tillst�nd som inom digitaltekniken kallas tri-state.
********************************************************************************/
static inline void init_ports(void)
{
   DDRB = (1 << LED1) | (1 << LED2);
   PORTD = (1 << BUTTON1) | (1 << BUTTON2);
   return;
}

/********************************************************************************
* init_interrupts: Aktiverar PCI-avbrott PCINT4 - PCINT5 f�r eventdetektering
*                  p� tryckknapparnas pinnar 12 - 13 / PORTB4 - PORTB5.
*
*                  F�rst aktiveras avbrott globalt via ettst�llning av I-flaggan
*                  i CPU:ns statusregister SREG. F�r att ettst�lla I-flaggan
*                  anv�nds assemblerinstruktionen SEI.
*
*                  D�refter aktiveras avbrott p� hela I/O-port B genom att
*                  aktivera avbrottsvektorn f�r denna I/O-port, PCINT0. Detta
*                  �stadkommes via ettst�llning av biten PCIE0 i kontrollregister
*                  PCICR.
*
*                  Slutligen aktiveras avbrott PCINT4 - PCINT5 p� tryckknapparnas
*                  pinnar pin 12 - 13 / PORTB4 - PORTB5 via ettst�llning av bitar
*                  PCINT4 och PCINT5 i maskregister PCMSK0. Eftersom dessa bitar
*                  har samma position som tryckknapparnas portnummer 4 och 5,
*                  s� anv�nds motsvarande makron BUTTON1 - BUTTON2 i st�llet,
*                  men det hade ocks� g�tt att skriva PCINT4 - PCINT5.
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