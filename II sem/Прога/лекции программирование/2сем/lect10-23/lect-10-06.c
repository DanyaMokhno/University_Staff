#include <stdio.h>
#include <errno.h>

int main()
{
    FILE *df;
    int i,n;
    long dataOffset;
    fpos_t p;
    char c;

    if((df=fopen("struct-data-03.txt","r"))!=NULL)
    {
        fseek(df,0,SEEK_SET);
        fseek(df,0,SEEK_END);
        n=ftell(df);
        rewind(df);
        for(i=0;i<n;i++)
        {
            if((c=fgetc(df))==';')
            {
                fgetpos(df,&p);
                dataOffset=p.__pos;
                printf("%c %ld\n",c,dataOffset);
            }
        }
    if(fclose(df)==EOF) perror("Input closing error");
    }
    else perror("Input opening error");
    return 0;
}

