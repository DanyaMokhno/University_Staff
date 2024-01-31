#include <stdio.h>
#include <errno.h>

int main()
{
    FILE *infile, *outfile;
    int i;

    if((outfile=fopen("results02.bin","w"))!=NULL)
    {
        putw(0x6d617073,outfile);
        if(fclose(outfile)==EOF) perror("Output closing error");
    }
    else perror("Output opening error");

    if((infile=fopen("results02.bin","r"))!=NULL)
        {
            i=getw(infile);
            printf("Current word: %x\n", i);
            if(fclose(infile)==EOF) perror("Input closing error");
        }
        else perror("Input opening error");

    return 0;
}
