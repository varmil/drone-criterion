#include "common_work.h"
#include <stdlib.h>
#include <string.h>

unsigned char *allocBlock(int blockSize, unsigned char basePattern)
{
	unsigned char *memBlock = NULL;

#ifdef _ANSWER_
	memBlock = (unsigned char *)malloc(blockSize);
	memset(memBlock, basePattern, blockSize);
#endif
	return( memBlock );
}

void fillBlock(unsigned char* memBlock, int startFillByte, int endFillByte, unsigned char subPattern)
{
#ifdef _ANSWER_
	memset( memBlock + startFillByte - 1, subPattern, endFillByte - startFillByte + 1 );
#endif
}
