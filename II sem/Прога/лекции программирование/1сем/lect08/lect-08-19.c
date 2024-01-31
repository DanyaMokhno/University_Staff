#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<errno.h>
#define MAXLEN 80

int main()
{
    int n;
    FILE *outfile;
    char *s2=NULL;

    s2=(char*)malloc(MAXLEN*sizeof(char));
    if(s2!=NULL)
    {
        printf("Enter some string: ");
        fgets(s2,MAXLEN,stdin);

        if((outfile=fopen("out00.bin","w"))!=NULL)
        {
            n=fwrite(s2,strlen(s2)/2,2,outfile);
            printf("Recorded blocks: %d\n",n);
            if(fclose(outfile)==EOF) perror("Closing error!");
        }
        else perror("Opening error!");
    }
    else puts("Memory allocation error. STOPPED.");
    return 0;

}
