/* AVRCRPX - charlieplexing library for avr.
 * avrcrpx.c
 *
 * Created: 02.12.2015 8:53:55
 *  Author: Integrator.SB
 */ 


#include "avrcrpx.h"


void crpx12SM()
{
	#ifdef COMMON_ANODE
	CRPXP = CRPXP & ~((1<<CRPX0)|(1<<CRPX1)|(1<<CRPX2)|(1<<CRPX3));
	CRPXDDR = CRPXDDR & ~((1<<CRPX0)|(1<<CRPX1)|(1<<CRPX2)|(1<<CRPX3));
	#else
	CRPXP = CRPXP | (1<<CRPX0)|(1<<CRPX1)|(1<<CRPX2)|(1<<CRPX3);
	CRPXDDR = CRPXDDR & ~((1<<CRPX0)|(1<<CRPX1)|(1<<CRPX2)|(1<<CRPX3));
	#endif
	switch(crpxSt)
	{
		case ON1:
		{
			
			if(crpxLedsA & 1<<0)
				CRPXDDR |= 1<<CRPX1;
			if(crpxLedsA & 1<<1)
				CRPXDDR |= 1<<CRPX2;
			if(crpxLedsA & 1<<2)
				CRPXDDR |= 1<<CRPX3;
				
			#ifdef COMMON_ANODE
			CRPXP |= (1<<CRPX0);
			#else
			CRPXP &= ~(1<<CRPX0);
			#endif
			CRPXDDR |= 1<<CRPX0;
			break;
		}
		case ON2:
		{

			if(crpxLedsA & 1<<3)
				CRPXDDR |= 1<<CRPX0;
			if(crpxLedsA & 1<<4)
				CRPXDDR |= 1<<CRPX2;
			if(crpxLedsA & 1<<5)
				CRPXDDR |= 1<<CRPX3;
				
			#ifdef COMMON_ANODE
			CRPXP |= (1<<CRPX1);
			#else
			CRPXP &= ~(1<<CRPX1);
			#endif
			CRPXDDR |= 1<<CRPX1;
			break;
		}
		case ON3:
		{

			if(crpxLedsA & 1<<6)
				CRPXDDR |= 1<<CRPX0;
			if(crpxLedsA & 1<<7)
				CRPXDDR |= 1<<CRPX1;
			if(crpxLedsA & 1<<8)
				CRPXDDR |= 1<<CRPX3;
				
			#ifdef COMMON_ANODE
			CRPXP |= (1<<CRPX2);
			#else
			CRPXP &= ~(1<<CRPX2);
			#endif
			CRPXDDR |= 1<<CRPX2;
			break;
		}

		case ON4:
		{
			if(crpxLedsA & 1<<9)
				CRPXDDR |= 1<<CRPX0;
			if(crpxLedsA & 1<<10)
				CRPXDDR |= 1<<CRPX1;
			if(crpxLedsA & 1<<11)
				CRPXDDR |= 1<<CRPX2;
			
			#ifdef COMMON_ANODE
			CRPXP |= (1<<CRPX3);
			#else
			CRPXP &= ~(1<<CRPX3);
			#endif
			CRPXDDR |= 1<<CRPX3;
		crpxSt = 0;
		break;
		}
	}
	crpxSt++;
}

 
