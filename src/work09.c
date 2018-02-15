#include "common_work.h"
#include <stdio.h>

unsigned int getSubBit(unsigned int baseData, int n, int m)
{
	unsigned int result = 0x0;

#ifdef _ANSWER_
	baseData >>= n;

	unsigned int mask = 0x1;
	int i;
	for( i = 0 ; i < m-n ; i++ ){
		mask <<= 1;
		mask |= 1;
	}
	result = baseData & mask;
#endif
	return(result);
}
