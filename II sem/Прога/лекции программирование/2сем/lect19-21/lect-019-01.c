#include <stdarg.h>
#include <stdio.h>

long summa(int k,...)
{
    va_list vl;
    long total,s;

    total=0;
    va_start(vl,k);
    while((s=va_arg(vl,int))!=0) total = total+s;
    va_end(vl);
    return total;
}

int main()
{
    printf("summa(1,4,6,0)= %ld\n",summa(1,4,6,0));
    printf("summa(1,1,2,3,4,5,6,0)= %ld\n",summa(1,1,2,3,4,5,6,0));
    return 0;
}
