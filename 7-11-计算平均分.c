/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：7-11-计算平均分.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月02日
*   Description ：
7-11 计算平均分 (5 point(s))
已知某位学生的数学、英语和计算机课程的成绩分别是87分、72分和93分，求该生3门课程的平均成绩（结果按整型输出）。

输入格式：
本题无输入


输出格式：
按照下列格式输出结果：

math = 87, eng = 72, comp = 93, average = 计算所得的平均成绩
================================================================*/
#include <stdio.h>

int main() {

    printf("math = 87, eng = 72, comp = 93, average = %d", (int)((87 + 72 + 93) / 3.0));

    return 0;
}
