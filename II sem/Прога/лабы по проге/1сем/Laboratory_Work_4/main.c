#include <stdio.h>

#define SIZE 100

void io(int (*arr)[SIZE], int rows, int collumns, int status); //Здесь int (*arr)[SIZE] указатель на массив из SIZE элементов типа int

void copy(int (*arr)[SIZE], int (*new_arr)[SIZE], int rows, int n, int k); // n = текущий столбец старого массива k = незаполненный столбец нового массива

int main() {
    int arr[SIZE][SIZE]; // массив
    int new_arr[SIZE][SIZE]; // преобразованный массив
    int rows, collumns; // кол-во строк и кол-во столбцов
    int n_collumns = 0; // кол-во столбцов нового массива
    int n; // заданное количество чисел одного знака
    int i, j; // итераторы
    int counter; // счётчик элементов одного знака в столбце
    int flag; // наличие подходящего числа в строке

    scanf("%i %i", &rows, &collumns); // получаем строки и столбцы
    scanf("%i", &n);

    //второй способ
    io(arr, rows, collumns, 1);
    io(arr, rows, collumns, 0);


    for (j = 0; j < collumns; j++) {
        counter = 1;
        flag = 0;
        for (i = 1; i < rows; i++) {
            if ((arr[i][j] < 0 && arr[i - 1][j] < 0) ||
                (arr[i][j] > 0 && arr[i - 1][j] > 0)) {
                counter++;
                if (counter == n)
                    flag = 1;
                else if (counter > n)
                    flag = 0;
            } else {
                counter = 1;
            }
        }
        if (flag) {
            copy(arr, new_arr, rows, j, n_collumns);
            n_collumns++;
        }
    }

    io(new_arr, rows, n_collumns, 0);
    return 0;
}

void io(int (*arr)[SIZE], int rows, int collumns, int status) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < collumns; j++) {
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

void copy(int (*arr)[SIZE], int (*new_arr)[SIZE], int rows, int n, int k) {

    for (int i = 0; i < rows; i++)
        new_arr[i][k] = arr[i][n];
}

/*
5 4
3
4 -3 2 2
3 -4 -3 -1
-2 0 -1 -3
0 9 -2 -3
-8 -7 9 8


4 4
2
1 2 2 -3
-2 3 5 -4
4 -3 -4 -3
0 -4 0 -43
*/
