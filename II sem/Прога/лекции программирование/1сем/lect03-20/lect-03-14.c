/* Output count and indexes of elements with given value */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 16

int main()
{
    int a[MAX_SIZE];
    int b[MAX_SIZE];
    int i,j,my_count;
    int value;

    my_count=0;
    j=0;
    srand(time(NULL));
/* Generating and output of array */
    puts("Initial array:");
    for(i=0;i<MAX_SIZE;i++)
    {
        a[i]=(int)((float)MAX_SIZE*rand()/(RAND_MAX+1.0));
        printf("%3d ", a[i]);
    }
    printf("\nEnter value to find: ");
    scanf("%d",&value);
/* Processing initial array */
    for(i=0;i<MAX_SIZE;i++)
    {
        if(a[i]==value)
        {
            my_count=my_count+1;
            b[j]=i;
            j=j+1;
        }
    }
    printf("Total found %d values\n",my_count);
    printf("Indexes of values: ");
    for(j=0;j<my_count;j++) printf("%3d",b[j]);
    getchar();
    puts("\nPress ENTER when ready");
    getchar();
    return 0;
}


