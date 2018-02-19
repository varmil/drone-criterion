#include <ctype.h>

#include "common_work.h"

PlayerParam sumPlayerParam(PlayerParam *data, int dataNum)
{
	PlayerParam sumParam;

#ifdef _ANSWER_
	int i;
	sumParam.win = sumParam.lose = sumParam.draw = 0;

	for(i=0 ; i < dataNum ; i++){
		sumParam.win  += data->win;
		sumParam.lose += data->lose;
		sumParam.draw += data->draw;
		data++;
	}
#endif
	return(sumParam);
}