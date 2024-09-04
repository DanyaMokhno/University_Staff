#include <stdio.h>
#include <errno.h>

int main()
{
    FILE *df;
    long dataOffset;
    fpos_t p;
    char c;

    if((df=fopen("struct-data-03.txt","r"))!=NULL)
    {
        dataOffset=204;
        p.__pos=dataOffset;
        fsetpos(df,&p);
        c=fgetc(df);
        printf("Position: %ld char: %c\n",dataOffset,c);

        if(fclose(df)==EOF) perror("Input closing error");
    }
    else perror("Input opening error");
    return 0;
}


