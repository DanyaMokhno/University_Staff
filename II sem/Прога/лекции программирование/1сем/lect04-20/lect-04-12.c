/* Triangle array */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int **m2=NULL;
    int n,i,j,count;

    printf("Enter number of ROWS in array: ");
    scanf("%d",&n);

    if((m2=(int**)malloc(n*sizeof(int*)))!=NULL)
    {
        for (i=0,count=1;i<n;i++,count++)
        {
            if((m2[i]=(int*)malloc((i+1)*sizeof(int)))!=NULL)
            {
                for(j=i;j>0;j--)
                {
                    m2[i][j]=i*j;
                    printf("%4d",m2[i][j]);
                }
                printf("\n");
            }
            else
            {
                i=n;
                puts("ERROR at string allocation!");
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
        for (i=0;i<n;i++)
        {
            if(m2[i]!=NULL)
            {
                free(m2[i]);
                m2[i]=NULL;
            }
        }
        free(m2);
        m2=NULL;
    }
    else puts("Cannot allocate memory!!!");
    getchar();
    puts("Press ENTER when ready");
    getchar();

    return 0;
}
