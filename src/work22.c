#include "common_work.h"
#include <stdio.h>

int complement2( int data )
{
	int result;

#ifdef _ANSWER_
	result = ~data + 1;
#endif
	return(result);
}