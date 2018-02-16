#include "common_work.h"
#include <stdlib.h>

void allocMyArray(unsigned char **p, unsigned int num, unsigned short pattern )
{
#ifdef _ANSWER_
	int i;
	for(i=0 ; i<num ; i++){
		*p = (unsigned char *)malloc(sizeof(unsigned char));
		**p = pattern;
		p++;
	}
#endif	
}

void freeMyArray(unsigned char **p, unsigned int num)
{
#ifdef _ANSWER_
	int i;

	for(i=0 ; i<num ; i++){
		free(*p);
		p++;
	}
#endif
}
