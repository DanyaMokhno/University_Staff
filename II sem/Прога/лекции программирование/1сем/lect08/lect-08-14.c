#include <stdio.h>
#include <errno.h>
#define MAXLEN 80

int main()
{
    FILE *df;
    int n;
    long dataOffset;
    fpos_t p;
    char str[MAXLEN];

    if((df=fopen("data0.txt","r"))!=NULL)
    {
        n=0;
        while(fgets(str,MAXLEN,df)!=NULL)
        {
            fgetpos(df,&p);
            dataOffset=p.__pos;
            printf("%ld %s\n",dataOffset,str);
            n++;
        }
    if(fclose(df)==EOF) perror("Input closing error");
    }
    else perror("Input opening error");
    return 0;
}
