#include <stdio.h>
#include <errno.h>
#define MAXLEN 80

int main()
{
    char str[MAXLEN];
    FILE *infile, *outfile;
    int fd_in, fd_out;

    if((infile=fopen("data0.txt","r"))!=NULL)
    {
        fd_in=fileno(infile);
        if(fgets(str,MAXLEN,infile)!=NULL)
        {
            if((outfile=fopen("results00.txt","w"))!=NULL)
            {
                fd_out=fileno(outfile);
                printf("%s\n", str);
                printf("%d\n",fd_out);
                if(fclose(outfile)==EOF) perror("Output closing error");
            }
            else perror("Output opening error");
        }
        if(fclose(infile)==EOF) perror("Input closing error");
        printf("%d\n",fd_in);
    }
    else perror("Input opening error");

    return 0;
}
