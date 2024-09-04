#include <stdarg.h>
#include <stdio.h>

void miniprint(char *format,...)
{
    va_list ap;
    char *p;
    int ii;
    double dd;

    va_start(ap,format);
    for(p=format;*p;p++)
    {
        if((*p)=='%')
        {
            switch(*(++p))
            {
            case 'd':
                ii=va_arg(ap,int);
                printf("%d",ii);
                break;
            case 'f':
                dd=va_arg(ap,double);
                printf("%f",dd);
                break;
            default:
                printf("%c",*p);
            }
        }
        else printf("%c",*p);
    }
    va_end(ap);
}

int main()
{
    int k;
    float e;

    k=123;
    e=2.71828;
    miniprint("%d\t %f\t %d\t %f\n",k,e,k,e);
    return 0;
}

