#include <string.h>

#include "common_work.h"

int strlaststr(char *strSrc, char *strMatch)
{
	int result = -1;

#ifdef _ANSWER_
	char *findStr = strSrc; // 探索ポイント
	int matchSize = strlen(strMatch);

	while(1){
		findStr = strstr( findStr, strMatch );
		if(findStr == NULL){ // もう見つからなかったら終了
			break;
		}
		result = findStr - strSrc; // 見つかった位置を保持

		if(strlen(findStr) > matchSize){ // マッチング文字列よりも対象文字列の未踏破部分が長い場合、続行
			findStr += matchSize; // 探索ポイントをずらす
		}
		else{
			break; // ポインタがオリジナル文字列の範囲外に出るため終了
		}
	}
#endif
	return(result);
}
