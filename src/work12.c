#include "common_work.h"

int myRound(double num)
{
	int result = 0;

#ifdef _ANSWER_
	result =  (int)( num < 0.0 ? num-0.5 : num+0.5 );
#endif
	return result;
}
