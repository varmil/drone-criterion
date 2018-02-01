#include "common_work.h"

unsigned char calcReverse(unsigned char a)
{
	unsigned char result = 0;

#ifdef _ANSWER_
	result = ~a;
#endif
	return result;
}

unsigned char calcXOR(unsigned char a, unsigned char b)
{
	unsigned char result = 0;

#ifdef _ANSWER_
	result  = a ^ b;
#endif
	return result;
}

unsigned char calcBitMask(unsigned char a, unsigned char b)
{
	unsigned char result = 0;

#ifdef _ANSWER_
	result = a & b;
#endif
	return result;
}

unsigned char calcBitEnable(unsigned char a, unsigned char b)
{
	unsigned char result = 0;

#ifdef _ANSWER_
	result = a | b;
#endif
	return result;
}
