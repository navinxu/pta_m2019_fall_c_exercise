/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-4-查找子串.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年09月25日
*   Description ：
        6-4 查找子串 (20 point(s))
        本题要求实现一个字符串查找的简单函数。
        
        函数接口定义：
        char *search( char *s, char *t );
        函数search在字符串s中查找子串t，返回子串t在s中的首地址。若未找到，则返回NULL。
        
        裁判测试程序样例：
        #include <stdio.h>
        #define MAXS 30
        
        char *search(char *s, char *t);
        void ReadString( char s[] ); // 裁判提供，细节不表
        
        int main()
        {
            char s[MAXS], t[MAXS], *pos;
        
            ReadString(s);
            ReadString(t);
            pos = search(s, t);
            if ( pos != NULL )
                printf("%d\n", pos - s);
            else
                printf("-1\n");
        
            return 0;
        }
        
        // 你的代码将被嵌在这里
        输入样例1：
        The C Programming Language
        ram
        输出样例1：
        10
        输入样例2：
        The C Programming Language
        bored
        输出样例2：
        -1
================================================================*/
#include <stdio.h>
#define MAXS 30

char *search(char *s, char *t);

int main()
{
    char s[MAXS] = "The C Programming Language";
    char t[MAXS] = "uage"; 
    char *pos;

    pos = search(s, t);
    if ( pos != NULL )
        printf("%ld\n", pos - s);
    else
        printf("-1\n");

    return 0;
}

char *search(char *s, char *t) {

    char* ps;
    char* pt;
    while (*s != '\0') {
        if (*t == '\0')
            return NULL;

        if (*s == *t) {
            ps = s;
            pt = t;
            while (*(++s) != '\0' && *(++t) != '\0' && *s == *t)
                ;

            if (*s == '\0') {
                if (*(++t) == '\0') {
                    return ps;
                } else 
                    return NULL;
            } else if (*t == '\0') {
                return ps;
            } else {
                t = pt;
            }
        }
        s ++;
    }

    return NULL;
}
