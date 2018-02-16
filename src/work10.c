#include "common_work.h"

#include<stdio.h>

TypeSize getTypeSize(void)
{
	TypeSize ts;

#ifdef _ANSWER_
	ts.charSize = sizeof(char);
	ts.charPtrSize = sizeof(char*);
	ts.shortSize = sizeof(short);
	ts.shortPtrSize = sizeof(short*);
	ts.intSize = sizeof(int);
	ts.intPtrSize = sizeof(int*);
	ts.longSize = sizeof(long);
	ts.longPtrSize = sizeof(long*);
	ts.floatSize = sizeof(float);
	ts.floatPtrSize = sizeof(float*);
	ts.doubleSize = sizeof(double);
	ts.doublePtrSize = sizeof(double*);
	ts.thisStructPtrSize = sizeof(TypeSize*);
	ts.thisStructSize = sizeof(TypeSize);
#endif
	return(ts);
}
