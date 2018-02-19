#include "common_work.h"

double mulVoidPtr(void *a, void *b)
{
	double result = 0.0;

#ifdef _ANSWER_
	result = *((double *)a) * *((int *)b);
#endif
	return result;
}