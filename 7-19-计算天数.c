/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：7-19-计算天数.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月20日
*   Description ：
        7-19 计算天数 (15 point(s))
        本题要求编写程序计算某年某月某日是该年中的第几天。
        
        输入格式:
        输入在一行中按照格式“yyyy/mm/dd”（即“年/月/日”）给出日期。注意：闰年的判别条件是该年年份能被4整除但不能被100整除、或者能被400整除。闰年的2月有29天。
        
        输出格式:
        在一行输出日期是该年中的第几天。
        
        输入样例1:
        2009/03/02
        输出样例1:
        61
        输入样例2:
        2000/03/02
        输出样例2:
        62
        鸣谢湖北汽车工业学院袁科老师补充数据
================================================================*/
#include <stdio.h>

int main() {

    int year, month, day;
    scanf("%d/%d/%d", &year, &month, &day);
    // printf("%d %d %d", year, month, day);
    // return 0;

    if (month >= 1 && month <= 12 && day >= 1 && day <= 31) {
        int leap;
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            leap = 29;
        } else
            leap = 28;

        int month_days[] = {31, leap, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days_count = 0;

        -- month;
        while (month > 0) {
            days_count += month_days[(month --) - 1];
        }

        days_count += day;

        printf("%d", days_count);

    }





    return 0;
}

