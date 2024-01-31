#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<errno.h>

/* Generate flat distributed random between 0 and k */
int my_rand(int k);

/* Generate 2D random array */
int **int_array(int n, int m, int k);

/* Main program */
int main()
{
    int rows,cols,num,n,i;
    FILE *outfile;
    int **m2=NULL;

    printf("Enter number of ROWS: ");
    scanf("%d",&rows);
    printf("Enter number of COLUMNS: ");
    scanf("%d",&cols);
    printf("Enter MAX value in array: ");
    scanf("%d",&num);

    m2=int_array(rows,cols,num);
    if(m2!=NULL)
    {
        if((outfile=fopen("out01.bin","w"))!=NULL)
        {
            for(i=0;i<rows;i++)
            {
                n=fwrite(m2[i],sizeof(int),cols,outfile);
                printf("Recorded blocks: %d\n",n);
            }
            if(fclose(outfile)==EOF) perror("Closing error!");
        }
        else perror("Opening error!");
    }
    else puts("Memory allocation error. STOPPED.");
    return 0;

}

/* Implementation of functions */
int my_rand(int k)
{
    return (int)((float)k*rand()/(RAND_MAX+1.0));
}
//-----------------------
int **int_array(int n, int m, int k)
{
    int i,j,count;
    int **arr2=NULL;

    arr2=(int**)calloc(n,sizeof(int*));
    if(arr2!=NULL)
    {
        for(i=0,count=0;i<n;i++,count++)
        {
            arr2[i]=(int*)calloc(m,sizeof(int));
            if(arr2[i]!=NULL)
            {
                for(j=0;j<m;j++) arr2[i][j]=my_rand(k);
            }
            else
            {
                i=n;
                puts("Error at string allocation!");
            }
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
    else arr2=NULL;
    return arr2;
}
