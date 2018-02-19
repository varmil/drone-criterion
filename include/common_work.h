#include<stddef.h>

#define _ANSWER_

/* ### 整数値aとbの値を入れ替える関数を作成せよ。(work01) ### */
void change();

/* ### 小文字を大文字に変換しつつ、文字列をコピーする関数my_strcpyを作成せよ。ただし標準関数は使用しないこと。(work02)　### */
void my_strcpy();

/* ### 整数値を文字列に変換する関数int_to_strを作成せよ。(work03) ### */
char *int_to_str(int value);

/* ### 下記データを価格の高い順にソートする関数を作成せよ。(work04) ### */
#define NAMELEN 20
typedef struct {
	int hb;             // 品番
	char name[NAMELEN]; // 商品名
	int price;          // 価格
} Juice;

void sortPrice(Juice *list, int n);

/* ### 任意の人物の「名前」と「年齢」を次々リストに登録する関数と、リストを解放する関数を作成せよ。(work05) ### 
 * ただし、リストの末尾の次の要素はNULLとする。
 */
typedef struct memberlist{
	int key;				// キー
	char name[NAMELEN];		// 名前 
	struct memberlist *next;// 次のデータへのポインタ
} MemberList;

MemberList *add_list(int key, char *name, MemberList *head); // メンバーをリストに登録する関数
void free_list(MemberList *p); // リストを解放する関数

/* ### 下記ビット配置のARGB8888フォーマットにおけるGreen値を抽出する関数を作成せよ(work6) ### */
// #define ARGB8888(a,r,g,b)  ((unsigned int)((((a) & 0xff)<<24) | (((r) & 0xff)<<16) | (((g) & 0xff)<<8) | ((b) & 0xff)))
unsigned int PickupGreen(unsigned int argb);

/* ### カンマ区切りの文字列データのn番目の要素(文字列)を取り出す関数を作成せよ(work7) ### */
char *getItemCSV(const char *csvData, int index);

/* ### 曜日を示す文字列へのポインタを返す関数を作成せよ(work8) ### 
 * ただし日曜日を0とし、土曜日を6とするパラメータを渡すとする。
 */
char *strweek(int n);

/* ### 32ビットデータ列のnビット目からmビット目までを抽出する関数を作成せよ。ただしn<=mであり、LSB=0ビット目とする(work9) ### */
unsigned int getSubBit(unsigned int baseData, int n, int m);

/* ### このシステムにおける各種型サイズを調べ、結果を構造体で返す関数を作成せよ(work10) ### */
typedef struct typesize{
	char charSize;		// char型のサイズ
	int charPtrSize;	// char*型のサイズ
	int shortSize;		// short int型のサイズ
	int shortPtrSize;	// short*型のサイズ
	int intSize;		// int型のサイズ
	int intPtrSize;		// int*型のサイズ
	int longSize;		// long int型のサイズ
	int longPtrSize;	// long*型のサイズ
	int floatSize;		// float型のサイズ
	int floatPtrSize;	// float*型のサイズ
	int doubleSize;		// double型のサイズ
	int doublePtrSize;	// double*型のサイズ
	int thisStructPtrSize;  // この構造体へのポインタのサイズ
	int thisStructSize; 	// この構造体のサイズ
} TypeSize;

TypeSize getTypeSize(void);

/* ### 下記の方法で生成した16bitデータを返す関数を作成せよ(work11) ### 
 * 1. 16bitデータであるdata1の下位8bitを上位8bitとし、かつ同じく16bitデータであるdata2の上位8bitを下位8bitとする、新規16bitデータを生成する
 * 2. 1.で生成した16bitデータを反転する。
 * 3. 結果は下位16bitだけ返すこと */
unsigned int make16BitReverseData(unsigned int data1, unsigned int data2);

/* ### 0.1刻みでカウントダウンする関数を作成せよ。また初期値を設定する関数も作成すること(work12) ### */
void resetCount(double iniVal); // 初期値設定
double countDown(void); // 0.1刻みでカウントダウンする関数

/* ### 任意の数のポインターの配列を使ってそれぞれに1バイト領域を割り当て、各要素をtestByteで埋めたのち、解放せよ(work13) ### */
void allocMyArray(unsigned char **p, unsigned int num, unsigned short pattern); // 領域を割り当て、パターンで埋める
void freeMyArray(unsigned char **p, unsigned int num); // 割り当てた領域を解放する

/* ### 各種演算関数を作成せよ(work14) ### 
 * ・バイトデータを反転した値を得る関数
 * ・２つのバイトデータの排他的論理和を得る関数
 * ・任意のバイトデータを任意のバイトデータでビットマスクする関数
 * ・任意のバイトデータの任意のバイトデータのビットで強制的に有効にする関数
 */
unsigned char calcReverse(unsigned char val); // バイトデータを反転
unsigned char calcXOR(unsigned char a, unsigned char b); // バイトデータ同士の排他的論理和
unsigned char calcBitMask(unsigned char a, unsigned char b); // ビットマスク
unsigned char calcBitEnable(unsigned char a, unsigned char b); // 任意のビットの有効化

/* ### 文字列から任意の文字が初めて出現する位置を求める関数を作成せよ(work15) ### */
int searchChar(unsigned char *str, unsigned char chara);

/* ### 下記データ構造における各関数を作成せよ(work16) ### 
 * ・全生徒の科目別の平均点を得る関数
 * ・全生徒、全科目の平均点を得る関数
 * ・生徒名から、その生徒の成績データ全体(grade構造体へのポインタ)を得る関数
 */
typedef enum SUBJECT{
	ENGLISH,
	FRANCH,
	JAPANESE,
	CHINESE,

	SUBJECT_MAX
}Subject;

typedef struct grade{
	int subjects[SUBJECT_MAX]; // 科目
} Grade;

typedef struct student{
	char name[NAMELEN]; // 名前
	Grade grade;        // 成績
} Student;

int calcSubjectAverage(Student *students, int num, Subject subject); // 科目別の平均点(ただし、小数点以下は切り捨てる)
int calcAllAverage(Student *students, int num); // 全生徒の平均点(ただし、小数点以下は切り捨てる)
Grade *getGrade(Student *students, int num, char *studentName); // 任意の生徒の成績データ全体を得る

/* ### キャリーなし左右ローテート関数を作り、ビットパターンが1ビットずつ移動するアニメーションを作成せよ(work17) ### 
 * ただし、処理系が算術シフト、論理シフトいずれを採用していても結果が変わらないように注意せよ
 */
unsigned char rotateLeft(unsigned char val); // 左ローテート関数
unsigned char rotateRight(unsigned char val); // 右ローテート関数

/* ### 文字列strSrcの中から文字列strMatcを探し、その最後にみつけた位置を返す関数を作成する。(work18) ###
 * ・見つからなかったら-1を返すこと。strstr関数を使用して良い
 */
int strlaststr(char *strSrc, char *strMatch);

/* ### dataSizeバイト確保されているメモリブロックに対し、下記の操作を行う関数を作成せよ(work19) ###
 * ・メモリブロックの先頭から１バイトずつ、任意のデータで埋める関数
 * ・メモリブロックの先頭からbyteIndexバイト先のデータを読み出す関数
 * ・メモリブロックのチェックサムを計算する関数
 */
void setMemoryBlock(unsigned char *memoryBlock, unsigned char *data, int dataSize); // メモリブロック任意のデータで埋める
unsigned char getByteMemory(unsigned char *memoryBlock, int byteIndex); // メモリブロックの任意の位置のデータを得る関数
unsigned char checkSum(unsigned char *memoryBlock, int num); // メモリブロックのチェックサム計算

/* ### 与えられた文字列をアッパーキャメルに変換する関数(work20) ### */
void convUpperCamel(char *str);

/* ### 下記構造体の要素ごとの総和を算出したデータを返す関数を作成せよ(work21) ### */
typedef struct playerParam{
	int win;
	int lose;
	int draw;
} PlayerParam;

PlayerParam sumPlayerParam(PlayerParam *data, int dataNum);

/* ### 与えられた数字の2の補数を求める関数を作成・利用して、aからbを引く関数を作成せよ(work22) ### */
int complement2(int data); // ２の補数を得る
int subUsedcomplement2(int a, int b); // 上記関数を用いてa-bを計算する関数

/* ### 第１引数のポインタのポインタに対して、下記の処理をする関数を作成せよ(work23) ###  
 * ・先頭要素(第1要素)のポインタをNULLにする
 * ・代わりに第2要素に関数の第２引数のポインタを格納する
 */
void changePtrPtr(int **pPtr, int * const p);

/* ### 既存の「奇数を判定する関数」を用いて、与えられた２値間の奇数の個数を求める関数を作成せよ(work24) ### */
int checkOdd(int startNum, int endNum, int (*func)(int num));

/* ### 配列の中から指定された数字と同じ要素を探し、その要素へのポインタを返す関数を作成せよ。ただし、見つからなかった場合はNULLを返すこと(work25) ### */
int *searchItem(int vec[], int vecSize, int matchNumber);

/* ### 下記２値で乗算ができるように、void *を引数とするmulVoidPtr関数の実装をしなさい(work26) ### */
double mulVoidPtr(void *a, void *b);

/* ### 下記関数をつかって数学ライブラリを用いずに3乘を求める関数を作成せよ。ただし、小数点以下は四捨五入すること(work27) ### */
int cubeFunc(double num);

/* ### strlenを用いずに文字列の長さを返す関数を作成せよ。ただしNULLの場合は0を返すようにすること(work28) ### */
int getLength(const char *string);

/* ### blockSize分のメモリを確保しbasePatternで埋めよ。さらに先頭startByte目からendByte目までをsubPatternで埋めよ(work29) ### */
unsigned char *allocBlock(int blockSize, unsigned char basePattern); // basePatternで埋めたメモリブロックを割り当て
void fillBlock(unsigned char* memBlock, int startFillByte, int endFillByte, unsigned char subPattern); // メモリブロックの任意の場所を指定したパターンで埋め直す

/* ### エンディアンを調べる関数を作成せよ。ただし処理系によるint幅に依存しないこと(work30) ### */
int isBigEndian(void);