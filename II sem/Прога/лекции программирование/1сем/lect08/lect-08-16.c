#include <stdio.h>
#include <string.h>
#include <errno.h>
#define MAXLEN 80

int main()
{
    FILE *df;
    char str[MAXLEN];
    long pos;
    int n;

    if((df=fopen("data0.txt","r"))!=NULL)
    {
        if(fseek(df,17,SEEK_SET)==0)
        {
            pos=ftell(df);
            fgets(str,MAXLEN,df); // reading from POS to end of line!!
            n=strlen(str);
            str[n-1]='\0';
            printf("%s %ld\n",str,pos);
        }
        if(fclose(df)==EOF) perror("Input closing error");
    }
    else perror("Input opening error");
    return 0;
}


