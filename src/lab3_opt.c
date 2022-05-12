/**
 * @file lab3.c
 * @author Bonino, Francisco Ignacio (franbonino82@gmail.com)
 * @brief Laboratorio #3 de la materia Sistemas Operativos II.
 * @version 0.8.1
 * @since 2022-04-13
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define XDIM 10000
#define YDIM 10000
#define PTR_SIZE sizeof(double *)

double **alloc_matrix(void)
{
    double **array = malloc(XDIM * PTR_SIZE);

    register unsigned short int i = XDIM;

    while (i--)
        *(array + i) = malloc(YDIM << 3);

    return array;
}

void fill(double **arr)
{
    register unsigned short int i, j;

    for (i = 0; i < XDIM; i++)
        for (j = 0; j < YDIM; j++)
            *(*(arr + i) + j) = (double)(rand() % 100);
}

void compute(double **arr)
{
    register unsigned short int i, j;

    __int8_t kern[3][3] = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};

    double tmp_sum[9];

    for (i = 1; i < XDIM - 1; i++)
        for (j = 1; j < YDIM - 1; j++)
        {
            tmp_sum[0] = kern[0][0] * arr[i - 1][j - 1] * 0.004 + 1;
            tmp_sum[1] = kern[0][1] * arr[i - 1][j] * 0.004 + 1;
            tmp_sum[2] = kern[0][2] * arr[i - 1][j + 1] * 0.004 + 1;
            tmp_sum[3] = kern[1][0] * arr[i][j - 1] * 0.004 + 1;
            tmp_sum[4] = kern[1][1] * arr[i][j] * 0.004 + 1;
            tmp_sum[5] = kern[1][2] * arr[i][j + 1] * 0.004 + 1;
            tmp_sum[6] = kern[2][0] * arr[i + 1][j - 1] * 0.004 + 1;
            tmp_sum[7] = kern[2][1] * arr[i + 1][j] * 0.004 + 1;
            tmp_sum[8] = kern[2][2] * arr[i + 1][j + 1] * 0.004 + 1;

            arr[i][j] = tmp_sum[0] + tmp_sum[1] + tmp_sum[2] + tmp_sum[3] + tmp_sum[4] + tmp_sum[5] + tmp_sum[6] + tmp_sum[7] + tmp_sum[8];
        }
}

void print(double **arr)
{
    register unsigned short int i, j;

    for (i = 0; i < XDIM; i++)
        for (j = 0; j < YDIM; j++)
            printf("array[%d][%d] = %f\n", i, j, *(*(arr + i) + j));
}

int main(void)
{
    double **arr = alloc_matrix();

    fill(arr);

    compute(arr);

    // print(arr);

    free(arr);

    return 0;
}