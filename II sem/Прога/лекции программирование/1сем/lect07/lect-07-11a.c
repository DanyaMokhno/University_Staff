#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 60

int main()
{
    char **str1=NULL;
    char *s1=NULL;
    int i,n,n1,count;
    int *slen=NULL;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    str1=(char**)malloc(n*sizeof(char*)); /* array of strings */
    slen=(int*)malloc(n*sizeof(int)); /* array of strings length */

    if((str1!=NULL)&&(slen!=NULL))
    {
        for(i=0;i<MAXLEN;i++) putchar('-');

        printf("\nPlease enter strings\n");
        getchar();

        for(i=0,count=0;i<n;i++,count++) /* filling array */
        {
            printf("String %d: ",i);
            s1=(char*)malloc(MAXLEN*sizeof(char));
            if(s1!=NULL) /* getting dynamic string */
            {
                fgets(s1,MAXLEN,stdin);
                n1=strlen(s1);
                s1[n1-1]='\0';

                str1[i]=(char*)malloc(n1*sizeof(char));
                if(str1[i]!=NULL)
                {
                    strncpy(str1[i],s1,n1-1);
                    slen[i]=strlen(str1[i]);
                    free(s1);
                    s1=NULL;
                }
                else
                {
                    i=n;
                    printf("Error at allocation string in array!!\n");
                    free(s1);
                    s1=NULL;
                }
            }
            else puts("Fail at string allocation!");
        }
        if(count==n) /* output of correct array */
        {
            for(i=0;i<MAXLEN;i++) putchar('-');
            printf("\nResults of processing\n");

            for(i=0;i<n;i=i+1)
            {
                printf("String %d \"%s\" has really %d symbols\n",i,str1[i],slen[i]);
                free(str1[i]);
                str1[i]=NULL;
            }
        }
        else /* erase of missing array */
        {
            for(i=0;i<count;i++)
            {
                free(str1[i]);
                str1[i]=NULL;
            }
        }
        free(str1);
        str1=NULL;
        free(slen);
        slen=NULL;
    }
    else printf("Error at memory allocation!\n");
    return 0;
}

