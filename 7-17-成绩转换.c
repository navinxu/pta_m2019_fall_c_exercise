/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：7-17-成绩转换.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月16日
*   Description ：
        7-17 成绩转换 (15 point(s))
        本题要求编写程序将一个百分制成绩转换为五分制成绩。转换规则：
        
        大于等于90分为A；
        小于90且大于等于80为B；
        小于80且大于等于70为C；
        小于70且大于等于60为D；
        小于60为E。
        输入格式:
        输入在一行中给出一个整数的百分制成绩。
        
        输出格式:
        在一行中输出对应的五分制成绩。
        
        输入样例:
        90
        输出样例:
        A
================================================================*/
#include <stdio.h>

char switch_score(int score);
int main() {

    int grade;
    scanf("%d", &grade);

    if (grade >= 0 && grade <= 100) {
        putchar(switch_score(grade));
    }

    return 0;
}

char switch_score(int score) {
    score /= 10;

    char grade;
    switch (score) {
        case 10:
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        default:
            grade = 'E';
    }

    return grade;
}
