/* Redirecting errors in log file */
#include <stdio.h>
#include <errno.h>

int main()
{
    FILE *df, *logfile;

    logfile=freopen("error.log","a",stderr);
    df=fopen("results00.txt","w");
    if(df!=NULL)
    {
        fputs("Sample file content\n",df);
        if(fclose(df)==EOF)
        {
            if(logfile!=NULL) perror("Closing error");
            else puts("Error close datafile! Log not recorded!");
        }
        else puts("Closing OK");
    }
    else
    {
        if(logfile!=NULL) perror("Opening error");
        else puts("Cannot open files!");
    }
    if(logfile!=NULL)
    {
        if(fclose(logfile)==EOF) puts("Error closing logfile!");
    }
    return 0;
}

