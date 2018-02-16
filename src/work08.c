#include "common_work.h"

char *strweek(int n)
{
#ifdef _ANSWER_
	static char *week[] = {
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
		"",
	};

	return(((n >= 0) && (n <= 6)) ? week[n] : week[7]);
#else
	return("");
#endif
}
