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

int main() {

    int a[5] = {1,2,3,4,5};
    int *p = (int *)(&a + 1);
    printf("%d,%d", *(a + 1), *(p - 1));

    return 0;
}
