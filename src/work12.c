#include "common_work.h"

#ifdef _ANSWER_
static int result;
#endif

void resetCount(double iniVal)
{
#ifdef _ANSWER_
	result = (int)(iniVal * 10);
#endif
}

double countDown(void)
{
#ifdef _ANSWER_
	result -= 1;
	
	return result/10.0f;
#else
	return(0.0f);
#endif

}
