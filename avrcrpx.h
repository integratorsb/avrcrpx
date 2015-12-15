#include <avr/io.h>

#define COMMON_ANODE  // закоментировать если светодиоды включены по схеме с общим катодом 
// выводы
#define CRPXP PORTB
#define CRPXDDR DDRB
#define CRPX0 PORTB2
#define CRPX1 PORTB1
#define CRPX2 PORTB0
#define CRPX3 PORTB4

enum
{
	ON1 = 1,
	ON2,
	ON3,
	ON4
};

uint8_t crpxSt; 
uint16_t crpxLedsA;// состояния светодиодов

void crpx12SM(void);
#define crpxInit() crpxSt = 0
#define crpxSetLeds(val) crpxLedsA = val
#define crpxLedOn(n) crpxLedsA |= 1<<n
#define crpxLedOff(n) crpxLedsA &= ~(1<<n)

