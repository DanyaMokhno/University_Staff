#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Generate flat distributed random between 0 and k */
int my_rand(int k)
{
    return (int)((float)k*rand()/(RAND_MAX+1.0));
}

/* Generating one-dimension array of n integer */
int *int_array(int n, int k)
{
    int i;
    int *arr;
    if((arr=(int*)malloc(n*sizeof(int)))!=NULL)
    {
        for(i=0;i<n;i++) arr[i]=my_rand(k);
    }
    else arr=NULL;
    return arr;
}

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
    int *a=NULL;
    int i,m,n;

    srand(time(NULL));

    printf("Please enter number of elements: ");
    scanf("%d",&m);
    printf("Please enter max value of element: ");
    scanf("%d",&n);

    if((a=int_array(m,n))!=NULL)
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







