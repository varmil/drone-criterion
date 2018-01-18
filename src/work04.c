#include <stdio.h>
#include <stdlib.h>

#include "common_work.h"

#ifdef _ANSWER_
static int cmp( const void *a , const void *b ) {
    if( ((Choco *)a)->price > ((Choco *)b)->price ) {
        return -1;
    }
    else if( ((Choco *)a)->price == ((Choco *)b)->price ) {
        return 0;
    }
    return 1;
}
#endif

void sortPrice( Choco *list, int n )
{
#ifdef _ANSWER_
    qsort( list, n, sizeof(Choco), cmp );
#endif
}
