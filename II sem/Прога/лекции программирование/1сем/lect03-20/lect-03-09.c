#include <stdio.h>

#define ROWS 2
#define COLS 3

int main()
{
    int m2[ROWS][COLS];
    int i,j;
/* Entering of array */
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            printf("Enter element [%d][%d]: ",i,j);
            scanf("%d", &m2[i][j]);
        }
    }
/* Printing of array elements */
    puts("\nActual array is:");
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++) printf("%3d",m2[i][j]);
        printf("\n");
    }
    getchar();
    puts("Press ENTER when ready");
    getchar();

    return 0;
}
