#include <stdio.h>
#include <errno.h>
#define MAXLEN 80

int main()
{
    char str[MAXLEN];
    FILE *df;

    if((df=fopen("data03.txt","r"))!=NULL)
    {
        printf("File content: \n");
        while(feof(df)==0)
        {
            fgets(str,MAXLEN,df);
            printf("%s", str);
        }
        if(fclose(df)!=EOF) printf("Closing OK\n");
        else printf("Closing error code: %d\n", errno);
    }
    else perror("Opening error");
    return 0;
}
