/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-25-链表拼接.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月26日
*   Description ：
        6-25 链表拼接 (20 point(s))
        本题要求实现一个合并两个有序链表的简单函数。链表结点定义如下：
        
        struct ListNode {
            int data;
            struct ListNode *next;
        };
        函数接口定义：
        struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
        其中list1和list2是用户传入的两个按data升序链接的链表的头指针；函数mergelists将两个链表合并成一个按data升序链接的链表，并返回结果链表的头指针。
        
        裁判测试程序样例：
        #include <stdio.h>
        #include <stdlib.h>
        
        struct ListNode {
            int data;
            struct ListNode *next;
        };
        
        struct ListNode *createlist(); //裁判实现，细节不表
        struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
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
            struct ListNode  *list1, *list2;
        
            list1 = createlist();
            list2 = createlist();
            list1 = mergelists(list1, list2);
            printlist(list1);
        	
            return 0;
        }
        
        // 你的代码将被嵌在这里
        输入样例：
        1 3 5 7 -1
        2 4 6 -1
        输出样例：
        1 2 3 4 5 6 7 
================================================================*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); //裁判实现，细节不表
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
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
    struct ListNode  *list1, *list2;

    list1 = createlist();
    list2 = createlist();
    list1 = mergelists(list1, list2);
    printlist(list1);
	
    return 0;
}

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

// 有效代码
struct ListNode *mergelists( struct ListNode *list1, struct ListNode *list2 ) {
    struct ListNode *head = NULL, *temp1 = NULL, *temp2 = NULL;

    if (list1 && !list2) {
        return list1;
    }

    if (!list1 && list2) {
        return list2;
    }

    while (list1 && list2) {
        if (!head) {
            if (list1->data <= list2->data) {
                head = list1;
            } else {
                head = list2;
            }
        }
        if (list1->data <= list2->data) {
            temp1 = list1->next;
            list1->next = list2;
            temp2 = list2->next;
            list2->next = temp1;
            list2 = temp2;
            list1 = temp1;
        } else {
            temp2 = list2->next;
            list2->next = list1;
            temp1 = list1->next;
            list1->next = temp2;
            list2 = temp2;
            list1 = temp1;
        }
    }

    return head;
}

