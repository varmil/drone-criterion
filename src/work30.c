#include "common_work.h"

int isBigEndian(void)
{
	int result = 0;

#ifdef _ANSWER_
	unsigned int x = 0x1;
	if(*(char *)&x == 0x0){
		result = 1;
	}
#else
	result = -1;
#endif
	return result;
}