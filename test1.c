/*
 * test1.c
 *
 * Created: 01.12.2015 23:49:39
 *  Author: Integrator.SB
 */ 

#define F_CPU 4800000UL 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "avrcrpx.h"


uint8_t tmr1, cnt1;
uint16_t leds;


ISR(TIM0_COMPA_vect)
{
	
 	if(!tmr1)
	{
		tmr1 = 250;
		if(leds >= 1<<12)
		{
			leds = 1;
		}
		crpxSetLeds(leds);
		leds = leds<<1;

	}
	
	tmr1--; 
	
	crpx12SM();
}



int main(void)
{
	
	cli();
	// настройка портов
	//DDRB = (1<<CPX0)|(1<<CPX1)|(1<<CPX2)|(1<<CPX3);

	// инициализация таймера
	TCCR0A = 1<<WGM01; // прерывание по сравнению
	TCCR0B = (1<<CS01) | (1<<CS00); // делитель на 64
	OCR0A = 75;// 4800000 / 64 / 75 = 1000uS
	TIMSK0 = 1<<OCIE0A;
	
	tmr1 = 250;// время переключения
	leds = 1;
	crpxSetLeds(1);
	sei();

    while(1)
    {

    }
}