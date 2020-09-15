/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：7-12-日期格式化.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月03日
*   Description ：
        7-12 日期格式化 (5 point(s))
        世界上不同国家有不同的写日期的习惯。比如美国人习惯写成“月-日-年”，而中国人习惯写成“年-月-日”。下面请你写个程序，自动把读入的美国格式的日期改写成中国习惯的日期。
        
        输入格式：
        输入在一行中按照“mm-dd-yyyy”的格式给出月、日、年。题目保证给出的日期是1900年元旦至今合法的日期。
        
        输出格式：
        在一行中按照“yyyy-mm-dd”的格式给出年、月、日。
        
        输入样例：
        03-15-2017
        输出样例：
        2017-03-15
================================================================*/
#include <stdio.h>

int main() {

    char month[3];
    char day[3];
    char year[5];

    scanf("%s-%s-%s", month, day, year);

    //year[4] = '\0';
    //month[2] = '\0';
    //day[2] = '\0';

    //printf("%s-%s-%s", year, month, day);
    //return 0;

    for (int i = 0; i < 4; i ++)
        printf("%c", year[i]);
    printf("-");
    for (int i = 0; i < 2; i ++)
        printf("%c", month[i]);
    printf("-");
    for (int i = 0; i < 2; i ++)
        printf("%c", day[i]);

    return 0;
}
