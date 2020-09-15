/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-17-指定位置输出字符串.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月15日
*   Description ：
        6-17 指定位置输出字符串 (20 point(s))
        本题要求实现一个函数，对给定的一个字符串和两个字符，打印出给定字符串中从与第一个字符匹配的位置开始到与第二个字符匹配的位置之间的所有字符。
        
        函数接口定义：
        char *match( char *s, char ch1, char ch2 );
        函数match应打印s中从ch1到ch2之间的所有字符，并且返回ch1的地址。
        
        裁判测试程序样例：
        #include <stdio.h>
        
        #define MAXS 10
        
        char *match( char *s, char ch1, char ch2 );
        
        int main()
        {
            char str[MAXS], ch_start, ch_end, *p;
        
            scanf("%s\n", str);
            scanf("%c %c", &ch_start, &ch_end);
            p = match(str, ch_start, ch_end);
            printf("%s\n", p);
        
            return 0;
        }
        
        // 你的代码将被嵌在这里
        输入样例1：
        program
        r g
        输出样例1：
        rog
        rogram
        输入样例2：
        program
        z o
        输出样例2：
        (空行)
        (空行)
        输入样例3：
        program
        g z
        输出样例3：
        gram
        gram
================================================================*/
#include <stdio.h>

#define MAXS 10

char *match( char *s, char ch1, char ch2 );

int main()
{
    char str[MAXS], ch_start, ch_end, *p;

    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);

    return 0;
}

char* match( char *s, char ch1, char ch2 ) {
    char* pCh1;
    char* pCh2;
    char* temp;

    for (pCh1 = s; *s != '\0' && (pCh1 = s) && ch1 != *s; ++ s)
        ;

    if (*s == '\0') {
        *pCh1  = '\0';
    }

    if (ch1 == *s) {
        ++ s;
        for (; *s != '\0' && (pCh2 = s) && ch2 != *s; ++s)
            ;

        if (*s == '\0') {
            temp = pCh1;
            while (*temp != '\0') {
                putchar(*temp);
                ++ temp;
            }
        }

        if (ch2 == *s) {
            temp = pCh1;
            while (temp != pCh2) {
                printf("%c", *temp);
                ++ temp;
            }

            printf("%c", *temp);
        }
    }
    printf("\n");

    return pCh1;
}
