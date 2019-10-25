/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-22-学生成绩链表处理.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月24日
*   Description ：
        6-22 学生成绩链表处理 (20 point(s))
        本题要求实现两个函数，一个将输入的学生成绩组织成单向链表；另一个将成绩低于某分数线的学生结点从链表中删除。
        
        函数接口定义：
        struct stud_node *createlist();
        struct stud_node *deletelist( struct stud_node *head, int min_score ); 函数createlist利用scanf从输入中获取学生的信息，将其组织成单向链表，并返回链表头指针。链表节点结构定义如下： struct stud_node {
            int              num;      //学号
            char             name[20]; //姓名
            int              score;    //成绩
            struct stud_node *next;    //指向下个结点的指针
        };
        输入为若干个学生的信息（学号、姓名、成绩），当输入学号为0时结束。
        
        函数deletelist从以head为头指针的链表中删除成绩低于min_score的学生，并返回结果链表的头指针。
        
        裁判测试程序样例：
        #include <stdio.h>
        #include <stdlib.h>
        
        struct stud_node {
             int    num;
             char   name[20];
             int    score;
             struct stud_node *next;
        };
        
        struct stud_node *createlist();
        struct stud_node *deletelist( struct stud_node *head, int min_score );
        
        int main()
        {
            int min_score;
            struct stud_node *p, *head = NULL;
        
            head = createlist();
            scanf("%d", &min_score);
            head = deletelist(head, min_score);
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
        80
        输出样例：
        2 wang 80
        4 zhao 85
================================================================*/
#include <stdio.h>
#include <stdlib.h>

struct stud_node {
     int    num;
     char   name[20];
     int    score;
     struct stud_node *next;
};

struct stud_node *createlist();
struct stud_node *deletelist( struct stud_node *head, int min_score );

int main()
{
    int min_score;
    struct stud_node *p, *head = NULL;

    head = createlist();
    // for ( p = head; p != NULL; p = p->next )
    //     printf("%d %s %d\n", p->num, p->name, p->score);
    // return 0;
    scanf("%d", &min_score);
    // printf("%d\n", min_score);
    // return 0;
    head = deletelist(head, min_score);
    for ( p = head; p != NULL; p = p->next )
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

// 以下是有效代码
struct stud_node* createlist() {
    int num;
    char name[20];
    int score;

    struct stud_node *head = NULL, *current = NULL, *prev = NULL;
    while (scanf("%d %s %d", &num, name, &score) == 3) {
        size_t i;
        if (!head) {
            head = (struct stud_node*) malloc(sizeof(struct stud_node));
            head->num = num;

            for ( i = 0; i < 19 && name[i] != '\0'; ++ i) {
                head->name[i] = name[i];
            }
            head->name[i] = '\0';
            head->score = score;

            current = head;
        } else {
            current = (struct stud_node*) malloc(sizeof(struct stud_node));
            current->num = num;
            for (i = 0; i < 19 && name[i] != '\0'; ++ i) {
                current->name[i] = name[i];
            }
            current->name[i] = '\0';
            current->score = score;
            prev->next = current;
        }

        prev = current;
    }

    if (head)
        current->next = NULL;

    size_t len = 0;
    size_t i;
    for (i = 0; i < 20 && name[i] != '\0'; ++ i) 
        len ++;
    // printf("%lu\n", len);
    
    for (i = len - 1; i > 0; -- i) 
        ungetc(name[i], stdin);
    ungetc(name[i], stdin);

    return head;
}

struct stud_node *deletelist( struct stud_node *head, int min_score ) {
    // 解决方案1
    //struct stud_node *p = NULL, *current = NULL, *prev = NULL;
    // for ( p = head; p != NULL; p = p->next )
    //     printf("%d %s %d\n", p->num, p->name, p->score);
    // return head;

    // for (; head != NULL; head = head->next) {
    //     // printf("%s\n", head->name);
    //     // continue;
    //     if (head->score >= min_score) {
    //         if (p == NULL) {
    //             // printf("\n====\n");
    //             p = head;
    //             current = p;
    //         } else {
    //             // printf("\n+++\n");
    //             current = head;
    //             prev->next = current;
    //         }
    //         prev = current;
    //     }
    // }
    //
    // if (p)
    //     current->next = NULL;
    //
    // return p;
    
    // 解决方案2
    struct stud_node *p = head, *prev = NULL;

    for (; p != NULL; p = p->next) {
        if (p->score < min_score) {
            if (p == head) {
                head = head->next;
            } else {
                prev->next = p->next;
            }
        } else {
            prev = p;
        }
    }

    return head;
}
