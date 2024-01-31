#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<errno.h>

/* Create 2D array */
int **create_array(int n, int m);

/* Main program */
int main()
{
    int rows,cols,n;
    int i,j;
    FILE *infile;
    int **m2=NULL;

    printf("Enter number of ROWS: ");
    scanf("%d",&rows);
    printf("Enter number of COLUMNS: ");
    scanf("%d",&cols);

    m2=create_array(rows,cols);
    if(m2!=NULL)
    {
        if((infile=fopen("out01.bin","r"))!=NULL)
        {
            for(i=0;i<rows;i++)
            {
                n=fread(m2[i],sizeof(int),cols,infile);
                printf("Readed blocks: %d\n",n);
            }

            if(fclose(infile)==EOF) perror("Closing error!");
            for(i=0;i<rows;i++)
            {
                for(j=0;j<cols;j++) printf("%3d",m2[i][j]);
                printf("\n");
            }
        }
        else perror("Opening error!");
    }
    else puts("Memory allocation error. STOPPED.");
    return 0;

}

/* Implementation of functions */
int **create_array(int n, int m)
{
    int i,count;
    int **arr2=NULL;

    arr2=(int**)calloc(n,sizeof(int*));
    if(arr2!=NULL)
    {
        for(i=0,count=0;i<n;i++)
        {
            if((arr2[i]=(int*)calloc(m,sizeof(int)))!=NULL) count++;
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

