#include <stdarg.h>
#include <stdio.h>

void print_times(char *str,...)
{
    va_list vl;
    char *p;
    int n,i;

    va_start(vl,str);
    for(p=str;p;p=va_arg(vl,char*))
    {
        n=va_arg(vl,int);
        for(i=0;i<n;i++) printf("%s ",p);
        printf("\n");
    }
    va_end(vl);
}

int main()
{
    print_times("one",1,"two",2,"six",6,NULL);
    return 0;
}

