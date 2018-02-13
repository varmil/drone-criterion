#include "common_work.h"
#include <stdio.h>

#ifdef _ANSWER_
extern double cubeDouble( double num );
#endif

double cubeFunc(double num)
{
	double result = 0.0;

#ifdef _ANSWER_
	result = cubeDouble(num);
#endif
	return result;
}