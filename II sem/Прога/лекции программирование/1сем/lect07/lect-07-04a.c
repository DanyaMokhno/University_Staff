#include <stdio.h>
#define MAXLEN 8

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
    int n1, n2;
    /* Let's try to enter more than MAXLEN symbols */
    printf("Enter first string: ");
    n1=new_gets(s1,MAXLEN);

    printf("Enter second string: ");
    n2=new_gets(s2,MAXLEN);

    puts("\nResults:");
    printf("String %s has %d symbols\n", s1, n1);
    printf("String %s has %d symbols\n", s2, n2);
    return 0;
}
