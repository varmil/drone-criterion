#include "common_work.h"

int searchChar(unsigned char *str, unsigned char chara)
{
	int index = 0;

#ifdef _ANSWER_
	while( *str != '\0' ){
		if( *str == chara ){
			break;
		}
		else{
			str++;
			index++;
		}
	}
	if( *str == '\0' ){
		index = -1;
	}
#endif
	return index;
}