#include <criterion/criterion.h>
#include <string.h>

#include "work01.h"
#include "work02.h"
#include "work03.h"

// 整数値aとbの値をスワップさせるswap関数を作成せよ。(work01)
Test(execise, 1) {
    int a = 10, b = 20;

    swap(&a, &b);

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
    cr_assert(strcmp(int_to_str(100),   "100") == 0, "string convert error");
    cr_assert(strcmp(int_to_str(-555), "-555") == 0, "string convert error");
}
