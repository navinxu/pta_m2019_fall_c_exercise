/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：7-20-简单计算器.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月21日
*   Description ：
        7-20 简单计算器 (20 point(s))
        模拟简单运算器的工作。假设计算器只能进行加减乘除运算，运算数和结果都是整数，四种运算符的优先级相同，按从左到右的顺序计算。
        
        输入格式:
        输入在一行中给出一个四则运算算式，没有空格，且至少有一个操作数。遇等号”=”说明输入结束。
        
        输出格式:
        在一行中输出算式的运算结果，或者如果除法分母为0或有非法运算符，则输出错误信息“ERROR”。
        
        输入样例:
        1+2*10-10/2=
        输出样例:
        10
================================================================*/
#include <stdio.h>

int makeNum(void);

int main() {

    int c;
    int result = 0;
    int num;
    while ((c = getchar()) != '=') {
        switch (c) {
            case '+':
                num = makeNum();
                result += num;
                break;
            case '-':
                num = makeNum();
                result -= num;
                break;
            case '*':
                num = makeNum();
                result *= num;
                break;
            case '/':
                num = makeNum();
                if (!num) {
                    printf("ERROR");
                    return 0;
                } else {
                    result /= num;
                }
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                ungetc(c, stdin);
                num = makeNum();
                // 不要忘记第一个数字
                result += num;
                break;
            default:
                printf("ERROR");
                return 0;
            
        }
    }

    printf("%d", result);

    return 0;
}

int makeNum(void) {
    int c;
    int num = 0;

    while ((c = getchar()) >= '0' && c <= '9') {
        num = 10 * num + c - '0'; 
    }

    ungetc(c, stdin);

    return num;
}
