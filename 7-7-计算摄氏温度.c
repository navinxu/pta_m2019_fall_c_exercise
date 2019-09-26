/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：7-7-计算摄氏温度.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年09月26日
*   Description ：
        7-7 计算摄氏温度 (10 point(s))
        给定一个华氏温度F，本题要求编写程序，计算对应的摄氏温度C。计算公式：C=5×(F−32)/9。题目保证输入与输出均在整型范围内。
        
        输入格式:
        输入在一行中给出一个华氏温度。
        
        输出格式:
        在一行中按照格式“Celsius = C”输出对应的摄氏温度C的整数值。
        
        输入样例:
        150
        输出样例:
        Celsius = 65
================================================================*/
#include <stdio.h>

int main() {

    int F;
    scanf("%d", &F);

    int C = 5 * (F - 32) / 9;

    printf("Celsius = %d", C);

    return 0;
}
