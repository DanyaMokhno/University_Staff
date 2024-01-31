#include <stdio.h>
#include <errno.h>
#define MAXLEN 256

int main()
{
    FILE *infile, *outfile;
    int n;
    char c;

    n=0;
    if((infile=fopen("data0.txt","r"))!=NULL)
    {
        if((outfile=fopen("results00.txt","w"))!=NULL)
        {
           while(((c=fgetc(infile))!=EOF) && n<MAXLEN)
           {
                fputc(c,outfile);
                printf("%d ",c);
                //ungetc(c,infile);
                n++;
           }
           if(fclose(outfile)==EOF) perror("Output closing error");
        }
        else perror("Output opening error");
        if(fclose(infile)==EOF) perror("Input closing error");
    }
    else perror("Input opening error");

    return 0;
}
