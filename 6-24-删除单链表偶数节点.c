/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-24-删除单链表偶数节点.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月25日
*   Description ：
        6-24 删除单链表偶数节点 (20 point(s))
        本题要求实现两个函数，分别将读入的数据存储为单链表、将链表中偶数值的结点删除。链表结点定义如下：
        
        struct ListNode {
            int data;
            struct ListNode *next;
        };
        函数接口定义：
        struct ListNode *createlist();
        struct ListNode *deleteeven( struct ListNode *head );
        函数createlist从标准输入读入一系列正整数，按照读入顺序建立单链表。当读到−1时表示输入结束，函数应返回指向单链表头结点的指针。
        
        函数deleteeven将单链表head中偶数值的结点删除，返回结果链表的头指针。
        
        裁判测试程序样例：
        #include <stdio.h>
        #include <stdlib.h>
        
        struct ListNode {
            int data;
            struct ListNode *next;
        };
        
        struct ListNode *createlist();
        struct ListNode *deleteeven( struct ListNode *head );
        void printlist( struct ListNode *head )
        {
             struct ListNode *p = head;
             while (p) {
                   printf("%d ", p->data);
                   p = p->next;
             }
             printf("\n");
        }
        
        int main()
        {
            struct ListNode *head;
        
            head = createlist();
            head = deleteeven(head);
            printlist(head);
        
            return 0;
        }
        
        // 你的代码将被嵌在这里
        输入样例：
        1 2 2 3 4 5 6 7 -1
        输出样例：
        1 3 5 7 
================================================================*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();
struct ListNode *deleteeven( struct ListNode *head );
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode *head;

    head = createlist();
    head = deleteeven(head);
    printlist(head);

    return 0;
}

// 以下是有效代码
struct ListNode *createlist() {
    struct ListNode *head = NULL, *current = NULL, *prev = NULL;

    int input;
    scanf("%d", &input);
    while (input != -1) {
        if (!head) {
            head = (struct ListNode*) malloc(sizeof(struct ListNode));
            head->data = input;
            head->next = NULL;
            current = head;
        } else {
            current = (struct ListNode*) malloc(sizeof(struct ListNode));
            current->data = input;
            current->next = NULL;
            prev->next = current;
        }

        prev = current;
        scanf("%d", &input); 
    }

    return head;
}

struct ListNode *deleteeven( struct ListNode *head ) {
    struct ListNode *p = head, *prev = NULL;

    for (; p != NULL; p = p->next) {
        if (p->data % 2 == 0) {
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
