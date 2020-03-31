#include "leds.h"
//Constante para apagar todos los leds
#define ALL_OFF 0

//Constante para prender todos los leds
#define ALL_ON 0xFFFF

//Constate para fijar el primer bit en uno
#define BIT_ON 1

//Constante para convertir el nª de led en bit
#define LED_OFFSET 1

static uint16_t *leds;//solo se manipula desde este archivo

uint8_t Leds_Bits(uint8_t led){
	return (BIT_ON << (led - LED_OFFSET));
}

void Leds_Create(uint16_t *puerto){

	leds = puerto ;
	*leds = ALL_OFF;		
}

void Leds_On(uint8_t led){
	*leds |= Leds_Bits(led);
	//*leds = 4;
}

void Leds_Off(uint8_t led){
	
	//*leds = 0;
	*leds &= ~ Leds_Bits(led);
}

void Leds_AllOn( void )
{
	*leds = ALL_ON;
}

void Leds_AllOff( void )
{
	*leds = ALL_OFF;
}

uint8_t Leds_State(uint8_t led)
{
	return ( *leds & Leds_Bits(led) ) >> Leds_Bits( led - LED_OFFSET ) ;
}
