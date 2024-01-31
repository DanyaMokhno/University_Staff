#include <stdio.h>
#include <errno.h>
#define MAXLEN 80

int main()
{
    FILE *df;
    char c;
    long pos;
    int n;

    if((df=fopen("data0.txt","r"))!=NULL)
    {
        if(fseek(df,0,SEEK_SET)==0)
        {
            n=0;
            while(((c=fgetc(df))!=EOF) && n<MAXLEN)
            {
                if(c=='t')
                {
                    pos=ftell(df);
                    printf("%ld\n",pos);
                }
            }
        }
        if(fclose(df)==EOF) perror("Input closing error");
    }
    else perror("Input opening error");
    return 0;
}



