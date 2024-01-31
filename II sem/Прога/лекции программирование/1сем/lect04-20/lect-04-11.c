#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int m,n,i,j,count,maxval;
    float **m2=NULL;

    printf("Enter array size ROWS COLS: ");
    scanf("%d %d", &m, &n);
    printf("Enter MAX value for array: ");
    scanf("%d",&maxval);

    srand(time(NULL));

    if ((m2=(float**)malloc(m*sizeof(float*)))!=NULL)
    {
        i=0;
        count=1;
        while(i<m)
        {
            if ((m2[i]=(float*)malloc(n*sizeof(float)))!=NULL)
            {
                for(j=0;j<n;j=j+1)
                {
                    m2[i][j]=maxval*(float)(rand()/(RAND_MAX+1.0));
                    printf("%8.3f ", m2[i][j]);
                }
                i=i+1;
                count=count+1;
                printf("\n");
            }
            else
            {
                i=m;
                printf("ERROR at string allocation!\n");
                for(i=0;i<count;i=i+1)
                {
                    if (m2[i]!=NULL)
                    {
                        free(m2[i]);
                        m2[i]=NULL;
                    }
                }
            }
        }
        for(i=0;i<m;i=i+1)
        {
           if (m2[i]!=NULL)
           {
               free(m2[i]);
               m2[i]=NULL;
           }
        }
        free(m2);
        m2=NULL;
    }
    else printf("ERROR at array allocation!\n");
    return 0;
}
