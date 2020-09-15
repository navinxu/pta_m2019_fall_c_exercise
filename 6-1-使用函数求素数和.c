/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-1-使用函数求素数和.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年09月23日
*   Description ：
        6-1 使用函数求素数和 (20 point(s))
        本题要求实现一个判断素数的简单函数、以及利用该函数计算给定区间内素数和的函数。
        
        素数就是只能被1和自身整除的正整数。注意：1不是素数，2是素数。
        
        函数接口定义：
        int prime( int p );
        int PrimeSum( int m, int n );
        其中函数prime当用户传入参数p为素数时返回1，否则返回0；函数PrimeSum返回区间[m, n]内所有素数的和。题目保证用户传入的参数m≤n。
        
        裁判测试程序样例：
        #include <stdio.h>
        #include <math.h>
        
        int prime( int p );
        int PrimeSum( int m, int n );
        
        int main()
        {
            int m, n, p;
        
            scanf("%d %d", &m, &n);
            printf("Sum of ( ");
            for( p=m; p<=n; p++ ) {
                if( prime(p) != 0 )
                    printf("%d ", p);
            }
            printf(") = %d\n", PrimeSum(m, n));
        
            return 0;
        }
        
        // 你的代码将被嵌在这里
        输入样例：
        -1 10
        输出样例：
        Sum of ( 2 3 5 7 ) = 17
================================================================*/
#include <stdio.h>
#include <math.h>

int prime( int p );
int PrimeSum( int m, int n );

int main()
{
    int m, n, p;

    scanf("%d %d", &m, &n);
    printf("Sum of ( ");
    for( p=m; p<=n; p++ ) {
        if( prime(p) != 0 )
            printf("%d ", p);
    }
    printf(") = %d\n", PrimeSum(m, n));

    return 0;
}

int prime(int p) {
    unsigned char is_prime = 1;

    if (p >= 2) {
        if (p == 2) {
            return 1;
        }

        for (int i = 2; i <= p; i ++) {
            if (p % i == 0 && p != i) {
                is_prime = 0;
                break;
            }
        }
    } else 
        is_prime = 0;

    if (is_prime)
        return 1;
    else
        return 0;

}

int PrimeSum(int m, int n ) {
    if (m < 1)
        m = 1;

    if (n < 1)
        n = 1;

    int sum = 0;
    if (m <= n) {
        while (m <= n) {
            if (prime(m))
                sum += m;
            m ++;
        }
    }

    return sum;
}
