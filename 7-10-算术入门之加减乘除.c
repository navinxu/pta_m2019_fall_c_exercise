/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：7-10-算术入门之加减乘除.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年09月26日
*   Description ：
        7-10 算术入门之加减乘除 (10 point(s))
        对于输入的两个整数，按照要求输出其和差积商。
        
        输入格式:
        在一行内输入两个不超过100的非负整数a和b，中间以一个空格间隔，且保证b不为0。
        
        输出格式:
        共四行，格式是：
        
        [a] + [b] = [a+b]
        [a] - [b] = [a-b]
        [a] * [b] = [a*b]
        [a] / [b] = [a/b]
        其中，带有方括号的内容（如[a]、[b]、[a+b]等）表示相应整数或运算结果的值，在输出时要用实际的值代替。
        
        并且：如果a能够被b整除，那么a/b应输出为整数格式，否则a/b输出为带两位小数的格式。
        
        提示：注意表达式中的空格。
        
        输入样例1:
        6 3
        输出样例1:
        6 + 3 = 9
        6 - 3 = 3
        6 * 3 = 18
        6 / 3 = 2
        输入样例2:
        8 6
        输出样例2:
        8 + 6 = 14
        8 - 6 = 2
        8 * 6 = 48
        8 / 6 = 1.33
        Author: 周强
        Organization: 青岛大学
        Time Limit: 400 ms
        Memory Limit: 64 MB
================================================================*/
#include <stdio.h>

int main() {
    
    int a, b;
    scanf("%d %d", &a, &b);

    if (a <= 100 && b <= 100 && b != 0) {
        printf("%d + %d = %d\n", a, b, a + b);
        printf("%d - %d = %d\n", a, b, a - b);
        printf("%d * %d = %d\n", a, b, a * b);

        if (a % b == 0) {
            printf("%d / %d = %d", a, b, a / b);
        } else
            printf("%d / %d = %.2f", a, b, (1.0 * a) / b);
    }

    return 0;
}

