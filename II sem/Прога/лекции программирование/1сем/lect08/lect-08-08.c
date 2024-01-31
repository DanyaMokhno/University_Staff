#include <stdio.h>
#include <errno.h>
#define MAXLEN 80

int main()
{
    char str[MAXLEN];
    FILE *df;
    int i;

    if((df=fopen("data0.txt","r"))!=NULL)
    {
        if(fgets(str,MAXLEN,df)!=NULL)
        {
            i=0;
            printf("Initial string: %s", str);
            printf("Char's codes: ");
            while(str[i])
            {
                printf("%d ",str[i]);
                i++;
            }
        }
        if(fclose(df)==EOF) perror("Input closing error");
    }
    else perror("Input opening error");

    printf("\nEnter another string: ");
    fgets(str,MAXLEN,stdin);
    printf("Read from console: %s\n", str);
    return 0;
}
