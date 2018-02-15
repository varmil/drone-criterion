#include "common_work.h"
#include <stdio.h>

#ifdef _ANSWER_
extern double cubeDouble( double num );
#endif

int cubeFunc(double num)
{
	double result = 0.0;

#ifdef _ANSWER_
	result = (int)(cubeDouble(num) + 0.5f);
#endif
	return result;
}