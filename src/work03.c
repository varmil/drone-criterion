#include<stdio.h>

#include "common_work.h"

char *int_to_str(int value)
{
#ifdef _ANSWER_
	static char buf[80];

	sprintf(buf, "%d", value);

	return buf;
#else
	return NULL;
#endif
}
