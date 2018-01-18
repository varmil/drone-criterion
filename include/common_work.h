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

/* ### 任意の人物たちの「名前」と「年齢」と次々リストに登録していき
 * 最後に一覧を表示せよ(work05) ### */
typedef struct memberlist{
	int key;			/* キー */
	char name[NAMELEN];		/* 名前 */
	struct memberlist *next;		/* 次のデータへのポインタ */
} MemberList;

MemberList *add_list(int key, char *name, MemberList *head);
void show_list(MemberList *p);
void free_list(MemberList *p);