#include <stdio.h>
#include <string.h>

#include "common_work.h"

char *getItemCSV(const char *csvData, int index)
{
	char *findString = NULL;

#ifdef _ANSWER_
	findString = strtok((char *)csvData, ",");
	if( index!=0 ){
		int i = 1;

		while( (findString = strtok(NULL, ",")) != NULL ){
			if( i == index ){
				break;
			}
			i++;
		}
	}
#endif
	return findString;
}