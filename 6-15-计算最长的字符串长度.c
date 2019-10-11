/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-15-计算最长的字符串长度.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月10日
*   Description ：
6-15 计算最长的字符串长度 (15 point(s))
本题要求实现一个函数，用于计算有n个元素的指针数组s中最长的字符串的长度。

函数接口定义：
int max_len( char *s[], int n );
其中n个字符串存储在s[]中，函数max_len应返回其中最长字符串的长度。

裁判测试程序样例：
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 10
#define MAXS 20

int max_len( char *s[], int n );

int main()
{
    int i, n;
    char *string[MAXN] = {NULL};

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        string[i] = (char *)malloc(sizeof(char)*MAXS);
        scanf("%s", string[i]);
    }
    printf("%d\n", max_len(string, n));

    return 0;
}

// 你的代码将被嵌在这里 
输入样例：
4
blue
yellow
red
green
输出样例：
6
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 10
#define MAXS 20

int max_len( char *s[], int n );

int main()
{
    int i, n;
    char *string[MAXN] = {NULL};

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        string[i] = (char *)malloc(sizeof(char)*MAXS);
        scanf("%s", string[i]);
    }
    printf("%d\n", max_len(string, n));

    return 0;
}
// 以下是有效代码
int max_len( char *s[], int n ) {
    size_t max_len = 0;
    for (int i = 0; i < n; i ++) {
        if (strlen(s[i]) > max_len)
            max_len = strlen(s[i]);
    }

    return max_len;
}
