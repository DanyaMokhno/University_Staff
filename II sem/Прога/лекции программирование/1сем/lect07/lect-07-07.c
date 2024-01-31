#include <stdio.h>
#include <string.h>
#define MAXLEN 80

int main()
{
    char s1[MAXLEN], s2[MAXLEN];
    int n1, n2, key;

    printf("Enter first string: ");
    fgets(s1,MAXLEN,stdin);

    printf("Enter second string: ");
    fgets(s2,MAXLEN,stdin);

    n1=strlen(s1);
    n2=strlen(s2);
    s1[n1-1]='\0';
    s2[n2-1]='\0';

    key=strcmp(s1,s2);
    printf("Result of comparison: %d\n", key);

    return 0;
}
