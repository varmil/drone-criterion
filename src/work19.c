#include "common_work.h"
#include <stdio.h>

void setMemoryBlock( unsigned char *dataBlock )
{
#ifdef _ANSWER_
	*dataBlock++ = 0x12;
	*dataBlock++ = 0x34;
	*dataBlock++ = 0x56;
	*dataBlock   = 0x78;
#endif
}

unsigned char getByteMemory( unsigned char *dataBlock, int byteIndex )
{
	unsigned char byteData = 0x0;

#ifdef _ANSWER_
	byteData = *( dataBlock + byteIndex );
#endif
	return( byteData );
}

unsigned char checkSum( unsigned char *dataBlock, int num )
{
	int i;
	unsigned char sum = 0;

#ifdef _ANSWER_
	for( i=0 ; i<num ; i++ ){
		sum += *dataBlock++;
	}
#endif
	return sum;
}