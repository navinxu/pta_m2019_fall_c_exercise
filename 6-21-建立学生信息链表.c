/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-21-建立学生信息链表.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月22日
*   Description ：
        6-21 建立学生信息链表 (20 point(s))
        本题要求实现一个将输入的学生成绩组织成单向链表的简单函数。
        
        函数接口定义：
        void input();
        该函数利用scanf从输入中获取学生的信息，并将其组织成单向链表。链表节点结构定义如下：
        
        struct stud_node {
            int              num;      //学号
            char             name[20]; //姓名
            int              score;    //成绩
            struct stud_node *next;    //指向下个结点的指针
        };
        单向链表的头尾指针保存在全局变量head和tail中。
        
        输入为若干个学生的信息（学号、姓名、成绩），当输入学号为0时结束。
        
        裁判测试程序样例：
        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>
        
        struct stud_node {
             int    num;
             char   name[20];
             int    score;
             struct stud_node *next;
        };
        struct stud_node *head, *tail;
        
        void input();
        
        int main()
        {
            struct stud_node *p;
        	
            head = tail = NULL;
            input();
            for ( p = head; p != NULL; p = p->next )
                printf("%d %s %d\n", p->num, p->name, p->score);
        
            return 0;
        }
        
        // 你的代码将被嵌在这里
        输入样例：
        1 zhang 78
        2 wang 80
        3 li 75
        4 zhao 85
        0
        输出样例：
        1 zhang 78
        2 wang 80
        3 li 75
        4 zhao 85
================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stud_node {
     int    num;
     char   name[20];
     int    score;
     struct stud_node *next;
};
struct stud_node *head, *tail;

void input();

int main()
{
    struct stud_node *p;
	
    head = tail = NULL;
    input();
    for ( p = head; p != NULL; p = p->next )
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

void input() {
    struct stud_node *current, *prev;
    head = tail = NULL;
    
    int num;
    char name[20];
    int score;

    
    while (scanf("%d %s %d", &num, name, &score) == 3) {
        //printf("%d %s %d\n", num, name, score);
        if (!head) {
            head = (struct stud_node*) malloc(sizeof(struct stud_node));
            head->num = num;
            strcpy(head->name, name);
            head->score = score;
            head->next = NULL;
            current = head;
        } else {
            current = (struct stud_node*) malloc(sizeof(struct stud_node));
            current->num = num;
            strcpy(current->name, name);
            current->score = score;
            current->next = NULL;
            prev->next = current;
        }

        prev = current;
    }

    if (head) {
        current->next = NULL;
        tail = current;
    }
}
