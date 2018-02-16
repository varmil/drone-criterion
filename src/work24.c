#include "common_work.h"
#include <stdio.h>

int checkOdd(int startNum, int endNum, int (*func)(int num))
{
	int result = 0;

#ifdef _ANSWER_
	int i;

	for(i = startNum ; i <= endNum ; i++){
		if(func(i) == 1){
			result++;
		}
	}
#endif
	return result;
}