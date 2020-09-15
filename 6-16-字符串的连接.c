/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-16-字符串的连接.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月10日
*   Description ：
6-16 字符串的连接 (15 point(s))
本题要求实现一个函数，将两个字符串连接起来。

函数接口定义：
char *str_cat( char *s, char *t );
函数str_cat应将字符串t复制到字符串s的末端，并且返回字符串s的首地址。

裁判测试程序样例：
#include <stdio.h>
#include <string.h>

#define MAXS 10

char *str_cat( char *s, char *t );

int main()
{
    char *p;
    char str1[MAXS+MAXS] = {'\0'}, str2[MAXS] = {'\0'};

    scanf("%s%s", str1, str2);
    p = str_cat(str1, str2);
    printf("%s\n%s\n", p, str1);

    return 0;
}

// 你的代码将被嵌在这里
输入样例：
abc
def
输出样例：
abcdef
abcdef
================================================================*/
#include <stdio.h>
#include <string.h>

#define MAXS 10

char *str_cat( char *s, char *t );

int main()
{
    char *p;
    char str1[MAXS+MAXS] = {'\0'}, str2[MAXS] = {'\0'};

    scanf("%s%s", str1, str2);
    p = str_cat(str1, str2);
    printf("%s\n%s\n", p, str1);

    return 0;
}

// 以下是有效代码
char* str_cat( char *s, char *t ) {
    char* p = s;
    while (*s != '\0')
        ++ s;

    while (*t != '\0') {
        *s = *t;
        ++s, ++t;
    }

    s = p;
    return p;
}
