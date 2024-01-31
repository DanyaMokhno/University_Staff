#include <stdio.h>
#define MAXLEN 80

void copy_string(char *src, char *dst)
{
    for(;*src;dst++,src++) *dst=*src;
    *dst='\0';
}

int new_gets(char *s, int lim)
{
    char c;
    int i;

    for(i=0;((c=getchar())!='\n')&&(i<lim-1);i++,s++) *s=c;
    *s='\0';
    return i;
}

int main()
{
    char s1[MAXLEN], s2[MAXLEN];
    int slen;

    printf("Enter your string: ");
    slen=new_gets(s1,MAXLEN);
    copy_string(s1,s2);

    printf("Copied string: \"%s\" has %d symbols\n", s2,slen);

    return 0;
}


