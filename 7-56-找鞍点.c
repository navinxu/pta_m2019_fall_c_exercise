/*================================================================
*   Copyright (C) 2018 Navin Xu. All rights reserved.
*   
*   Filename    ：7-56-找鞍点.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2019年09月22日
*   Description ：
    7-56 找鞍点 (20 point(s))
    一个矩阵元素的“鞍点”是指该位置上的元素值在该行上最大、在该列上最小。
    
    本题要求编写程序，求一个给定的n阶方阵的鞍点。
    
    输入格式：
    输入第一行给出一个正整数n（1≤n≤6）。随后n行，每行给出n个整数，其间以空格分隔。
    
    输出格式：
    输出在一行中按照“行下标 列下标”（下标从0开始）的格式输出鞍点的位置。如果鞍点不存在，则输出“NONE”。题目保证给出的矩阵至多存在一个鞍点。
    
    输入样例1：
    4
    1 7 4 1
    4 8 3 6
    1 6 1 2
    0 7 8 9
    输出样例1：
    2 1
    输入样例2：
    2
    1 7
    4 1
    输出样例2：
    NONE
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


        int temp;
        // 如一行中有相同的最大数，
        // 那么就必须是索引最小的一个首先被加入
        for (int i = 0;i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (row_max_point[i][j] == 1) {
                    temp = matrix[i][j];
                    continue;
                }

                if (temp == matrix[i][j])
                    row_max_point[i][j] = 1;
            }
        }

        //printf("\n==============\n");
        //for (int i = 0;i < n; i ++)
        //    for (int j = 0; j < n; j ++)
        //        printf("%d%c", row_max_point[i][j], (j == n - 1) ? '\n' : ' ');
        ////return 0;

        //printf("\n==============\n");

        int min_col = 0, min_row = 0;
        int matrix2[n][n];
        // 此 for 有大 Bug
        for (int i = 0;i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                //printf("%d%c", matrix[j][i], (j == n -1 ) ? '\n' : ' ');
                matrix2[i][j] = matrix[j][i];
            }
        }

        for (int i = 0;i < n; i ++) {
            min_col = 0;
            min_row = i;
            for (int j = 0; j < n; j ++) {
                if (matrix2[i][j] < matrix2[min_row][min_col]) {
                    min_row = i;
                    min_col = j;
                }
            }
            col_min_point[min_col][min_row] = 1;
        }

        for (int i = 0;i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (col_min_point[j][i] == 1) {
                    temp = matrix[j][i];
                    continue;
                }

                if (temp == matrix[j][i]) {
                    col_min_point[j][i] = 1;
                }
            }
        }

        //printf("\n==============\n");
        //for (int i = 0;i < n; i ++)
        //    for (int j = 0; j < n; j ++)
        //        printf("%d%c", col_min_point[i][j], (j == n - 1) ? '\n' : ' ');

        //printf("\n++++++++++\n");
        unsigned char found = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n ; j ++) {
                if (col_min_point[i][j] == 1 && row_max_point[i][j] == 1) {
                    printf("%d %d", i, j);
                    found = 1;
                    break;
                }
            }

            if (found)
                break;
        }

        if (!found)
            printf("NONE");
    }
    return 0;
}
