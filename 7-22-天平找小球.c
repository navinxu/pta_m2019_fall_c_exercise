/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：7-22-天平找小球.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月25日
*   Description ：
        7-22 用天平找小球 (10 point(s))
        三个球A、B、C，大小形状相同且其中有一个球与其他球重量不同。要求找出这个不一样的球。
        
        输入格式：
        输入在一行中给出3个正整数，顺序对应球A、B、C的重量。
        
        输出格式：
        在一行中输出唯一的那个不一样的球。
        
        输入样例：
        1 1 2
        输出样例：
        C
================================================================*/
#include <stdio.h>

size_t diff_index(int []);

int main() {
    int weights[3];
    scanf("%d %d %d", weights, &weights[1], &weights[2]);
    char balls[3] = {'A', 'B', 'C'};
    printf("%c", balls[diff_index(weights)]);
    return 0;
}

size_t diff_index(int weights[]) {
    size_t index = 0;
    if (weights[0] == weights[2])
        index = 1;
    else if (weights[0] == weights[1])
        index = 2;

    return index;
}
