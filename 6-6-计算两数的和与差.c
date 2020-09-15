/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-6-计算两数的和与差.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年09月26日
*   Description ：
        6-6 计算两数的和与差 (10 point(s))
        本题要求实现一个计算输入的两数的和与差的简单函数。
        
        函数接口定义：
        void sum_diff( float op1, float op2, float *psum, float *pdiff );
        其中op1和op2是输入的两个实数，*psum和*pdiff是计算得出的和与差。
        
        裁判测试程序样例：
        #include <stdio.h>
        
        void sum_diff( float op1, float op2, float *psum, float *pdiff );
        
        int main()
        {
            float a, b, sum, diff;
        
            scanf("%f %f", &a, &b);
            sum_diff(a, b, &sum, &diff);
            printf("The sum is %.2f\nThe diff is %.2f\n", sum, diff);
        	
            return 0; 
        }
        
        // 你的代码将被嵌在这里
        输入样例：
        4 6
        输出样例：
        The sum is 10.00
        The diff is -2.00
================================================================*/
#include <stdio.h>

void sum_diff( float op1, float op2, float *psum, float *pdiff );

int main()
{
    float a, b, sum, diff;

    scanf("%f %f", &a, &b);
    sum_diff(a, b, &sum, &diff);
    printf("The sum is %.2f\nThe diff is %.2f\n", sum, diff);
	
    return 0; 
}

void sum_diff(float op1, float op2, float *psum, float *pdiff) {
    *psum  = op1 + op2;
    *pdiff = op1 - op2;
}
