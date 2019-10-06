/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：7-13-后天.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月06日
*   Description ：
        7-13 后天 (5 point(s))
        如果今天是星期三，后天就是星期五；如果今天是星期六，后天就是星期一。我们用数字1到7对应星期一到星期日。给定某一天，请你输出那天的“后天”是星期几。
        
        输入格式：
        输入第一行给出一个正整数D（1 ≤ D ≤ 7），代表星期里的某一天。
        
        输出格式：
        在一行中输出D天的后天是星期几。
        
        输入样例：
        3
        输出样例：
        5
================================================================*/
#include <stdio.h>

int main() {

    unsigned int D;
    scanf("%u", &D);

    if (D >= 1 && D <= 7) {
        unsigned int week;
        if (D < 6)
            week = D + 2;
        else
            week = D + 2 - 7;
        printf("%u", week);
    }
    return 0;
}
