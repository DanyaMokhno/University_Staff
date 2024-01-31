#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "mydefs.h"

int main()
{
    char fname[MAXLEN];
    int slen;
    int variant;
    FILE *df;

    printf("Enter your filename: ");
    fgets(fname,MAXLEN,stdin);
    slen=strlen(fname);
    fname[slen-1]='\0';

    if((variant=menu())==0) df=fopen(fname,"w");
    else df=fopen(fname,"a");

    if(df!=NULL)
    {
        fputs("Writing in the file\n",df); // writing to file
        fputs("Writing in the file\n",stdout); // writing to screen

        if(fclose(df)!=EOF) printf("Closing OK\n");
        else printf("Closing error code: %d\n", errno);
    }
    else perror("Data error");
    return 0;
}

/* Function implementation */
int menu() // Simple menu
{
    int v;

    do
    {
        CLS;
        puts("Options:");
        puts("0 - Create new file");
        puts("1 - Append to existing file");
        printf("Enter options: ");
        scanf("%d",&v);
    } while((v!=0)&&(v!=1));
    return v;
}
