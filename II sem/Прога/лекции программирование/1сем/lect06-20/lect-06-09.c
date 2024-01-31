#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int cmp(int *a, int *b)
{
    return *a-*b;
}

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

        qsort(a,m,sizeof(int),(int(*)(const void*,const void*))cmp);

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


