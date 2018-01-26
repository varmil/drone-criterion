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

/* ### data1の下位8bitを上位8bitとし、data2の上位8bitを下位8bitとしたビット列を
 * 反転した値を表示する関数を作成せよ(work11) ### */
unsigned short make16BitData(unsigned short data1, unsigned short data2);

 /* ### 小数点以下を四捨五入する関数を自作せよ(work12) ### */
int myRound(double num);

/* ### 任意の数のポインターの配列を使って、それぞれに1バイト領域を割り当て、要素を0xbeで埋めたのち、解放せよ(work13) ### */
void allocMyArray( unsigned char **p, unsigned int num, unsigned short pattern);
void freeMyArray( unsigned char **p, unsigned int num);

/* ### 各種演算関数を作成せよ(work14) ### */
unsigned char calcReverse(unsigned char val);
unsigned char calcXOR(unsigned char a, unsigned char b);
unsigned char calcBitMask(unsigned char a, unsigned char b);
unsigned char calcBitEnable(unsigned char a, unsigned char b);
void calcIncrement(unsigned char *val);
void calcDecrement(unsigned char *val);

/**/
int searchChar(unsigned char *str, unsigned char chara);