/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-13-输出月份英文名.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月06日
*   Description ：
        6-13 输出月份英文名 (15 point(s))
        本题要求实现函数，可以返回一个给定月份的英文名称。
        
        函数接口定义：
        char *getmonth( int n );
        函数getmonth应返回存储了n对应的月份英文名称的字符串头指针。如果传入的参数n不是一个代表月份的数字，则返回空指针NULL。
        
        裁判测试程序样例：
        #include <stdio.h>
        
        char *getmonth( int n );
        
        int main()
        {
            int n;
            char *s;
        
            scanf("%d", &n);
            s = getmonth(n);
            if ( s==NULL ) printf("wrong input!\n");
            else printf("%s\n", s);
        
           return (char*) 0;
        }
        
        // 你的代码将被嵌在这里
        输入样例1：
        5
        输出样例1：
        May
        输入样例2：
        15
        输出样例2：
        wrong input!
================================================================*/
#include <stdio.h>

char *getmonth( int n );

int main()
{
    int n;
    char *s;

    scanf("%d", &n);
    s = getmonth(n);
    if ( s==NULL ) printf("wrong input!\n");
    else printf("%s\n", s);

   return (char*) 0;
}

char* getmonth(int n) {
        switch (n) {
            case 1:
                return (char*) "January";
            case 2:
                return (char*) "February";
                
            case 3:
                return (char*) "March";
                
            case 4:
                return (char*) "April";
                
            case 5:
                return (char*) "May";
                
            case 6:
                return (char*) "June";
                
            case 7:
                return (char*) "July";
                
            case 8:
                return (char*) "August";
                
            case 9:
                return (char*) "September";
                
            case 10:
                return (char*) "October";
                
            case 11:
                return (char*) "November";
                
            case 12:
                return (char*) "December";
                
            default:
                return (char*) NULL;
        };
}

