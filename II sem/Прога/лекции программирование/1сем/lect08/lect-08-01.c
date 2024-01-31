#include <stdio.h>
#include <errno.h>
#define MAXLEN 80

int main()
{
    char str[MAXLEN];
    FILE *df;

    if((df=fopen("data0.txt","r"))!=NULL)
    {
        printf("File content: \n");
        while(fgets(str,MAXLEN,df)!=NULL) printf("%s", str);

        if(fclose(df)!=EOF) printf("Closing OK\n");
        else printf("Closing error code: %d\n", errno);
    }
    else perror("Data error");
    return 0;
}
