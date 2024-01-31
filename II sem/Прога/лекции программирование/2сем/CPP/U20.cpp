#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *make_array(int n)
{
    int *arr=NULL;
    int i;

    arr=(int*)malloc(n*sizeof(int));
    if(arr)
    {
        for(i=0;i<n;i++) arr[i]=rand()/10000000;
    }
    return arr;
}

void sort_int(int *arr, int n)
{
    int i,j;
    int tmp;

    for(i=0;i<n;i++)
    {
        tmp=arr[i];
        for(j=i-1;(j>=0)&&(arr[j]>tmp);j=j-1) arr[j+1]=arr[j];
        arr[j+1]=tmp;
    }
}

void show_array(int *arr, int n)
{
    int i;
    for(i=0;i<n;i++) printf(" %3d", arr[i]);
    puts("");
}

int main()
{
    int *m1=NULL;
    int num;
    char s0[16];

    srand(time(NULL));

    printf("Enter number of elements: ");
    fgets(s0,16,stdin);
    num=atoi(s0);

    m1=make_array(num);
    if(m1)
    {
        puts("Initial array:");
        show_array(m1, num);

        sort_int(m1, num);
        puts("Sorted array:");
        show_array(m1, num);
        free(m1);
        m1=NULL;
    }
    return 0;
}
