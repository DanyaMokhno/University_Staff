#include <stdio.h>
#include <errno.h>

int main()
{
    FILE *infile, *outfile;
    int i;

    if((outfile=fopen("results02.bin","w"))!=NULL)
    {
        for(i=0;i<8;i++) putw(i*10,outfile);
        putw(0x6d617073,outfile);

        if(fclose(outfile)==EOF) perror("Output closing error");
    }
    else perror("Output opening error");

    if((infile=fopen("results02.bin","r"))!=NULL)
        {
            while((i=getw(infile))!=EOF) printf("Current byte: %d\n", i);
            if(fclose(infile)==EOF) perror("Input closing error");
        }
        else perror("Input opening error");

    return 0;
}
