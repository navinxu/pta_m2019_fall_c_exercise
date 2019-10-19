/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-19-单链表结点删除.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月19日
*   Description ：
6-19 单链表结点删除 (20 point(s))
本题要求实现两个函数，分别将读入的数据存储为单链表、将链表中所有存储了某给定值的结点删除。链表结点定义如下：

struct ListNode {
    int data;
    ListNode *next;
};
函数接口定义：
struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
函数readlist从标准输入读入一系列正整数，按照读入顺序建立单链表。当读到−1时表示输入结束，函数应返回指向单链表头结点的指针。

函数deletem将单链表L中所有存储了m的结点删除。返回指向结果链表头结点的指针。

裁判测试程序样例：
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);

    return 0;
}

// 你的代码将被嵌在这里
输入样例：
10 11 10 12 10 -1
10 11 10 10 12 10 -1
10
输出样例：
11 12 
================================================================*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);

    return 0;
}

struct ListNode* deletem(struct ListNode* L, int m) {
    struct ListNode* temp = L;
    struct ListNode *pHead = NULL, *pCurrent = NULL, *pPrev = NULL;
    pHead = L;
    while (temp) {
        if (temp->data == m) {
            if (temp == pHead) {
                // printf("head: %d,", m);
                // printf("\n");
                pCurrent = pHead->next;
                pHead = pCurrent;
            } else {
                pCurrent = pPrev;
                pCurrent->next = temp->next;
            }
        } else 
            pPrev = temp;
        // printf("\n");
        // printf("temp: %d,", temp->data);
        temp = temp->next;
    }
    if (pHead)
        pCurrent = NULL;

    return pHead;
}

struct ListNode* readlist() {
    int num;
    scanf("%d", &num);

    struct ListNode *pHead = NULL, *pCurrent = NULL, *pPrev = NULL;

    while (num != -1) {
        if (!pHead) {
            pHead = (struct ListNode*) malloc(sizeof(struct ListNode));
            pHead->data = num;
            pCurrent = pHead;
        } else {
            pCurrent = (struct ListNode*) malloc(sizeof(struct ListNode));
            pCurrent->data = num;
            pPrev->next = pCurrent;
        }

        pPrev = pCurrent;
        scanf("%d", &num);
    }

    if (pHead)
        pCurrent->next = NULL;

    return pHead;
}

