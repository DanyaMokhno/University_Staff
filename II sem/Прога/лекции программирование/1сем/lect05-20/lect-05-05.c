#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 16

/* Sorting array by insertion method */
void sort_array1(int arr[], int n)
{
    int i,j,tmp;

    for(i=0;i<n;i=i+1)
    {
        tmp=arr[i];
        for(j=i-1;(j>=0)&&(arr[j]>tmp);j=j-1) arr[j+1]=arr[j];
        arr[j+1]=tmp;
    }

}

int main()
{
    int a[MAX_SIZE];
    int i;

    srand(time(NULL));
/* Generating an array */
    puts("Initial array:");
    for(i=0;i<MAX_SIZE;i++)
    {
        a[i]=(int)((float)MAX_SIZE*rand()/(RAND_MAX+1.0));
        printf("%3d ", a[i]);
    }

    sort_array1(a,MAX_SIZE);
    puts("\nSorted array:");
    for(i=0;i<MAX_SIZE;i++) printf("%3d ",a[i]);

    puts("\nPress ENTER when ready");
    getchar();
    return 0;
}





