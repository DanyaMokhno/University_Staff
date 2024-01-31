#include <stdio.h>
#include <errno.h>
#define MAXLEN 80

int main()
{
    FILE *df;
    long dataOffset;
    fpos_t p;
    char c;

    if((df=fopen("data0.txt","r"))!=NULL)
    {
        p.__pos=20;
        fsetpos(df,&p);
        c=fgetc(df);
        dataOffset=p.__pos;
        printf("%ld %c\n",dataOffset,c);
        if(fclose(df)==EOF) perror("Input closing error");
    }
    else perror("Input opening error");
    return 0;
}

