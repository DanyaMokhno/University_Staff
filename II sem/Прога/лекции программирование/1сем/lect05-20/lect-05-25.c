/**********************************************************
* From random integer matrix select elements bigger than  *
* given value and save them into vector.                  *
* Functions and memory allocation must be used            *
**********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Prototypes of functions                                */

/* Random value between 0 and given k                     */
int my_rand(int k);
/* Random matrix with given sizes                         */
int **create2d(int n, int m, int k);
/* Processing the matrix and creating vector              */
int *process(int **m2, int n, int m, int value);
/* Printing array line or vector                         */
void print1d(int *m1, int m);
/* Printing matrix                                       */
void print2d(int **m2, int n, int m);

int main()
{
    int **m2=NULL;
    int *m1=NULL;
    int n,m,i,k,value;

    srand(time(NULL));
    printf("Enter number rows and cols via space: ");
    scanf("%d %d",&n,&m);
    printf("Enter max random value: ");
    scanf("%d",&k);
    m2=create2d(n,m,k);

    if(m2!=NULL)
    {
        print2d(m2,n,m);
        printf("Enter value to select: ");
        scanf("%d",&value);
        m1=process(m2,n,m,value);
        if(m1!=NULL)
        {
            free(m1);
            m1=NULL;
        }
        for(i=0;i<n;i++)
        {
            free(m2[i]);
            m2[i]=NULL;
        }
        free(m2);
        m2=NULL;
    }
    else puts("No memory allocated!");

    return 0;
}

/* Implementation of functions                            */
int **create2d(int n, int m, int k)
{
    int **m2=NULL;
    int count;
    int i,j;

    m2=(int**)malloc(n*sizeof(int*));
    if(m2!=NULL)
    {
        for(i=0,count=0;i<n;i++,count++)
        {
            m2[i]=(int*)malloc(m*sizeof(int));
            /*printf("%p\n",m2[i]);*/
            if(m2[i]==NULL) i=n;
        }
        if(count==n)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++) m2[i][j]=my_rand(k);
            }
        }
        else
        {
            for(i=0;i<count;i++)
            {
                free(m2[i]);
                m2[i]=NULL;
            }
            free(m2);
            m2=NULL;
        }
    }
    return m2;
}
/* ----------------------------------------------------- */
int *process(int **m2, int n, int m, int value)
{
    int *m1=NULL;
    int i,j,k;
    k=0;
    m1=(int*)malloc(n*m*sizeof(int));
    if(m1!=NULL)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(m2[i][j]>value)
                {
                    m1[k]=m2[i][j];
                    k++;
                }
            }
        }
        m1=(int*)realloc(m1,k*sizeof(int));
        print1d(m1,k);
        puts("");
    }
    else puts("No 1d array...");
    return m1;
}
/* ----------------------------------------------------- */
int my_rand(int k)
{
    return (int)((float)k*rand()/(RAND_MAX+1.0));
}
/* ----------------------------------------------------- */
void print1d(int *m1, int m)
{
    int i;

    for(i=0;i<m;i++) printf("%4d ",m1[i]);
}
/* ----------------------------------------------------- */
void print2d(int **m2, int n, int m)
{
    int k;
    for(k=0;k<n;k++)
    {
        print1d(m2[k],m);
        puts("");
    }
}
