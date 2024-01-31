#include <stdio.h>
#include <errno.h>

int main()
{
    FILE *df;

    if((df=freopen("results00.txt","w",stdout))!=NULL)
    {
        printf("Sample file content\n");
        if(fclose(df)==EOF) perror("Closing error");
    }
    else perror("Opening error");

    return 0;
}
