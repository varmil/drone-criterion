#include "common_work.h"

#include<stdio.h>

unsigned int make16BitReverseData(unsigned int data1, unsigned int data2)
{
	unsigned int newData = 0x0;

#ifdef _ANSWER_
	data1 <<= 8;
	data1 &= 0xffff;
	data2 &= 0xffff;
	data2 >>= 8;
	data1 |= data2;
	newData = ~data1;
	newData &= 0xffff;
#endif
	return(newData);
}
