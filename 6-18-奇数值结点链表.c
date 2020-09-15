/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-18-奇数值结点链表.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年10月16日
*   Description ：
        6-18 奇数值结点链表 (20 point(s))
        本题要求实现两个函数，分别将读入的数据存储为单链表、将链表中奇数值的结点重新组成一个新的链表。链表结点定义如下：
        
        struct ListNode {
            int data;
            ListNode *next;
        };
        函数接口定义：
        struct ListNode *readlist();
        struct ListNode *getodd( struct ListNode **L );
        函数readlist从标准输入读入一系列正整数，按照读入顺序建立单链表。当读到−1时表示输入结束，函数应返回指向单链表头结点的指针。
        
        函数getodd将单链表L中奇数值的结点分离出来，重新组成一个新的链表。返回指向新链表头结点的指针，同时将L中存储的地址改为删除了奇数值结点后的链表的头结点地址（所以要传入L的指针）。
        
        裁判测试程序样例：
        #include <stdio.h>
        #include <stdlib.h>
        
        struct ListNode {
            int data;
            struct ListNode *next;
        };
        
        struct ListNode *readlist();
        struct ListNode *getodd( struct ListNode **L );
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
            struct ListNode *L, *Odd;
            L = readlist();
            Odd = getodd(&L);
            printlist(Odd);
            printlist(L);
        
            return 0;
        }
        
        // 你的代码将被嵌在这里
        输入样例：
        1 2 2 3 4 5 6 7 -1
        输出样例：
        1 3 5 7 
        2 2 4 6 
================================================================*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *getodd( struct ListNode **L );
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
    struct ListNode *L, *Odd;
    L = readlist();
    Odd = getodd(&L);
    printlist(Odd);
    printlist(L);

    return 0;
}

// 以下是有效代码
struct ListNode* getodd(struct ListNode **L) {
    struct ListNode *pHead = NULL, *pCurrent = NULL, *pPrev = NULL, *head = NULL, *current = NULL, *prev = NULL;
    
    while (*L) {
        if ((*L)->data % 2 ) {
            if (!pHead) {            
                pHead = *L;
                pCurrent = pHead;
            } else {
                pCurrent = *L;
                pPrev->next = pCurrent;
            }
            pPrev = pCurrent;
        } else {
            if (!head) {
                head = *L;
                current = head;
            } else {
                current = *L;
                prev->next = current;
            }

            prev = current;
        }

        *L = (*L)->next;
    }

    if (pHead)
        pCurrent->next = NULL;

    if (head)
        current->next = NULL;

    *L = head;

    return pHead;
}

struct ListNode *readlist() {
    int i;
    scanf("%d", &i);

    struct ListNode* pHead = NULL;
    struct ListNode* pCurrent = NULL;
    struct ListNode* pPrev = NULL;
    while (i != -1) {
        
        if (!pHead) {
            pHead = (struct ListNode*) malloc(sizeof(struct ListNode));
            pHead->data = i;
            // printf("%d ", pHead->data);
            pCurrent = pHead;
        } else {
            pCurrent = (struct ListNode*) malloc(sizeof(struct ListNode));
            pCurrent->data = i;
            // printf("%d:%d ", pHead->data, pCurrent->data);
            pPrev->next = pCurrent;
        }

        if (!pPrev)
            pPrev = (struct ListNode*) malloc(sizeof(struct ListNode));

        pPrev = pCurrent;
        scanf("%d", &i);
    }

    if (pHead)
        pCurrent->next = NULL;

    return pHead;
}
