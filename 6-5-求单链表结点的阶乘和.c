/*================================================================
*   Copyright (C) 2019 Navin Xu. All rights reserved.
*   
*   Filename    ：6-5-求单链表结点的阶乘和.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年09月26日
*   Description ：
        6-5 求单链表结点的阶乘和 (15 point(s))
        本题要求实现一个函数，求单链表L结点的阶乘和。这里默认所有结点的值非负，且题目保证结果在int范围内。
        
        函数接口定义：
        int FactorialSum( List L );
        其中单链表List的定义如下：
        
        typedef struct Node *PtrToNode;
        struct Node {
            int Data; // 存储结点数据
            PtrToNode Next; // 指向下一个结点的指针
        };
        typedef PtrToNode List; // 定义单链表类型
        裁判测试程序样例：
        #include <stdio.h>
        #include <stdlib.h>
        
        typedef struct Node *PtrToNode;
        struct Node {
            int Data; // 存储结点数据 
            PtrToNode Next; // 指向下一个结点的指针 
        };
        typedef PtrToNode List; // 定义单链表类型
        
        int FactorialSum( List L );
        
        int main()
        {
            int N, i;
            List L, p;
        
            scanf("%d", &N);
            L = NULL;
            for ( i=0; i<N; i++ ) {
                p = (List)malloc(sizeof(struct Node));
                scanf("%d", &p->Data);
                p->Next = L;  L = p;
            }
            printf("%d\n", FactorialSum(L));
        
            return 0;
        }
        
        // 你的代码将被嵌在这里
        输入样例：
        3
        5 3 6
        输出样例：
        846
================================================================*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int Data; // 存储结点数据
    PtrToNode Next; // 指向下一个结点的指针
};
typedef PtrToNode List; // 定义单链表类型

typedef struct Node *PtrToNode;
typedef PtrToNode List; // 定义单链表类型

int FactorialSum( List L );

int main()
{
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for ( i=0; i<N; i++ ) {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;  L = p;
    }
    printf("%d\n", FactorialSum(L));

    return 0;
}


int FactorialSum( List L ) {
    int sum = 0;
    int product = 1;
    int count = 1;
    while (L) {
        product = 1;
        count = 1;
        while (count <= L->Data) {
            product *= count ++;
        }
        sum += product;
        L = L->Next;
    }
    return sum;
}
