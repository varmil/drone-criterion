#include "common_work.h"

#ifdef _ANSWER_
void swap( int *a, int *b )
#else
void swap( void )
#endif
{
#ifdef _ANSWER_
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
#endif
}
