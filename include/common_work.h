#define _ANSWER_

/* ### 整数値aとbの値をスワップさせるswap関数を作成せよ。(work01) ### */
#ifdef _ANSWER_
void swap( int *a, int *b );
#else
void swap( void );
#endif

/* ### strcpyを使わずに文字列をコピーする関数my_strcpyを作成せよ。(work02) ### */
void my_strcpy(char *dstStr, const char *srcStr);

/* ### 整数値を文字列に変換する関数int_to_strを作成せよ。(work03) ### */
char *int_to_str(int value);

/* ### 下記データを価格順(降順)にソートする関数を作成せよ。(work04) ### */
#define NAMELEN 20
typedef struct {
	int hb;             //品番
	char name[NAMELEN]; //商品名
	int price;          //価格
} Choco;

void sortPrice( Choco *list, int n );

/* ### 任意の人物たちの「名前」と「年齢」と次々リストに登録していき、最後にリスト一覧を表示せよ(work05) ### */
typedef struct memberlist{
	int key;			/* キー */
	char name[NAMELEN];		/* 名前 */
	struct memberlist *next;		/* 次のデータへのポインタ */
} MemberList;

MemberList *add_list(int key, char *name, MemberList *head);
void show_list(MemberList *p);
void free_list(MemberList *p);

/* ### 下記ビット配置のARGB8888フォーマットにおけるGreen値を抽出せよ(work6) ###
 * #define ARGB8888(a,r,g,b)  ((unsigned int)((((a) & 0xff)<<24) | (((r) & 0xff)<<16) | (((g) & 0xff)<<8) | ((b) & 0xff)))
 */
unsigned int PickupGreen(unsigned int argb);

/* ### 任意の文字のANSIキャラクタコード(16進)を得よ(work07) ### */
char *getItemCSV(const char *csvData, int index);

/* ### 曜日を示す文字列へのポインタを返す関数を作成せよ(work8) ### 
 * ただし日曜日を0とし、土曜日を6とする
 */
char *strweek(int n);

/* ### 呼ぶたびにパターンが点滅する関数を作成せよ(work9) ### */
unsigned int blinkPattern(unsigned int pattern);

/* ### 処理系ごとにint型のサイズが異なる。このシステムのint型のサイズを調べる関数を作成せよ(work10) ### */
int getIntByteSize(void);

/* ### data1の下位8bitを上位8bitとし、data2の上位8bitを下位8bitとしたビット列を反転した値を表示する関数を作成せよ(work11) ### */
unsigned short make16BitData(unsigned short data1, unsigned short data2);

/* ### 小数点以下を四捨五入する関数を自作せよ(work12) ### */
int myRound(double num);

/* ### 任意の数のポインターの配列を使って、それぞれに1バイト領域を割り当て、要素を0xbeで埋めたのち、解放せよ(work13) ### */
void allocMyArray(unsigned char **p, unsigned int num, unsigned short pattern); // 領域を割り当て、パターンで埋める
void freeMyArray(unsigned char **p, unsigned int num); // 割り当てた領域を解放する

/* ### 各種演算関数を作成せよ(work14) ### 
 * ・バイトデータを反転した値を得る関数
 * ・２つのバイトデータの排他的論理和を得る関数
 * ・任意のバイトデータを任意のバイトデータでビットマスクする関数
 * ・任意のバイトデータの任意のバイトデータのビットで強制的に有効にする関数
 */
unsigned char calcReverse(unsigned char val);
unsigned char calcXOR(unsigned char a, unsigned char b);
unsigned char calcBitMask(unsigned char a, unsigned char b);
unsigned char calcBitEnable(unsigned char a, unsigned char b);

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
unsigned char rotateLeft(unsigned char val);
unsigned char rotateRight(unsigned char val);

/* ### 文字列strSrcの中から文字列strMatcを探し、その最後にみつけた位置を返す関数を作成する。(work18) ###
 * ・見つからなかったら-1を返すこと。strstr関数を使用して良い
 */
int strlaststr(char *strSrc, char *strMatch);

/* ### dataSizeバイト確保されているメモリブロックに対し、下記の操作を行う関数を作成せよ(work19) ###
 * ・メモリブロックの先頭から１バイトずつ、0x12, 034, 0x56, 0x78で埋める関数
 * ・メモリブロックの先頭からbyteIndexバイト先のデータを読み出す関数
 * ・メモリブロックのチェックサムを計算する関数
 */
void setMemoryBlock( unsigned char *memoryBlock, unsigned char *data, int dataSize );
unsigned char getByteMemory( unsigned char *memoryBlock, int byteIndex );
unsigned char checkSum( unsigned char *memoryBlock, int num );

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
int complement2( int data );
int subUsedcomplement2(int a, int b);

/* ### 第１引数のポインタのポインタに対して、下記の処理をする関数を作成せよ(work23) ###  
 * ・先頭要素(第1要素)のポインタをNULLにする
 * ・代わりに第2要素に関数の第２引数のポインタを格納する
 */
void changePtrPtr(int **pPtr, int *p);

/* ### 既存の「奇数を判定する関数」を用いて、与えられた２値間の奇数の個数を求める関数を作成せよ(work24) ### */
int checkOdd(int startNum, int endNum, int (*func)(int num));

/* ### 配列の指定された要素へのポインタを返す関数を作成せよ。ただし、見つからなかった場合はNULLを返すこと(work25) ### */
int *searchItem( int vec[], int vecSize, int matchNumber );

/* ### 下記２値乗算ができるように、void *を引数とするmulVoidPtr関数の実装をしなさい(work26) ### */
double mulVoidPtr( void *a, void *b );

/* ### 下記関数をつかって数学ライブラリを用いずに3乘を求める関数を作成せよ。(work27) ### */
double cubeFunc(double num);

/* ### 文字列の長さを返す関数を作成せよ。ただしNULLの場合は0を返すようにすること(work28) ### */
int getLength(const char *string);

/* ### 10バイトのメモリを確保し0x11で埋めよ。さらに先頭3バイトを0x55で埋めよ(work29) ### */
unsigned char *allocBlock(int blockSize, unsigned char fillData);
void fillBlock(unsigned char* memBlock, int startFillByte, int endFillByte, unsigned char fillData);

/* ### エンディアンを調べる関数を作成せよ。ただし処理系によるint幅に依存しないこと(work30) ### */
int isBigEndian(void);