#include <criterion/criterion.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "common_work.h"

// 整数値aとbの値をスワップさせるswap関数を作成せよ。(work01)
Test(execise, 1) {
    int a = 10, b = 20;

#ifdef _ANSWER_
    swap( &a, &b );
#else
    swap();
#endif        

    cr_assert(a == 20, "swap error a");
    cr_assert(b == 10, "swap error b");
}

// strcpyを使わずに文字列をコピーする関数my_strcpyを作成せよ。(work02)
Test(execise, 2) {
    char dstStr[] = "";
    
    my_strcpy(dstStr, "PHP");

    cr_assert(strcmp(dstStr, "PHP") == 0, "dstStr copy fatal");
}

// 整数値を文字列に変換する関数int_to_strを作成せよ。(work03)
Test(execise, 3) {
    cr_assert(int_to_str(100)!=NULL, "string NULL error");
    cr_assert(strcmp(int_to_str(100), "100") == 0, "string convert error");
    cr_assert(strcmp(int_to_str(-555), "-555") == 0, "string convert error");
}

// サンプルデータを価格順にソートする関数を作成せよ。(work04)
Test(execise, 4) {
    Choco list[] =
        { { 5200, "アーモンド", 1000 }, { 3010, "ラムレーズン", 840 }
        , { 2020, "ビター", 525 }, { 3020, "クランチ", 720 }
        , { 2030, "ホワイト", 500 }, { 2010, "ミルク", 450 }
        , { 5050, "マカダミア", 1200 } };

    sortPrice( list, sizeof(list)/sizeof(Choco) );

    cr_assert(strcmp(list[0].name, "マカダミア") == 0, "list0 error");
    cr_assert(strcmp(list[1].name, "アーモンド") == 0, "list1 error");
    cr_assert(strcmp(list[2].name, "ラムレーズン") == 0, "list2 error");
    cr_assert(strcmp(list[3].name, "クランチ") == 0, "list3 error");
    cr_assert(strcmp(list[4].name, "ビター") == 0, "list4 error");
    cr_assert(strcmp(list[5].name, "ホワイト") == 0, "list5 error");
    cr_assert(strcmp(list[6].name, "ミルク") == 0, "list6 error");
}

// 名前とインデックス番号をリストに登録していき、一括表示。最後にリスト情報を解放する。(work05)
Test(execise, 5) {
	MemberList *head = NULL; /* 先頭ポインタ */
	char *name[] = {
        "ashihara", "matsuo", "yamamoto", "kuwata" 
    };	
    int num = sizeof(name)/sizeof(*name);
    int indexNo;

    for( indexNo = 0 ; indexNo < num ; indexNo++ ){
        head = add_list(indexNo, name[indexNo], head);
	}

	/* リストの一括表示 */
	show_list(head);

    MemberList *p = head;
    cr_assert(strcmp(p->name, "ashihara") == 0, "list0 error"); p = p->next;
    cr_assert(strcmp(p->name, "matsuo")   == 0, "list1 error"); p = p->next;
    cr_assert(strcmp(p->name, "yamamoto") == 0, "list2 error"); p = p->next;
    cr_assert(strcmp(p->name, "kuwata")   == 0, "list3 error");

	/* リストの開放 */
	free_list(head);
}

// 下記ビット配置のARGB8888フォーマットにおけるGreen値を抽出せよ(work6)
#define ARGB8888(a,r,g,b)  ((unsigned int)((((a) & 0xff)<<24) | (((r) & 0xff)<<16) | (((g) & 0xff)<<8) | ((b) & 0xff)))

Test(execise, 6) {

    unsigned int argbColor = ARGB8888(0x12, 0x34, 0x56, 0x78);

    unsigned int colorG = 0x00;

    colorG = PickupGreen(argbColor);

    cr_assert(colorG == 0x56, "color unmatching");
}

// カンマ区切りの文字列データのn番目の要素を取り出せ(work7)
Test(execise, 7) {

    const char csvData[]="SQL,C,PHP,JavaScript,Linux,HTML,bash";

	char *copyStr = (char *)malloc(sizeof(csvData));
    strcpy(copyStr, csvData);
    cr_assert(strcmp(getItemCSV(copyStr, 0), "SQL") == 0, "csv parse error");
    strcpy(copyStr, csvData);
    cr_assert(strcmp(getItemCSV(copyStr, 5), "HTML") == 0, "csv parse error");

    free(copyStr);
}