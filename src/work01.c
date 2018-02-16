#include "common_work.h"

#ifdef _ANSWER_
void change(int *a, int *b)
#else
void change(void)
#endif
{
#ifdef _ANSWER_
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
#endif
}
