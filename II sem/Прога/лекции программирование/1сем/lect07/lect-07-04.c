#include <stdio.h>
#define MAXLEN 8

void new_gets(char s[], int lim)
{
    char c;
    int i;

    i=0;
    while(((c=getchar())!='\n')&&(i<lim-1))
    {
        s[i]=c;
        i++;
    }
    s[i]='\0';
}

int main()
{
    char s1[MAXLEN], s2[MAXLEN];
    int n1, n2;
    /* Let's try to enter more than MAXLEN symbols */
    printf("Enter first string: ");
    new_gets(s1,MAXLEN);

    printf("Enter second string: ");
    new_gets(s2,MAXLEN);

    n1=printf("%s", s1);
    n2=printf("%s", s2);
    puts("\nResults:");
    printf("String %s has %d symbols\n", s1, n1);
    printf("String %s has %d symbols\n", s2, n2);
    return 0;
}

