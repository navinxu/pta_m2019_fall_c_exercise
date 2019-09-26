/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-7-移动字母.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年09月26日
*   Description ：
        6-7 移动字母 (10 point(s))
        本题要求编写函数，将输入字符串的前3个字符移到最后。
        
        函数接口定义：
        void Shift( char s[] );
        其中char s[]是用户传入的字符串，题目保证其长度不小于3；函数Shift须将按照要求变换后的字符串仍然存在s[]里。
        
        裁判测试程序样例：
        #include <stdio.h>
        #include <string.h>
        
        #define MAXS 10
        
        void Shift( char s[] );
        
        void GetString( char s[] ); // 实现细节在此不表
        
        int main()
        {
            char s[MAXS];
        
            GetString(s);
            Shift(s);
            printf("%s\n", s);
        	
            return 0; 
        }
        
        // 你的代码将被嵌在这里
        输入样例：
        abcdef
        输出样例：
        defabc
================================================================*/
#include <stdio.h>
#include <string.h>

#define MAXS 10

void Shift( char s[] );

int main()
{
    char s[MAXS] = "abcefg";

    Shift(s);
    printf("%s\n", s);
	
    return 0; 
}


void Shift( char s[] ) {

    if (strlen(s) >= 3) {
        char ps[4];

        size_t i;
        for (i = 0; i < 3; i ++)
            ps[i] = s[i];
        ps[i] = '\0';
        for (i = 0; i < strlen(s) - 3;i ++)
            s[i] = s[i + 3];

        s[i] = ps[0];
        s[i + 1] = ps[1];
        s[i + 2] = ps[2];
        s[i + 3] = '\0';
    }
}
