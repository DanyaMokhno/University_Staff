#include <stdio.h>

int cTest(char char0, char *charArray, int arrsize)
{
    int i,n,key;

    i=0;
    key=0;
    n=arrsize;
    for(i=0;i<n;i++)
    {
        if(char0==charArray[i]) key=1;
    }
    return key;
}

int main()
{
    char sepArr[]={',','.','!','?',';',':','-',' '};
    char c0;
    int test,n;

    printf("Enter your char: ");
    c0=getchar();
    n=sizeof(sepArr)/sizeof(char);
    if((test=cTest(c0, sepArr,n))==1) puts("Your char is separator");
    else puts("Your char is not separator");

    return 0;
}
