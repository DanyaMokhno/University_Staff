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

void swap(int *a, int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}

void my_qsort(int *arr,int b,int e)
{
    int left,right,middle;

    left=b;
    right=e;
    middle=arr[(left + right) / 2]; /* It's a reference element */
    while(left<=right)
    {
        while(arr[left]<middle) left++;
        while(arr[right]>middle) right--;
        if(left<=right) swap(&arr[left++],&arr[right--]);
    }
    if(b<right) my_qsort(arr,b,right);
    if(e>left) my_qsort(arr,left,e);
}
/* my_qsort (arr,0, n-1); */

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

        my_qsort(a,0,m-1);

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

