#include "common_work.h"
#include <stdlib.h>
#include <string.h>

unsigned char *allocBlock(int blockSize, unsigned char fillData)
{
	unsigned char *memBlock = NULL;

#ifdef _ANSWER_
	memBlock = (unsigned char *)malloc(blockSize);
	memset(memBlock, fillData, blockSize);
#endif
	return( memBlock );
}

void fillBlock(unsigned char* memBlock, int startFillByte, int endFillByte, unsigned char fillData)
{
#ifdef _ANSWER_
	memset( memBlock + startFillByte - 1, fillData, endFillByte - startFillByte + 1 );
#endif
}
