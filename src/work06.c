#include <stdio.h>

#include "common_work.h"

unsigned int PickupGreen(unsigned int argb)
{
	unsigned int colorG = 0x00;
	
#ifdef _ANSWER_
	colorG = (argb >> 8) & 0xff;
#endif
	return colorG;
}
