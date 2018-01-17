#include<stdio.h>

#include "work03.h"

char *int_to_str(int value)
{
    static char buf[80];

    sprintf(buf, "%d", value);

    return buf;
}
