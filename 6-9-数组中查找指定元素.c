/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-9-数组中查找指定元素.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年09月26日
*   Description ：
        6-9 在数组中查找指定元素 (15 point(s))
        本题要求实现一个在数组中查找指定元素的简单函数。
        
        函数接口定义：
        int search( int list[], int n, int x );
        其中list[]是用户传入的数组；n（≥0）是list[]中元素的个数；x是待查找的元素。如果找到
        
        则函数search返回相应元素的最小下标（下标从0开始），否则返回−1。
        
        裁判测试程序样例：
        #include <stdio.h>
        #define MAXN 10
        
        int search( int list[], int n, int x );
        
        int main()
        {
            int i, index, n, x;
            int a[MAXN];
        
            scanf("%d", &n);
            for( i = 0; i < n; i++ )
                scanf("%d", &a[i]);
            scanf("%d", &x);
            index = search( a, n, x );
            if( index != -1 )
                printf("index = %d\n", index);
            else
                printf("Not found\n");
        
            return 0;
        }
        
        // 你的代码将被嵌在这里
        输入样例1：
        5
        1 2 2 5 4
        2
        输出样例1：
        index = 1
        输入样例2：
        5
        1 2 2 5 4
        0
        输出样例2：
        Not found
================================================================*/
#include <stdio.h>
#define MAXN 10

int search( int list[], int n, int x );

int main()
{
    int i, index, n, x;
    int a[MAXN];

    scanf("%d", &n);
    for( i = 0; i < n; i++ )
        scanf("%d", &a[i]);
    scanf("%d", &x);
    index = search( a, n, x );
    if( index != -1 )
        printf("index = %d\n", index);
    else
        printf("Not found\n");

    return 0;
}

// 以下是有效代码
int search(int list[], int n, int x) {
    for (int i = 0; i < n; i ++) {
        if (list[i] == x)
            return i;
    }

    return -1;
}
