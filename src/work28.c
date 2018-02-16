#include "common_work.h"
#include <stdio.h>

int getLength(const char *string)
{
	int result = 0;

#ifdef _ANSWER_
	if(string != NULL){
		while(*string++ != '\0'){
			result++;
		}
	}
#endif
	return result;
}
