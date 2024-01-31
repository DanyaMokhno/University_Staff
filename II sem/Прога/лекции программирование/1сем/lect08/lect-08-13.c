#include <stdio.h>
#include <errno.h>
#define MAXLEN 80

int main()
{
    FILE *df;
    int n;
    long dataOffset;
    fpos_t p;
    char c;

    if((df=fopen("data0.txt","r"))!=NULL)
    {
        n=0;
        while(((c=fgetc(df))!=EOF) && n<MAXLEN)
        {
            fgetpos(df,&p);
            dataOffset=p.__pos;
            printf("%c %ld\n",c,dataOffset);
            n++;
        }
    if(fclose(df)==EOF) perror("Input closing error");
    }
    else perror("Input opening error");
    return 0;
}
