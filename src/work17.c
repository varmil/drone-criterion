#include "common_work.h"

unsigned char rotateLeft(unsigned char val)
{
	unsigned char result = 0x0;

#ifdef _ANSWER_
	if(val & 0x80){
		result = 0x01;
	}
	result |= (val << 1);
#endif
	return(result);
}

unsigned char rotateRight(unsigned char val)
{
	unsigned char result = 0x0;

#ifdef _ANSWER_
	result = (val & 0x01) << 7;
	result |= (val >> 1) & 0x7f;
#endif
	return(result);
}
