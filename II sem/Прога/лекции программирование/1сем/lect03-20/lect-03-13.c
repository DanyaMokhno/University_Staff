/* Calculate sum of elements with even indexes */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 16

int main()
{
    int a[MAX_SIZE];
    int i,my_sum;

    my_sum=0;
    srand(time(NULL));
/* Generating and output of array */
    puts("Initial array:");
    for(i=0;i<MAX_SIZE;i++)
    {
        a[i]=(int)((float)MAX_SIZE*rand()/(RAND_MAX+1.0));
        printf("%3d ", a[i]);
    }
/* Calculating sum
   Zero is even!   */
    for(i=0;i<MAX_SIZE;i++)
    {
        if(i%2==0) my_sum=my_sum+a[i];
    }
    printf("\nSum of values with even indexes: %d",my_sum);
    puts("\nPress ENTER when ready");
    getchar();
    return 0;
}

