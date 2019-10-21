/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：test.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月21日
*   Description ：
================================================================*/
#include <stdio.h>

int max(int a, int b);
int main() {

    int a = 1;
    int b = 10;
    printf("max: %d\n", max(a, b));

    return 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}
