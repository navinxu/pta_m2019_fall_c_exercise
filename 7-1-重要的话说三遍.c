/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：7-1-重要的话说三遍.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年09月23日
*   Description ：
7-1 重要的话说三遍 (5 point(s))
这道超级简单的题目没有任何输入。

你只需要把这句很重要的话 —— “I'm gonna WIN!”——连续输出三遍就可以了。

注意每遍占一行，除了每行的回车不能有任何多余字符。
================================================================*/
#include <stdio.h>

int main() {

    for (int i = 0; i < 3; i ++)
        printf("I'm gonna WIN!\n");

    return 0;
}

