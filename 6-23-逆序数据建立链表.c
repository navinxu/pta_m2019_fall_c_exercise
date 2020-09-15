/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-23-逆序数据建立链表.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月25日
*   Description ：
        6-23 逆序数据建立链表 (20 point(s))
        本题要求实现一个函数，按输入数据的逆序建立一个链表。
        
        函数接口定义：
        struct ListNode *createlist();
        函数createlist利用scanf从输入中获取一系列正整数，当读到−1时表示输入结束。按输入数据的逆序建立一个链表，并返回链表头指针。链表节点结构定义如下：
        
        struct ListNode {
            int data;
            struct ListNode *next;
        };
        裁判测试程序样例：
        #include <stdio.h>
        #include <stdlib.h>
        
        struct ListNode {
            int data;
            struct ListNode *next;
        };
        
        struct ListNode *createlist();
        
        int main()
        {
            struct ListNode *p, *head = NULL;
        
            head = createlist();
            for ( p = head; p != NULL; p = p->next )
                printf("%d ", p->data);
            printf("\n");
        
            return 0;
        }
        
        // 你的代码将被嵌在这里
        输入样例：
        1 2 3 4 5 6 7 -1
        输出样例：
        7 6 5 4 3 2 1 
================================================================*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();

int main()
{
    struct ListNode *p, *head = NULL;

    head = createlist();
    for ( p = head; p != NULL; p = p->next )
        printf("%d ", p->data);
    printf("\n");

    return 0;
}

// 以下是有效代码
struct ListNode *createlist() {
    static struct ListNode *head = NULL, *current = NULL, *prev = NULL;

    int input;
    scanf("%d", &input);

    if (input != -1) {
        createlist();
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
    } else {
        return NULL;
    }


    return head;
}
