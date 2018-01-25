#include "common_work.h"

#include<stdio.h>

unsigned short make16BitData(unsigned short data1, unsigned short data2)
{
	unsigned short int newData = 0x0;

#ifdef _ANSWER_
	data1 <<= 8;
	data2 >>= 8;
	data1 |= data2;
	newData = ~data1;
#endif
	return(newData);
}
