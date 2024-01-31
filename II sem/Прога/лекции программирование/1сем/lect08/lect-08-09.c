#include <stdio.h>
#include <errno.h>
#define MAXLEN 80

int main()
{
    FILE *infile, *outfile;
    char str[MAXLEN];

    if((infile=fopen("data0.txt","r"))!=NULL)
    {
        if((outfile=fopen("results01.txt","w"))!=NULL)
        {
           if(fgets(str,MAXLEN,infile)!=NULL)
           {
                fputs(str,outfile);
                fputs(str,stdout);
           }
           if(fclose(outfile)==EOF) perror("Output closing error");
        }
        else perror("Output opening error");
        if(fclose(infile)==EOF) perror("Input closing error");
    }
    else perror("Input opening error");

    return 0;
}
