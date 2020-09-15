/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-11-计算两个复数之积.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月02日
*   Description ：
        6-11 计算两个复数之积 (15 point(s))
        本题要求实现一个计算复数之积的简单函数。
        
        函数接口定义：
        struct complex multiply(struct complex x, struct complex y);
        其中struct complex是复数结构体，其定义如下：
        
        struct complex{
            int real;
            int imag;
        };
        裁判测试程序样例：
        #include <stdio.h>
        
        struct complex{
            int real;
            int imag;
        };
        
        struct complex multiply(struct complex x, struct complex y);
        
        int main()
        {
            struct complex product, x, y;
        
            scanf("%d%d%d%d", &x.real, &x.imag, &y.real, &y.imag);
            product = multiply(x, y);
            printf("(%d+%di) * (%d+%di) = %d + %di\n", 
                    x.real, x.imag, y.real, y.imag, product.real, product.imag);
        
            return 0;
        }
        
        // 你的代码将被嵌在这里
        输入样例：
        3 4 5 6
        输出样例：
        (3+4i) * (5+6i) = -9 + 38i
================================================================*/
#include <stdio.h>

struct complex{
    int real;
    int imag;
};

struct complex multiply(struct complex x, struct complex y);

int main()
{
    struct complex product, x, y;

    scanf("%d%d%d%d", &x.real, &x.imag, &y.real, &y.imag);
    product = multiply(x, y);
    printf("(%d+%di) * (%d+%di) = %d + %di\n", 
            x.real, x.imag, y.real, y.imag, product.real, product.imag);

    return 0;
}

// 有效代码
struct complex multiply(struct complex x, struct complex y) {
    struct complex product;
    product.real = x.real * y.real - x.imag * y.imag;
    product.imag = x.real * y.imag + x.imag * y.real;
    return product;
}
