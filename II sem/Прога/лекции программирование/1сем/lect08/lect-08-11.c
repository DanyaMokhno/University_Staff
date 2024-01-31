#include <stdio.h>
#define MAXLEN 80

int main()
{
    char word[MAXLEN];
    int first,second,third,n;
    FILE *df;

    if((df=fopen("data0.txt","r"))!=NULL)
    {
        if((n=fscanf(df,"%s %d %d %d", word, &first, &second, &third))==4)
        {
            printf("Titles: |%20s |%6s |%6s |%6s |\n","word","data","data","data");
            printf("Fields: |%20s |%6d |%6d |%6d |\n",word,first,second,third);
        }
        else printf("Incorrect input!\n");
        if(fclose(df)==EOF) perror("Input closing error");
    }
    else perror("Input opening error");
    return 0;
}
