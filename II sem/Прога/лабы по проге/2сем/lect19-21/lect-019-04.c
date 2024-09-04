/* Original on https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/vprintf.htm

CELEBV04

   This example prints out a variable number of strings to stdout, using &vprintf..

 */
#include <stdarg.h>
#include <stdio.h>

void vout(char *fmt, ...)
{
    va_list arg_ptr;

    va_start(arg_ptr, fmt);
    vprintf(fmt, arg_ptr);
    va_end(arg_ptr);
}

int main()
{
    char fmt1[]=" %s\t %d\n %s\t %d\n %s\t %d\n";

    vout(fmt1,"Mon",1,"Wed",3,"Fri",5);
    return 0;
}
