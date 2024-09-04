#include <stdio.h>

int main() {
    int columns;
    int rows;
    int max = -10000, min = 10000;
    int arr[100][100];
    int i, j;

    
    scanf("%i", &columns);
    
    for (i = 0; i < columns; i++)
    {
        scanf("%i", &arr[0][i]);
        if (arr[0][i] > max)
        {
            max = arr[0][i];
        }
        if (min > arr[0][i])
        {
            min = arr[0][i];
        }
    }

    rows = max - min;
    
    for (i = 1; i < rows; i++)
        for (j = 0; j < columns; j++) {
            scanf("%i", &arr[i][j]);
        }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if (arr[rows-1][j]%2 != 0)
                printf("%i ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
