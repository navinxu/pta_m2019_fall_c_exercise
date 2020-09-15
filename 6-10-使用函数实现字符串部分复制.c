/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-10-使用函数实现字符串部分复制.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年09月26日
*   Description ：
        6-10 使用函数实现字符串部分复制 (20 point(s))
        本题要求编写函数，将输入字符串t中从第m个字符开始的全部字符复制到字符串s中。
        
        函数接口定义：
        void strmcpy( char *t, int m, char *s );
        函数strmcpy将输入字符串char *t中从第m个字符开始的全部字符复制到字符串char *s中。若m超过输入字符串的长度，则结果字符串应为空串。
        
        裁判测试程序样例：
        #include <stdio.h>
        #define MAXN 20
        
        void strmcpy( char *t, int m, char *s );
        void ReadString( char s[] ); // 由裁判实现，略去不表 int main()
        {
            char t[MAXN], s[MAXN];
            int m;
        
            scanf("%d\n", &m);
            ReadString(t);
            strmcpy( t, m, s );
            printf("%s\n", s);
        
            return 0;
        }
        
        // 你的代码将被嵌在这里
        输入样例：
        7
        happy new year
        输出样例：
        new year
================================================================*/
#include <stdio.h>
#define MAXN 20

void strmcpy( char *t, int m, char *s );
void ReadString( char s[] ); // 由裁判实现，略去不表

int main()
{
    char t[MAXN] = "happy new year";
    char s[MAXN];
    int m;

    scanf("%d", &m);
    //ReadString(t);
    strmcpy( t, m, s );
    printf("%s\n", s);

    return 0;
}

// 以下是有效代码
#include <string.h>
void strmcpy(char *t, int m, char *s) {
    if (m - 1 >= (int)strlen(t))
        *s = '\0';
    else {
        t = t + m - 1;

        while (*t != '\0' && (*s = *t))
            t++, s++;

        *s = '\0';
    }
}
