#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Generating one-dimension array of integer */
int *int_array(int);

/* Sorting array by insertion method */
void sort_array1(int*, int);

int main()
{
    int *a=NULL;
    int i,m;

    srand(time(NULL));

    printf("Please enter number of elements: ");
    scanf("%d",&m);
    if((a=int_array(m))!=NULL)
    {
        puts("Initial array:");
        for(i=0;i<m;i++) printf("%3d ", a[i]);

        sort_array1(a,m);

        puts("\nSorted array:");
        for(i=0;i<m;i++) printf("%3d ",a[i]);

        free(a);
        a=NULL;

        getchar();
        puts("\nPress ENTER when ready");
        getchar();
    }
    else puts("Error at memory allocation!");
    return 0;
}

int *int_array(int n)
{
    int i;
    int *arr;
    if((arr=(int*)malloc(n*sizeof(int)))!=NULL)
    {
        for(i=0;i<n;i++) arr[i]=(int)((float)n*rand()/(RAND_MAX+1.0));
    }
    else arr=NULL;
    return arr;
}

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








