#include "common_work.h"

#include<stdio.h>

int getIntByteSize(void)
{
	int size = 0;
#ifdef _ANSWER_
	size = sizeof(int);
#endif
	return(size);
}
