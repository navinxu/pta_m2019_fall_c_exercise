/*================================================================
*   Copyright (C) 2018 Navin Xu. All rights reserved.
*   
*   Filename    ：Week07-02-saddle-matrix.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2018年12月30日
*   Description ：
        鞍点（5分）
        题目内容：
        
        给定一个n*n矩阵A。矩阵A的鞍点是一个位置（i，j），在该位置上的元素是第i行上的最大数，第j列上的最小数。一个矩阵A也可能没有鞍点。
        
        你的任务是找出A的鞍点。
        
        输入格式:
        
        输入的第1行是一个正整数n, （1<=n<=6），然后有n行，每一行有n个整数，同一行上两个整数之间有一个或多个空格。
        
        
        
        输出格式：
        
        对输入的矩阵，如果找到鞍点，就输出其下标。下标为两个数字，第一个数字是行号，第二个数字是列号，均从0开始计数。
        
        如果找不到，就输出
        
        NONE
        
        题目所给的数据保证了不会出现多个鞍点。
        
        
        
        输入样例：
        
        4 
        
        1 7 4 1 
        
        4 8 3 6 
        
        1 6 1 2 
        
        0 7 8 9
        
        
        
        输出样例：
        
        2 1
        
        
        我的样例：
        1 7 4 11
        4 8 3 60
        1 9 1 8
        0 7 8 29
        输出：
        NONE
        
        1 7 4 11
        4 8 3 60
        1 9 1 10
        0 7 8 29
        输出：
        2 3
        
        1 8 3
        4 7 6
        9 9 0
        输出：
        1 1
        
        0 0 0 0
        0 0 0 0
        0 0 0 0
        0 0 0 0
        
        10 10 10 10
        10 10 10 10
        10 10 10 10
        10 10 10 10
        
        以上两个测试点结果都为：
        0 0
        
        
        时间限制：500ms内存限制：32000kb
================================================================*/
#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    if (n >= 1 && n <= 6) {
        int matrix[n][n];

        for (int i = 0;i < n; i ++)
            for (int j = 0; j < n; j ++)
                scanf("%d", &matrix[i][j]);

        //for (int i = 0;i < n; i ++)
        //    for (int j = 0; j < n; j ++)
        //        printf("%d%c", matrix[i][j], (j == n - 1) ? '\n' : ' ');
        
        int row_max_point[n][n];
        int col_min_point[n][n];

        for (int i = 0;i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                row_max_point[i][j] = 0;
                col_min_point[i][j] = 0;
            }
        }

        int max_col = 0, max_row = 0;
        for (int i = 0;i < n; i ++) {
            max_col = 0;
            max_row = i;
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j] > matrix[max_row][max_col]) {
                    max_row = i;
                    max_col = j;
                }
            }
            row_max_point[max_row][max_col] = 1;
        }


        for (int i = 0;i < n; i ++) {
            for (int j = 0; j < n; j ++) {
            }
        }

        for (int i = 0;i < n; i ++)
            for (int j = 0; j < n; j ++)
                printf("%d%c", row_max_point[i][j], (j == n - 1) ? '\n' : ' ');
        return 0;


        int min_col = 0, min_row = 0;
        for (int i = 0;i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (matrix[j][i] < matrix[min_col][min_row]) {
                    min_row = i;
                    min_col = j;
                }
            }
            col_min_point[min_row][min_col] = 1;
        }

        for (int i = 0;i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (matrix[j][i] == matrix[min_col][min_row] && i != min_row) {
                    row_max_point[j][i] = 1;
                }
            }
        }

        for (int i = 0;i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (row_max_point[i][j] == 1 && col_min_point[i][j] == 1) {
                    printf("%d %d", i, j);
                    break;
                }
            }
        }
    }


    return 0;
}
