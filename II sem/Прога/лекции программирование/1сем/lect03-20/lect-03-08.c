#include <stdio.h>

#define MSIZE 10

int main()
{
    int m1[MSIZE];
    int i,n;

    do
    {
        printf("Enter n (from 1 to %d): ", MSIZE);
        scanf("%d", &n);
    }while((n<1)||(n>MSIZE));
/* Entering of array */
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ",i);
        scanf("%d", &m1[i]);
    }
/* Printing of array elements */
    puts("\nActual array is:");
    for(i=0;i<n;i++) printf("m1[%d]= %d\n",i,m1[i]);
    getchar();
    puts("Press ENTER when ready");
    getchar();

    return 0;
}

