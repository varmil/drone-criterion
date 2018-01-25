#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_work.h"

MemberList* add_list(int key, char *name, MemberList *head)
{
#ifdef _ANSWER_
	MemberList *p;
	
	/* 記憶領域の確保 */
	if ((p = (MemberList *) malloc(sizeof(MemberList))) == NULL) {
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}
	
	/* リストにデータを登録 */
	p->key = key;
	strcpy(p->name, name);
	
	if( head==NULL ){ // ヘッダ要素なければ追加
		head = p;
		p->next = NULL;
	}
	else{
		// 末尾探索
		MemberList *itr = head;
		while( itr->next != NULL ){
			itr = itr->next;
		}
		// 要素追加
		itr->next = p;
		p->next = NULL;
	}
#else

#endif
	return head;
}

void free_list(MemberList *p)
{
#ifdef _ANSWER_
	MemberList *p2;

	while (p != NULL) {     /* 次ポインタがNULLまで処理 */
		p2 = p->next;
		free(p);
		p = p2;
	}
#endif
}

void show_list(MemberList *p)
{
#ifdef _ANSWER_
	while (p != NULL) {	/* 次ポインタがNULLまで処理 */
		printf("%3d %s\n", p->key, p->name);
		p = p->next;
	}
#endif
}
