#include <stdio.h>
#include <string.h>
#define MAXLEN 80

int main()
{
    char s1[MAXLEN], s2[MAXLEN];
    int n;
    char *s3;

    printf("Enter string: ");
    fgets(s2,MAXLEN,stdin);

    n=strlen(s2);
    s2[n-1]='\0';

    n=strlen(s2);
    s3=strncpy(s1,s2,n);
    printf("Target string is %s, length %d\n",s1,n);
    printf("Used memory is %ld bytes\n", sizeof(s1));

    return 0;
}

