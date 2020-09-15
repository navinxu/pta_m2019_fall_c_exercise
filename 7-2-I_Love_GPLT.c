/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：7-2-I_Love_GPLT.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年09月23日
*   Description ：
        7-2 I Love GPLT (5 point(s))
        这道超级简单的题目没有任何输入。
        
        你只需要把这句很重要的话 —— I Love GPLT ——竖着输出就可以了。
        
        所谓“竖着输出”，是指每个字符占一行（包括空格），即每行只能有1个字符和回车。
================================================================*/
#include <stdio.h>
#include <string.h>

int main() {

    const char cs[] = "I Love GPLT";

    for (size_t i = 0;i < strlen(cs); i ++) 
        printf("%c\n", cs[i]);

    return 0;
}

