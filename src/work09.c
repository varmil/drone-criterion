#include "common_work.h"

unsigned int blinkPattern(unsigned int pattern)
{
	static unsigned int currentPattern = 0x0;

#ifdef _ANSWER_
	currentPattern ^= pattern;
#else

	return(currentPattern);
#endif
}
