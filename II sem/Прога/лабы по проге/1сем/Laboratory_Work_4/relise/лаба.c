#include <stdio.h>

#define SIZE 100

void io(int (*arr)[SIZE], int rows, int collumns, int status);

void copy(int (*arr)[SIZE], int (*new_arr)[SIZE], int rows, int n, int k);

int main()
{
    int arr[SIZE][SIZE];
    int new_arr[SIZE][SIZE];
    int rows, collumns;
    int n_collumns = 0;
    int n;
    int i, j;
    int counter;
    int flag;

    scanf("%i %i", &rows, &collumns);
    scanf("%i", &n);

    io(arr, rows, collumns, 1);
    io(arr, rows, collumns, 0);

    for (j = 0; j < collumns; j++)
    {
        counter = 1;
        flag = 0;
        for (i = 1; i < rows; i++)
        {
            if ((arr[i][j] < 0 && arr[i - 1][j] < 0) ||
                (arr[i][j] > 0 && arr[i - 1][j] > 0))
            {
                counter++;
                if (counter == n)
                    flag = 1;
                else if (counter > n)
                    flag = 0;
            }
            else
            {
                counter = 1;
            }
        }
        if (flag)
        {
            copy(arr, new_arr, rows, j, n_collumns);
            n_collumns++;
        }
    }

    io(new_arr, rows, n_collumns, 0);

    return 0;
}

void io(int (*arr)[SIZE], int rows, int collumns, int status)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < collumns; j++)
        {
            if (status == 1)
                scanf("%i", &arr[i][j]);
            else
                printf("%i ", arr[i][j]);
        }
        if (status == 0)
            printf("\n");
    }
    printf("\n");
}

void copy(int (*arr)[SIZE], int (*new_arr)[SIZE], int rows, int n, int k)
{
    for (int i = 0; i < rows; i++)
        new_arr[i][k] = arr[i][n];
}