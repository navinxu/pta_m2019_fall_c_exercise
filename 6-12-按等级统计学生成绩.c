/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-12-按等级统计学生成绩.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月03日
*   Description ：
        6-12 按等级统计学生成绩 (20 point(s))
        本题要求实现一个根据学生成绩设置其等级，并统计不及格人数的简单函数。
        
        函数接口定义：
        int set_grade( struct student *p, int n );
        其中p是指向学生信息的结构体数组的指针，该结构体的定义为：
        
        struct student{
            int num;
            char name[20];
            int score;
            char grade;
        };
        n是数组元素个数。学号num、姓名name和成绩score均是已经存储好的。set_grade函数需要根据学生的成绩score设置其等级grade。等级设置：85－100为A，70－84为B，60－69为C，0－59为D。同时，set_grade还需要返回不及格的人数。
        
        裁判测试程序样例：
        #include <stdio.h>
        #define MAXN 10
        
        struct student{
            int num;
            char name[20];
            int score;
            char grade;
        };
        
        int set_grade( struct student *p, int n );
        
        int main()
        {   struct student stu[MAXN], *ptr;
            int n, i, count;
        
            ptr = stu;
            scanf("%d\n", &n);
            for(i = 0; i < n; i++){
               scanf("%d%s%d", &stu[i].num, stu[i].name, &stu[i].score);
            } 
           count = set_grade(ptr, n);
           printf("The count for failed (<60): %d\n", count);
           printf("The grades:\n"); 
           for(i = 0; i < n; i++)
               printf("%d %s %c\n", stu[i].num, stu[i].name, stu[i].grade);
            return 0;
        }
        
        // 你的代码将被嵌在这里
        输入样例：
        10
        31001 annie 85
        31002 bonny 75
        31003 carol 70
        31004 dan 84
        31005 susan 90
        31006 paul 69
        31007 pam 60
        31008 apple 50
        31009 nancy 100
        31010 bob 78
        输出样例：
        The count for failed (<60): 1
        The grades:
        31001 annie A
        31002 bonny B
        31003 carol B
        31004 dan B
        31005 susan A
        31006 paul C
        31007 pam C
        31008 apple D
        31009 nancy A
        31010 bob B
================================================================*/
#include <stdio.h>
#define MAXN 10

struct student{
    int num;
    char name[20];
    int score;
    char grade;
};

int set_grade( struct student *p, int n );

int main()
{   struct student stu[MAXN], *ptr;
    int n, i, count;

    ptr = stu;
    scanf("%d\n", &n);
    for(i = 0; i < n; i++){
       scanf("%d%s%d", &stu[i].num, stu[i].name, &stu[i].score);
    } 
   count = set_grade(ptr, n);
   printf("The count for failed (<60): %d\n", count);
   printf("The grades:\n"); 
   for(i = 0; i < n; i++)
       printf("%d %s %c\n", stu[i].num, stu[i].name, stu[i].grade);
    return 0;
}

// 以下是有效代码
int set_grade( struct student *p, int n ) {
    int D_student = 0;
    while (--n >= 0) {
        if (p->score >= 85 && p->score <= 100)
            p->grade = 'A';
        else if (p->score >= 70 && p->score <= 84) 
            p->grade = 'B';
        else if (p->score >= 60 && p->score <= 69)
            p->grade = 'C';
        else {
            p->grade = 'D';   
            ++ D_student;
        }
        ++ p;
    }

    return D_student;
}
