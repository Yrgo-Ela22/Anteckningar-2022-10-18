/********************************************************************************
* setup.c: Inneh�ller initieringsrutiner f�r det inbyggda systemet.
********************************************************************************/
#include "header.h"

/* Statiska funktioner: */
static inline void init_ports(void);
static inline void init_interrupts(void);

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar samt aktiverar PCI-avbrott f�r
*        eventdetektering p� tryckknappens pin.
********************************************************************************/
void setup(void)
{
   init_ports();
   init_interrupts();
   return;
}

/********************************************************************************
* init_ports: Initierar mikrodatorns I/O-portar. F�rst s�tts lysdiodens pin 8
*             / PORTB0 till utport via ettst�llning av motsvarande bit i
*             datariktningsregister DDRB.
*
*             D�refter aktiveras den interna pullup-resistorn p� tryckknappens
*             pin 13 / PORTB5 via ettst�llning av motsvarande bit i register
*             PORTB. Detta genomf�rs f�r att insignalen alltid ska bli h�g (1) 
*             eller l�g (0). Som default �r insignalen annars flytande mellan
*             0 - 1, ett tillst�nd som inom digitaltekniken kallas tri-state.
********************************************************************************/
static inline void init_ports(void)
{
   DDRB = (1 << LED1);
   PORTB = (1 << BUTTON1);
   return;
}

/********************************************************************************
* init_interrupts: Aktiverar PCI-avbrott PCINT5 f�r eventdetektering p�
*                  tryckknappens pin 13 / PORTB5.
*
*                  F�rst aktiveras avbrott globalt via ettst�llning av I-flaggan
*                  i CPU:ns statusregister SREG. F�r att ettst�lla I-flaggan
*                  anv�nds assemblerinstruktionen SEI.
*
*                  D�refter aktiveras avbrott p� hela I/O-port B genom att
*                  aktivera avbrottsvektorn f�r denna I/O-port, PCINT0. Detta
*                  �stadkommes via ettst�llning av biten PCIE0 i kontrollregister
*                  PCICR. Den avbrottsrutin som d� anropas vid PCI-avbrott p�
*                  denna I/O-port innehar d� avbrottsvektor PCINT0_vect.
*
*                  Slutligen aktiveras avbrott PCINT5 p� tryckknappens pin 13 /
*                  PORTB5 via ettst�llning av biten PCINT5 i maskregister PCMSK0. 
*                  Eftersom denna bit har samma bitposition som tryckknappens
*                  portnummer 5, s� anv�nds motsvarande makro BUTTON1 i st�llet,
*                  men det hade ocks� g�tt att skriva PCINT5.
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