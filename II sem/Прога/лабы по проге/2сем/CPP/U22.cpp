#include <stdio.h>
#include <stdlib.h>
#include <time.h>
template <class T>
T *make_array(int n)
{
    T *arr=NULL;
    int i;

    arr=(T*)malloc(n*sizeof(T));
    if(arr)
    {
        for(i=0;i<n;i++) arr[i]=rand()/10000000;
    }
    return arr;
}

template <class T>
void sort_arr(T *arr, int n)
{
    int i,j;
    T tmp;

    for(i=0;i<n;i++)
    {
        tmp=arr[i];
        for(j=i-1;(j>=0)&&(arr[j]>tmp);j=j-1) arr[j+1]=arr[j];
        arr[j+1]=tmp;
    }
}

void show_array(double *arr, int n)
{
    int i;
    for(i=0;i<n;i++) printf(" %3.2f", arr[i]);
    puts("");
}

int main()
{
    double *m1=NULL;
    int num;
    char s0[16];

    srand(time(NULL));

    printf("Enter number of elements: ");
    fgets(s0,16,stdin);
    num=atoi(s0);

    m1=make_array<double>(num);
    if(m1)
    {
        puts("Initial array:");
        show_array(m1, num);

        sort_arr<double>(m1, num);
        puts("Sorted array:");
        show_array(m1, num);
        free(m1);
        m1=NULL;
    }
    return 0;
}

