/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-14-查找星期.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月08日
*   Description ：
        6-14 查找星期 (15 point(s))
        本题要求实现函数，可以根据下表查找到星期，返回对应的序号。
        
        序号	星期
        0	Sunday
        1	Monday
        2	Tuesday
        3	Wednesday
        4	Thursday
        5	Friday
        6	Saturday
        函数接口定义：
        int getindex( char *s );
        函数getindex应返回字符串s序号。如果传入的参数s不是一个代表星期的字符串，则返回-1。
        
        裁判测试程序样例：
        #include <stdio.h>
        #include <string.h>
        
        #define MAXS 80
        
        int getindex( char *s );
        
        int main()
        {
            int n;
            char s[MAXS];
        
            scanf("%s", s);
            n = getindex(s);
            if ( n==-1 ) printf("wrong input!\n");
            else printf("%d\n", n);
        
            return 0;
        }
        
        // 你的代码将被嵌在这里
        输入样例1：
        Tuesday
        输出样例1：
        2
        输入样例2：
        today
        输出样例2：
        wrong input!
================================================================*/
#include <stdio.h>
#include <string.h>

#define MAXS 80

int getindex( char *s );

int main()
{
    int n;
    char s[MAXS];

    scanf("%s", s);
    n = getindex(s);
    if ( n==-1 ) printf("wrong input!\n");
    else printf("%d\n", n);

    return 0;
}

// 以下是有效代码
#include <string.h>
int getindex( char *s ) {
    char week[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    for (int i = 0; i < 7; ++ i) {
        if (strcmp(s, week[i]) == 0) {
            return i;
        }
    }

    return -1;
}
