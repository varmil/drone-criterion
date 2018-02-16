#include "common_work.h"

void setMemoryBlock(unsigned char *memoryBlock, unsigned char *data, int dataSize)
{
#ifdef _ANSWER_
	int i;
	for(i=0 ; i<dataSize ; i++){
		*memoryBlock++ = *data++;
	}
#endif
}

unsigned char getByteMemory(unsigned char *memoryBlock, int byteIndex)
{
	unsigned char byteData = 0x0;

#ifdef _ANSWER_
	byteData = *(memoryBlock + byteIndex);
#endif
	return( byteData );
}

unsigned char checkSum(unsigned char *memoryBlock, int num)
{
	int i;
	unsigned char sum = 0;

#ifdef _ANSWER_
	for(i=0 ; i<num ; i++){
		sum += *memoryBlock++;
	}
#endif
	return sum;
}