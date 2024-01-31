#include <stdio.h>
#include <string.h>
#define MAXLEN 80

int main()
{

    char word[MAXLEN];
    int first,second,third,n,maxw;
    FILE *infile, *outfile;

    if((infile=fopen("data0.txt","r"))!=NULL)
    {
        if((n=fscanf(infile,"%s %d %d %d", word, &first, &second, &third))==4)
        {
            if(fclose(infile)==EOF) perror("Input closing error");
            maxw=strlen("word");
            n=strlen(word);
            if(n>maxw) maxw=n;

            if((outfile=fopen("results03.txt","w"))!=NULL)
            {
                fprintf(outfile,"Titles: |%*s |%6s |%6s |%6s |\n",maxw,"word","data","data","data");
                fprintf(outfile,"Fields: |%*s |%6d |%6d |%6d |\n",maxw,word,first,second,third);
                if(fclose(outfile)==EOF) perror("Output closing error");
            }
            else perror("Output opening error");
        }
        else printf("Incorrect input!\n");
    }
    else perror("Input opening error");
    return 0;
}
