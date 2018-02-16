#include "common_work.h"
#include <ctype.h>

void convUpperCamel(char *str)
{
#ifdef _ANSWER_
	*str = toupper(*str);
#endif
}