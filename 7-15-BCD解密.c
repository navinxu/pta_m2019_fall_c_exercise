/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：7-15-BCD解密.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月10日
*   Description ：
        7-15 BCD解密 (10 point(s))
        BCD数是用一个字节来表达两位十进制的数，每四个比特表示一位。所以如果一个BCD数的十六进制是0x12，它表达的就是十进制的12。但是小明没学过BCD，把所有的BCD数都当作二进制数转换成十进制输出了。于是BCD的0x12被输出成了十进制的18了！
        
        现在，你的程序要读入这个错误的十进制数，然后输出正确的十进制数。提示：你可以把18转换回0x12，然后再转换回12。
        
        输入格式：
        输入在一行中给出一个[0, 153]范围内的正整数，保证能转换回有效的BCD数，也就是说这个整数转换成十六进制时不会出现A-F的数字。
        
        输出格式：
        输出对应的十进制数。
        
        输入样例：
        18
        输出样例：
        12
================================================================*/
#include <stdio.h>
#include <math.h>

int main() {

    int num;
    scanf("%d", &num);

    if (num >= 0 && num <= 153) {
        int binary[8] = {0};
        int bit;
        int index = 7;
        while (num > 0) {
            bit = num % 2;
            //printf("\tbit: %d\n", bit);
            binary[index--] = bit;
            num /= 2;
        }

        // for (int i = 0; i < 8; ++ i) {
        //     if (i == 0)
        //         printf("%d", binary[i]);
        //     else
        //         printf(" %d", binary[i]);
        // }
        // printf("\n");

        int result = 0;
        int cnt = 0;
        int i;
        for (i = 7;i >= 4; -- i) {
            result += binary[i] * pow(2, cnt++);
        }

        // printf("%d", result);
        int result2 = 0;
        for (cnt = 0; i >= 0; -- i) {
            result2 += binary[i] * pow(2, cnt++);
        }

        printf("%d", result2 * 10 + result);
    }

    return 0;
}
