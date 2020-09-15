/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：7-23-分段计算居民水费.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月25日
*   Description ：
        7-23 分段计算居民水费 (10 point(s))
        为鼓励居民节约用水，自来水公司采取按用水量阶梯式计价的办法，居民应交水费y（元）与月用水量x（吨）相关：当x不超过15吨时，y=4x/3；超过后，y=2.5x−17.5。请编写程序实现水费的计算。
        
        输入格式：
        输入在一行中给出非负实数x。
        
        输出格式：
        在一行输出应交的水费，精确到小数点后2位。
        
        输入样例1：
        12
        输出样例1：
        16.00
        输入样例2：
        16
        输出样例2：
        22.50
================================================================*/
#include <stdio.h>

int main() {

    double x;
    scanf("%lf", &x);
    if (x >= 0) {
        double y;
        if (x <= 15) {
            y = 4.0 * x / 3;
        } else {
            y = 2.5 * x - 17.5;
        }

        printf("%.2f", y);
    }

    return 0;
}
