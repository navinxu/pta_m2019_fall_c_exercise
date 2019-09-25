/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-2-使用函数验证哥德巴赫猜想.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年09月25日
*   Description ：
        6-2 使用函数验证哥德巴赫猜想 (20 point(s))
        本题要求实现一个判断素数的简单函数，并利用该函数验证哥德巴赫猜想：任何一个不小于6的偶数均可表示为两个奇素数之和。素数就是只能被1和自身整除的正整数。注意：1不是素数，2是素数。
        
        函数接口定义：
        int prime( int p );
        void Goldbach( int n );
        其中函数prime当用户传入参数p为素数时返回1，否则返回0；函数Goldbach按照格式“n=p+q”输出n的素数分解，其中p≤q均为素数。又因为这样的分解不唯一（例如24可以分解为5+19，还可以分解为7+17），要求必须输出所有解中p最小的解。
        
        裁判测试程序样例：
        #include <stdio.h>
        #include <math.h>
        
        int prime( int p );
        void Goldbach( int n );
        
        int main()
        {
            int m, n, i, cnt;
        
            scanf("%d %d", &m, &n);
            if ( prime(m) != 0 ) printf("%d is a prime number\n", m);
            if ( m < 6 ) m = 6;
            if ( m%2 ) m++;
            cnt = 0;
            for( i=m; i<=n; i+=2 ) {
                Goldbach(i);
                cnt++;
                if ( cnt%5 ) printf(", ");
                else printf("\n");
            }
        
            return 0;
        }
        
        // 你的代码将被嵌在这里
        输入样例：
        89 100
        输出样例：
        89 is a prime number
        90=7+83, 92=3+89, 94=5+89, 96=7+89, 98=19+79
        100=3+97, 
================================================================*/
#include <stdio.h>
#include <math.h>

int prime( int p );
void Goldbach( int n );

int main()
{
    int m, n, i, cnt;

    scanf("%d %d", &m, &n);
    if ( prime(m) != 0 ) printf("%d is a prime number\n", m);
    if ( m < 6 ) m = 6;
    if ( m%2 ) m++;
    cnt = 0;
    for( i=m; i<=n; i+=2 ) {
        Goldbach(i);
        cnt++;
        if ( cnt%5 ) printf(", ");
        else printf("\n");
    }

    return 0;
}
int prime( int p ) {
    unsigned char is_prime = 1;

    if (p == 1)
        is_prime = 0;
    else {
        for (int i = 2; i < p; i ++) {
            if (p % i == 0) {
                is_prime = 0;
                break;
            }
        }
    }

    return is_prime;
}

void Goldbach( int n ) {
    int p, q;
    unsigned char flag = 0;
    for (int i = 2; i < n; i ++) {
        if (prime(i))
            p = i;
        else
            continue;
        for (int j = i; j < n;j ++) {
            if (prime(j))
                q = j;
            else
                continue;

            if (n == p + q) {
                printf("%d=%d+%d", n, p, q);
                flag = 1;
                break;
            }
        }

        if (flag)
            break;
    }
}
