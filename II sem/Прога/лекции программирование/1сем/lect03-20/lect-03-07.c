#include <stdio.h>

#define MSIZE 8

int main()
{
    int m1[MSIZE];
    int i;
/* Entering of array */
    for(i=0;i<MSIZE;i++)
    {
        printf("Enter element %d: ",i);
        scanf("%d", &m1[i]);
    }
/* Printing of array elements */
    puts("\nActual array is:");
    for(i=0;i<MSIZE;i++) printf("m1[%d]= %d\n",i,m1[i]);
    getchar();
    puts("Press ENTER when ready");
    getchar();

    return 0;
}
