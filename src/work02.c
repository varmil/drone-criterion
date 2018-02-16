#include "common_work.h"

void my_strcpy(char *dstStr, const char *srcStr)
{
#ifdef _ANSWER_
	while(*dstStr = *srcStr){
		if(*dstStr >= 0x61 && *dstStr <= 0x7A){
			*dstStr -= 0x20;
		}
		dstStr++;
		srcStr++;	
	}
#endif
}
