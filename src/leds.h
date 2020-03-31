
#include <stdint.h>

#define ON 1
#define OFF 0

void Leds_Create (uint16_t *puerto);

void Leds_On(uint8_t led);

void Leds_Off(uint8_t led);

void Leds_AllOn( void );

void Leds_AllOff( void );

uint8_t Leds_State(uint8_t led);
