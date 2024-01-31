#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_1d(float *arr, int m);

void print_2d(int **arr2, int n, int m);

int my_rand(int rmax);

int **make_array(int n, int m);

void fill_array(int **arr2, int n, int m);

float *process_array(int **arr2, int n, int m);


int main()
{
    int **m2=NULL;
    float *m1=NULL;
    int n,m;
    int i;

    srand(time(NULL));
    printf("Set array sizes (n,m) by space: ");
    scanf("%d %d",&n,&m);

    m2=make_array(n,m);
    if(m2!=NULL)
    {
        fill_array(m2,n,m);

        for(i=0;i<n;i++)
        {
           free(m2[i]);
           m2[i]=NULL;
        }
        free(m2);
    }

    return 0;
}

void print_1d(float *arr, int m)
{
    int i;

    for(i=0;i<m;i++) printf("%8.2f ",arr[i]);
    printf("\n");
}

void print_2d(int **arr2, int n, int m)
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++) printf("%3d ",arr2[i][j]);
        printf("\n");
    }
}

int **make_array(int n, int m)
{
    int **arr2=NULL;
    int i,count;

    arr2=(int**)calloc(n,sizeof(int*));
    if(arr2!=NULL)
    {
       for(i=0,count=1;i<n;i++,count++)
        {
            arr2[i]=(int*)calloc(m,sizeof(int));
            if(arr2[i]==NULL) i=n;
        }
        if(count<n)
        {
            for(i=0;i<count;i++)
            {
                free(arr2[i]);
                arr2[i]=NULL;
            }
            arr2=NULL;
        }

    }
    else puts("Do NOTHING! No memory allocated!");

    return arr2;
}

void fill_array(int **arr2, int n, int m)
{
    char way;
    int maxval;
    int i,j;

    printf("Choose the way to make array\n");
    printf("r - by random, any other char - by hands ");
    getchar();
    way=getchar();
    if(way=='r')
    {
        printf("Set max value for random numbers: ");
        scanf("%d",&maxval);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++) arr2[i][j]=my_rand(maxval);
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("Element [%d][%d]: ",i,j);
                scanf("%d",&arr2[i][j]);
            }
        }
    }
    print_2d(arr2,n,m);
}

int my_rand(int rmax)
{
    return (int)(rmax*(float)rand()/(RAND_MAX+1.0));
}
