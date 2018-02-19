#include "common_work.h"

int complement2(int data)
{
	int result;

#ifdef _ANSWER_
	result = ~data + 1;
#endif
	return(result);
}

int subUsedcomplement2(int a, int b)
{
	int result = 0;

#ifdef _ANSWER_
	result = a + complement2(b);
#endif
	return(result);
}