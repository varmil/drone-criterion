#include "common_work.h"
#include <stdio.h>

int *searchItem( int vec[], int vecSize, int matchNumber )
{
	int *pResult = NULL;

#ifdef _ANSWER_
	int i;
	for( i=0 ; i<vecSize ; i++ ){
		if(vec[i] == matchNumber){
			pResult = vec + i;
		}
	}

#endif
	return pResult;
}