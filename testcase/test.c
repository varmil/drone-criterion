#include <criterion/criterion.h>
#include "common_work.h"

#include<stdio.h>

/* ### 整数値aとbの値を入れ替える関数を作成せよ。(work01) ### */
Test(execise, 1) {
	int a, b;

	a = 10; b = 20;
	change(&a, &b);
	cr_assert(a == 20);
	cr_assert(b == 10);

	a = 27; b = 9;
	change(&a, &b);
	cr_assert(a == 9);
	cr_assert(b == 27);
}

/* ### 小文字を大文字に変換しつつ、文字列をコピーする関数my_strcpyを作成せよ。ただし標準関数は使用しないこと。(work02)　### */
Test(execise, 2) {
	char dstStr[] = "";
    
	my_strcpy(dstStr, "Cygames");
	cr_assert(strcmp(dstStr, "CYGAMES") == 0);

	my_strcpy(dstStr, "JavaScript");
	cr_assert(strcmp(dstStr, "JAVASCRIPT") == 0);
}

/* ### 整数値を文字列に変換する関数int_to_strを作成せよ。(work03) ### */
Test(execise, 3) {
	cr_assert(int_to_str(100) != NULL);
	cr_assert(strcmp(int_to_str(100), "100") == 0);
	cr_assert(strcmp(int_to_str(-550045), "-550045") == 0);
}

/* ### 下記データを価格の高い順にソートする関数を作成せよ。(work04) ### */
Test(execise, 4) {
	Juice list[] = {
		{ 5200, "オレンジ", 1000 }, { 3010, "アップル", 840 },
		{ 2020, "パイナップル", 525 }, { 3020, "グレープ", 720 },
		{ 2030, "レモン", 500 }, { 2010, "トマト", 450 },
		{ 5050, "ドリアン", 1200 }
	};

	sortPrice(list, sizeof(list)/sizeof(Juice));

	cr_assert(strcmp(list[0].name, "ドリアン") == 0);
	cr_assert(strcmp(list[1].name, "オレンジ") == 0);
	cr_assert(strcmp(list[2].name, "アップル") == 0);
	cr_assert(strcmp(list[3].name, "グレープ") == 0);
	cr_assert(strcmp(list[4].name, "パイナップル") == 0);
	cr_assert(strcmp(list[5].name, "レモン") == 0);
	cr_assert(strcmp(list[6].name, "トマト") == 0);
}

/* ### 任意の人物の「名前」と「年齢」を次々リストに登録する関数と、リストを解放する関数を作成せよ。(work05) ### 
 * ただし、リストの末尾の次の要素はNULLとする。
 */
Test(execise, 5) {
	MemberList *head = NULL; /* 先頭ポインタ */
	char *name[] = {
		"ashihara", "matsuo", "yamamoto", "kuwata" 
	};	
	int num = sizeof(name)/sizeof(*name);
	int indexNo;

	for(indexNo = 0 ; indexNo < num ; indexNo++){
		head = add_list(indexNo, name[indexNo], head);
	}

	MemberList *p = head;
	cr_assert(head !=  NULL);
	cr_assert(strcmp(p->name, "ashihara") == 0); p = p->next;
	cr_assert(strcmp(p->name, "matsuo") == 0); 	 p = p->next;
	cr_assert(strcmp(p->name, "yamamoto") == 0); p = p->next;
	cr_assert(strcmp(p->name, "kuwata") == 0);
	cr_assert(head->next->next->next->next == NULL);

	/* リストの開放 */
	free_list(head);
}

/* ### 下記ビット配置のARGB8888フォーマットにおけるGreen値を抽出する関数を作成せよ(work6) ### */
#define ARGB8888(a,r,g,b)  ((unsigned int)((((a) & 0xff)<<24) | (((r) & 0xff)<<16) | (((g) & 0xff)<<8) | ((b) & 0xff)))

Test(execise, 6) {
	unsigned int argbColor;
	unsigned int colorG;

	argbColor = ARGB8888(0x12, 0x34, 0x56, 0x78);
	colorG = 0x00;
	colorG = PickupGreen(argbColor);
	cr_assert(colorG == 0x56);

	argbColor = ARGB8888(0x98, 0x76, 0x54, 0x32);
	colorG = 0x00;
	colorG = PickupGreen(argbColor);
	cr_assert(colorG == 0x54);
}

/* ### カンマ区切りの文字列データのn番目の要素(文字列)を取り出す関数を作成せよ(work7) ### */
Test(execise, 7) {
	const char csvData[]="SQL,C,PHP,JavaScript,Linux,HTML,bash";
	char *copyStr = (char *)malloc(sizeof(csvData));
	char *itemStr;

	strcpy(copyStr, csvData);
	itemStr = getItemCSV(copyStr, 0);
	cr_assert(itemStr != NULL);
	cr_assert(strcmp(itemStr, "SQL") == 0);
	strcpy(copyStr, csvData);
	itemStr = getItemCSV(copyStr, 5);
	cr_assert(itemStr != NULL);
	cr_assert(strcmp(itemStr, "HTML") == 0);

	free(copyStr);
}

/* ### 曜日を示す文字列へのポインタを返す関数を作成せよ(work8) ### 
 * ただし日曜日を0とし、土曜日を6とするパラメータを渡すとする。
 */
Test(execise, 8) {
	cr_assert(strcmp(strweek(0), "Sunday") == 0);
	cr_assert(strcmp(strweek(6), "Saturday") == 0);
}

/* ### 32ビットデータ列のnビット目からmビット目までを抽出する関数を作成せよ。ただしn<=mであり、LSB=0ビット目とする(work9) ### */
Test(execise, 9) {
	cr_assert(getSubBit(0x12345678, 0, 0) == 0x0);
	cr_assert(getSubBit(0x12345678, 3, 3) == 0x1);
	cr_assert(getSubBit(0x12345678, 4, 7) == 0x7);
	cr_assert(getSubBit(0x12345678, 24, 31) == 0x12);
	cr_assert(getSubBit(0x12345678, 0, 31) == 0x12345678);
}

/* ### このシステムにおける各種型サイズを調べ、結果を構造体で返す関数を作成せよ(work10) ### */
Test(execise, 10) {
	TypeSize ts = getTypeSize();

	cr_assert(ts.charSize == 1);
	cr_assert(ts.charPtrSize == 8);
	cr_assert(ts.shortSize == 2);
	cr_assert(ts.shortPtrSize == 8);
	cr_assert(ts.intSize == 4);
	cr_assert(ts.intPtrSize == 8);
	cr_assert(ts.longSize == 8);
	cr_assert(ts.longPtrSize == 8);
	cr_assert(ts.floatSize == 4);
	cr_assert(ts.floatPtrSize == 8);
	cr_assert(ts.doubleSize == 8);
	cr_assert(ts.doublePtrSize == 8);
	cr_assert(ts.thisStructPtrSize == 8);
	cr_assert(ts.thisStructSize == 56);
}

/* ### 下記の方法で生成した16bitデータを返す関数を作成せよ(work11) ### 
 * 1. 16bitデータであるdata1の下位8bitを上位8bitとし、かつ同じく16bitデータであるdata2の上位8bitを下位8bitとする、新規16bitデータを生成する
 * 2. 1.で生成した16bitデータを反転する。
 * 3. 結果は下位16bitだけ返すこと */
Test(execise, 11) {
	cr_assert(make16BitReverseData(0xabcd, 0x1234) == 0x32ed);
	cr_assert(make16BitReverseData(0x00ff, 0xff00) == 0x0000);
	cr_assert(make16BitReverseData(0xff00, 0x00ff) == 0xffff);
}

/* ### 0.1刻みでカウントダウンする関数を作成せよ。また初期値を設定する関数も作成すること(work12) ### */
Test(execise, 12) {
	resetCount(1.0f);

	cr_assert(countDown() == 0.9f);
	cr_assert(countDown() == 0.8f);
	cr_assert(countDown() == 0.7f);
	cr_assert(countDown() == 0.6f);
	cr_assert(countDown() == 0.5f);
	cr_assert(countDown() == 0.4f);
	cr_assert(countDown() == 0.3f);
	cr_assert(countDown() == 0.2f);
	cr_assert(countDown() == 0.1f);
	cr_assert(countDown() == 0.0f);
}

/* ### 任意の数のポインターの配列を使ってそれぞれに1バイト領域を割り当て、各要素をtestByteで埋めたのち、解放せよ(work13) ### */
#define ARRAY_NUM   3

Test(execise, 13) {
	unsigned char *p[ARRAY_NUM] = {NULL, NULL, NULL};
	unsigned char testByte = 0xbe;

	allocMyArray(p, ARRAY_NUM, testByte);

	cr_assert(p[0] != NULL);
	cr_assert(p[1] != NULL);
	cr_assert(p[2] != NULL);

	cr_assert(*p[0] == testByte);
	cr_assert(*p[1] == testByte);
	cr_assert(*p[2] == testByte);

	freeMyArray(p, ARRAY_NUM);
}

/* ### 各種演算関数を作成せよ(work14) ### 
 * ・バイトデータを反転した値を得る関数
 * ・２つのバイトデータの排他的論理和を得る関数
 * ・任意のバイトデータを任意のバイトデータでビットマスクする関数
 * ・任意のバイトデータの任意のバイトデータのビットで強制的に有効にする関数
 */
Test(execise, 14) {
	unsigned char a = 0xc5;
	unsigned char b = 0x96;

	cr_assert(calcReverse(a) == 0x3a); // 反転
	cr_assert(calcXOR(a, b) == 0x53); // 排他的論理和
	cr_assert(calcBitMask(a, b) == 0x84); // ビットマスク
	cr_assert(calcBitEnable(a, b) == 0xd7); // 特定ビットを常に有効にする
}

/* ### 文字列から任意の文字が初めて出現する位置を求める関数を作成せよ(work15) ### */
Test(execise, 15) {
	char testStr[] = "abcdefghijklm";

	cr_assert(searchChar(testStr, 'd') == 3);
	cr_assert(searchChar(testStr, 'm') == 12);
	cr_assert(searchChar(testStr, '@') == -1);  // 不正文字
}

/* ### 下記データ構造における各関数を作成せよ(work16) ### 
 * ・全生徒の科目別の平均点を得る関数
 * ・全生徒、全科目の平均点を得る関数
 * ・生徒名から、その生徒の成績データ全体(grade構造体へのポインタ)を得る関数
 */
Test(execise, 16) {
	Student students[]={
		{"yamamoto",{100,100,100,100}},
		{"kuwata",	{ 10, 20, 30, 40}},
		{"iggy",	{ 12, 34, 56, 78}},
	};

	int num = sizeof(students)/sizeof(Student);
	cr_assert(calcSubjectAverage(students, num, JAPANESE) == 62);
	cr_assert(calcAllAverage(students, num) == 56);
	Grade *grade = getGrade(students, num, "kuwata");
	cr_assert(grade != NULL);
//	if(grade){
		cr_assert(grade->subjects[ENGLISH] == 10);
//	}
}

/* ### キャリーなし左右ローテート関数を作り、ビットパターンが1ビットずつ移動するアニメーションを作成せよ(work17) ### 
 * ただし、処理系が算術シフト、論理シフトいずれを採用していても結果が変わらないように注意せよ
 */
Test(execise, 17) {
	unsigned char data;

	// ビットパターン左移動
	data = 0x81;
	data = rotateLeft(data);
	cr_assert(data == 0x03);
	data = rotateLeft(data);
	cr_assert(data == 0x06);
	data = rotateLeft(data);
	cr_assert(data == 0x0c);

	// ビットパターン右移動
	data = 0x81;
	data = rotateRight(data);
	cr_assert(data == 0xc0);
	data = rotateRight(data);
	cr_assert(data == 0x60);
	data = rotateRight(data);
	cr_assert(data == 0x30);
}

/* ### 文字列strSrcの中から文字列strMatcを探し、その最後にみつけた位置を返す関数を作成する。(work18) ###
 * ・見つからなかったら-1を返すこと。strstr関数を使用して良い
 */
Test(execise, 18) {
	char *strSrc1 = "abcdefdefdef"; // 探索文字列その1
	char *strSrc2 = "a"; // 探索文字列その2
	char *strMatch = "def"; // マッチング対象文字列

	cr_assert(strlaststr(strSrc1, strMatch) == 9);
	cr_assert(strlaststr(strSrc2, strMatch) == -1);
}

/* ### dataSizeバイト確保されているメモリブロックに対し、下記の操作を行う関数を作成せよ(work19) ###
 * ・メモリブロックの先頭から１バイトずつ、0x12, 034, 0x56, 0x78で埋める関数
 * ・メモリブロックの先頭からbyteIndexバイト先のデータを読み出す関数
 * ・メモリブロックのチェックサムを計算する関数
 */
Test(execise, 19) {
	const int dataSize = 4;
	unsigned char *memoryBlock = (unsigned char *)calloc(1, sizeof(unsigned char)*dataSize);
	char data[] = { 0x12, 0x34, 0x56, 0x78 };

	setMemoryBlock(memoryBlock, data, dataSize);
	cr_assert(getByteMemory(memoryBlock, 2) == 0x56);
	cr_assert(checkSum(memoryBlock, dataSize) == 0x14);

	free(memoryBlock);
}

/* ### 与えられた文字列をアッパーキャメルに変換する関数(work20) ### */
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

/* ### 下記構造体の要素ごとの総和を算出したデータを返す関数を作成せよ(work21) ### */
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

/* ### 与えられた数字の2の補数を求める関数を作成・利用して、aからbを引く関数を作成せよ(work22) ### */
Test(execise, 22) {
	cr_assert(complement2(5) == -5);
	cr_assert(complement2(7) == -7);
	cr_assert(complement2(0) == 0);
	cr_assert(complement2(-1) == 1);

	cr_assert(subUsedcomplement2(8, 2) == 6);
	cr_assert(subUsedcomplement2(5, -3) == 8);
	cr_assert(subUsedcomplement2(2, 5) == -3);
}

/* ### 第１引数のポインタのポインタに対して、下記のポインタ処理をする関数を作成せよ(work23) ###  
 * ・先頭要素(第1要素)のポインタをNULLにする
 * ・代わりに第2要素に関数の第２引数のポインタを格納する
 */
Test(execise, 23) {
	int testData = 999;
	int * const p = &testData;
	int *pPtr[] = {p, NULL};

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

	if(num % 2){
		result = 1;
	}
	return(result);
}

Test(execise, 24) {
	int (*func)(int num);

	func = isOddNum;

	cr_assert(checkOdd(0, 1, isOddNum) == 1);	
	cr_assert(checkOdd(0, 2, isOddNum) == 1);	
	cr_assert(checkOdd(0, 3, isOddNum) == 2);
	cr_assert(checkOdd(5, 10, isOddNum) == 3);
}

/* ### 配列の中から指定された数字と同じ要素を探し、その要素へのポインタを返す関数を作成せよ。ただし、見つからなかった場合はNULLを返すこと(work25) ### */
Test(execise, 25) {
	int numVec[] = {23, 4, 2, 11, 8, 99, 0};
	int numVecSize = sizeof(numVec)/sizeof(int);
	int *p;

	p = searchItem(numVec, numVecSize, 99); // 配列データから99の要素を探す
	cr_assert(p != NULL);
	cr_assert(p-numVec == 5); // 配列中の位置を調べる
	cr_assert(*p == 99); // 内容は確かに99

	p = searchItem(numVec, numVecSize, 4); // 配列データから4の要素を探す
	cr_assert(p != NULL);
	cr_assert(p-numVec == 1); // 配列中の位置を調べる
	cr_assert(*p == 4); // 内容は確かに4

	p = searchItem(numVec, numVecSize, 22); // 存在しない数字
	cr_assert(p == NULL);
}

/* ### 下記２値で乗算ができるように、void *を引数とするmulVoidPtr関数の実装をしなさい(work26) ### */
Test(execise, 26) {
	double a;
	int b;
	
	a = 2.5; b = 4;
	cr_assert(mulVoidPtr(&a, &b) == 10.0);

	a = 5.5; b = 3;
	cr_assert(mulVoidPtr(&a, &b) == 16.5);
}

/* ### 下記関数をつかって数学ライブラリを用いずに3乘を求める関数を作成せよ。ただし、小数点以下は四捨五入すること(work27) ### */
double cubeDouble(double num)
{
	return(num * num * num);
}

Test(execise, 27) {
	cr_assert(cubeFunc(2) == 8);
	cr_assert(cubeFunc(5) == 125);
	cr_assert(cubeFunc(2.5) == 16);
}

/* ### strlenを用いずに文字列の長さを返す関数を作成せよ。ただしNULLの場合は0を返すようにすること(work28) ### */
Test(execise, 28) {
	cr_assert(getLength("abc") == 3);
	cr_assert(getLength("") == 0);
	cr_assert(getLength(NULL) == 0);
}

/* ### blockSize分のメモリを確保しbasePatternで埋めよ。さらに先頭startByte目からendByte目までをsubPatternで埋めよ(work29) ### */
Test(execise, 29) {
	unsigned char basePattern = 0x11;
	int blockSize = 10;
	unsigned char *memBlock = allocBlock(blockSize, basePattern);

	cr_assert(memBlock != NULL);

	int startByte = 3;
	int endByte = 5;
	unsigned char subPattern = 0x55;

	fillBlock(memBlock, startByte, endByte, subPattern);
	cr_assert(*(memBlock+0) == basePattern);
	cr_assert(*(memBlock+1) == basePattern);
	cr_assert(*(memBlock+2) == subPattern);
	cr_assert(*(memBlock+3) == subPattern);
	cr_assert(*(memBlock+4) == subPattern);
	cr_assert(*(memBlock+5) == basePattern);

	free(memBlock);
}

/* ### エンディアンを調べる関数を作成せよ。ただし処理系によるint幅に依存しないこと(work30) ### */
Test(execise, 30) {
	cr_assert(isBigEndian() == 0);
}