#include <stdio.h>

int main() {
    int columns; // количество столбцов
    int rows; // кол-во строк
    int max = -10000, min = 10000; // максимальное и минимальное числа 0-й строки
    int arr[100][100];
    int i, j; //итераторы

    //получаем кол-во столбцов
    scanf("%i", &columns);
    // заполняем первую строку массива
    for (i = 0; i < columns; i++){
        scanf("%i", &arr[0][i]);
        if (arr[0][i] > max){
            max = arr[0][i];
        }
        if (min > arr[0][i]){
            min = arr[0][i];
        }
    }
    //вычисляем кол-во строк
    rows = max - min;
    // заполняем остальные строки массива
    for (i = 1; i < rows; i++)
        for (j = 0; j < columns; j++) {
            scanf("%i", &arr[i][j]);
        }

    //красивенько выводим массив
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if (arr[rows-1][j]%2 != 0)
                printf("%4i ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}