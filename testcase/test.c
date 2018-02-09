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
	cr_assert(strcmp(getItemCSV(copyStr, 0), "SQL") == 0, "SQL parse error");
	strcpy(copyStr, csvData);
	cr_assert(strcmp(getItemCSV(copyStr, 5), "HTML") == 0, "HTML parse error");

	free(copyStr);
}

// 曜日を示す文字列へのポインタを返す関数を作成せよ(work8)
// ただし日曜日を0とし、土曜日を6とする
Test(execise, 8) {
	cr_assert(strcmp(strweek(0), "Sunday") == 0, "週初め取得できず");
	cr_assert(strcmp(strweek(6), "Saturday") == 0, "週末取得できず");
}

// 呼ぶたびにパターンが点滅する関数を作成せよ(work9)
Test(execise, 9) {
	unsigned int basePattern = 0xabcd;

	cr_assert(blinkPattern(basePattern) == 0xabcd, "初回点灯 NG");
	cr_assert(blinkPattern(basePattern) == 0x0, "消灯 NG");
	cr_assert(blinkPattern(basePattern) == 0xabcd, "再点灯 NG");
}

// 処理系ごとにint型のサイズが異なる。
// このシステムのint型のサイズを調べる関数を作成せよ(work10)
Test(execise, 10) {
	cr_assert(getIntByteSize() == 4, "size mistake");
}

// data1の下位8bitを上位8bitとし、data2の上位8bitを下位8bitとしたビット列を
// 反転した値を表示する関数を作成せよ(work11)
Test(execise, 11) {
	cr_assert(make16BitData(0xabcd, 0x1234) == 0x32ed, "bitdata mistake");
}

 // 小数点以下を四捨五入する関数を自作せよ(work12)
Test(execise, 12) {
	cr_assert(myRound(5.4) == 5, "切り下げ error");
	cr_assert(myRound(5.5) == 6, "切り上げ error");
}

// 任意の数のポインターの配列を使って、それぞれに1バイト領域を割り当て、要素を0xbeで埋めたのち、解放せよ(work13)
#define ARRAY_NUM   3

Test(execise, 13) {

	unsigned char *p[ARRAY_NUM] = { NULL, NULL, NULL };

	allocMyArray( p, ARRAY_NUM, 0xbe );

	cr_assert(p[0] != NULL, "p0 null");
	cr_assert(p[1] != NULL, "p1 null");
	cr_assert(p[2] != NULL, "p2 null");

	cr_assert(*p[0] == 0xbe, "p0 value set error");
	cr_assert(*p[1] == 0xbe, "p1 value set error");
	cr_assert(*p[2] == 0xbe, "p2 value set error");

	freeMyArray(p, ARRAY_NUM);
}

// 下記の演算関数を作成せよ(work14)
Test(execise, 14) {
	unsigned char a = 0xc5;
	unsigned char b = 0x96;

	cr_assert(calcReverse(a)        == 0x3a, "reverse error");  // 反転
	cr_assert(calcXOR(a, b)         == 0x53, "xor error");      // 排他的論理和
	cr_assert(calcBitMask(a, b)     == 0x84, "mask error");     // ビットマスク
	cr_assert(calcBitEnable(a, b)   == 0xd7, "eneble error");   // 特定ビットを常に有効にする
}

// 文字列から任意の文字が初めて出現する位置を求める関数を作成せよ(work15)
Test(execise, 15) {
	char testStr[] = "abcdefghijklmnopqrstuvwxyz";

	cr_assert(searchChar(testStr, 'd') == 3, "d index error");  // d
	cr_assert(searchChar(testStr, '@') == -1, "@ index error");  // 不正文字
}

// 当該データ構造における各種関数を作成せよ(work16)
Test(execise, 16) {
	Student students[]={
		{ "yamamoto",{100,100,100,100 } },
		{ "kuwata",  { 10, 20, 30, 40 } },
		{ "iggy",    { 12, 34, 56, 78 } },
	};

	int num = sizeof(students)/sizeof(Student);
	cr_assert(calcSubjectAverage(students, num, JAPANESE) == 62, "Japanese average error");
	cr_assert(calcAllAverage(students, num) == 56, "all average error");
	Grade *grade = getGrade(students, num, "kuwata");
	cr_assert(grade != NULL, "grade not null");
//	if( grade ){
		cr_assert(grade->subjects[ENGLISH] == 10, "kuwata\'s English error");
//	}
}

// キャリーなし左右ローテート関数を作り、ビットパターンが1ビットずつ移動するアニメーションを作成せよ(work17)  
// ただし、処理系が算術シフト、論理シフトいずれを採用していても結果が変わらないように注意せよ
Test(execise, 17) {
	unsigned char data;

	// ビットパターン左移動
	data = 0x81;
	data = rotateLeft(data);
	cr_assert(data == 0x03, "RotateLeft1 error");
	data = rotateLeft(data);
	cr_assert(data == 0x06, "RotateLeft2 error");
	data = rotateLeft(data);
	cr_assert(data == 0x0c, "RotateLeft3 error");

	// ビットパターン右移動
	data = 0x81;
	data = rotateRight(data);
	cr_assert(data == 0xc0, "RotateRight1 error");
	data = rotateRight(data);
	cr_assert(data == 0x60, "RotateRight2 error");
	data = rotateRight(data);
	cr_assert(data == 0x30, "RotateRight3 error");
}

// 文字列strSrcの中から文字列strMatcを探し、その最後にみつけた位置を返す関数を作成する。(work18) 
// ・見つからなかったら-1を返すこと。strstr関数を使用して良い
Test(execise, 18) {
	char *strSrc1 = "abcdefdefdef"; // 探索文字列その1
	char *strSrc2 = "a"; // 探索文字列その2
	char *strMatch = "def"; // マッチング対象文字列

	cr_assert(strlaststr(strSrc1, strMatch) == 9);
	cr_assert(strlaststr(strSrc2, strMatch) == -1);
}

// 4バイト確保されているメモリブロックに対し、下記の操作を行う関数を作成せよ(work19)
// ・メモリブロックの先頭から１バイトずつ、0x12, 034, 0x56, 0x78で埋める関数
// ・メモリブロックの先頭からbyteIndexバイト先のデータを読み出す関数(要:オーバーフロー検知)
// ・メモリブロックのチェックサムを計算する関数
Test(execise, 19) {
	const int dataSize = 4;
	unsigned char *memoryBlock = (unsigned char *)calloc(dataSize, sizeof(unsigned char));
	char data[] = { 0x12, 0x34, 0x56, 0x78 };

	setMemoryBlock( memoryBlock, data, dataSize );
	cr_assert(getByteMemory( memoryBlock, 2 ) == 0x56);
	cr_assert(checkSum( memoryBlock, dataSize ) == 0x14);

	free( memoryBlock );
}

// 与えられた文字列をアッパーキャメルに変換する関数(work20)
Test(execise, 20) {
	char str1[] = "abc";
	char str2[] = "a";
	char str3[] = "";

	convUpperCamel(str1);
	cr_assert(strcmp(str1, "Abc") == 0);
	convUpperCamel(str2);
	cr_assert(strcmp(str2, "A") == 0);
	convUpperCamel(str3);
	cr_assert(strcmp(str3, "") == 0);
}

// 下記構造体の要素ごとの総和を算出したデータを返す関数を作成せよ(work21)
Test(execise, 21) {
	PlayerParam param[] = {
		{1, 2, 3},
		{2, 1, 1},
		{0, 1, 7},
		{9, 3, 1},
		{2, 3, 1},
	};
	PlayerParam sumParam;

	int size = sizeof(param)/sizeof(PlayerParam);
	sumParam = sumPlayerParam(param, size);
	cr_assert(sumParam.win  == 14);
	cr_assert(sumParam.lose == 10);
	cr_assert(sumParam.draw == 13);
}

// 与えられた数字の2の補数を求める関数を作成・利用して、aからbを引く関数を作成せよ(work22)
Test(execise, 22) {
	cr_assert(complement2(5) == -5);
	cr_assert(complement2(7) == -7);
	cr_assert(complement2(0) == 0);
	cr_assert(complement2(-1) == 1);

	cr_assert(subUsedcomplement2(8, 2) == 6);
	cr_assert(subUsedcomplement2(5, -3) == 8);
	cr_assert(subUsedcomplement2(2, 5) == -3);
}

/* ### 第１引数のポインタのポインタに対して、下記の処理をせよ(work23) ###  
 * ・先頭要素(第1要素)のポインタをNULLにする
 * ・代わりに第2要素に関数の第２引数のポインタを格納せよ。
 */
Test(execise, 23) {
	int testData = 999;
	int *p = &testData;
	int *pPtr[] = {p, NULL, NULL};

	changePtrPtr(pPtr, p);
	cr_assert(pPtr[0] == NULL);	
	cr_assert(pPtr[1] != NULL);
	cr_assert(*pPtr[1] == 999);
}

/* ### 既存の「奇数を判定する関数」を用いて、与えられた２値間の奇数の個数を求める関数を作成せよ(work24) ### */
// 奇数を判定する関数。奇数なら1を、偶数なら0を返す
static int isOddNum(int num)
{
	int result = 0;

	if( num % 2 ){
		result = 1;
	}
	return( result ) ;
}

Test(execise, 24) {
	int (*func)(int num);

	func = isOddNum;

	cr_assert( checkOdd(0, 1, isOddNum) == 1);	
	cr_assert( checkOdd(0, 2, isOddNum) == 1);	
	cr_assert( checkOdd(0, 3, isOddNum) == 2);	
}

/* ### 配列の指定された要素へのポインタを返す関数を作成せよ。ただし、見つからなかった場合はNULLを返すこと(work25) ### */
Test(execise, 25) {
	int numVec[] = { 23, 4, 2, 11, 8, 99, 0 };
	int numVecSize = sizeof(numVec)/sizeof(int);
	int *p;

	p = searchItem(numVec, numVecSize, 99);
	cr_assert( p != NULL);
	cr_assert( p-numVec == 5);
	cr_assert( *p == 99);

	p = searchItem(numVec, numVecSize, 22);
	cr_assert( p == NULL);
}