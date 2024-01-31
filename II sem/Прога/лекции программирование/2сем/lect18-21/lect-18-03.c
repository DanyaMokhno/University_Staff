# include <stdio.h>
/* Need to remove -pedantic mode! */

union charByte
{
    char ss;
    struct
    {
        unsigned char s0:1;
        unsigned char s1:1;
        unsigned char s2:1;
        unsigned char s3:1;
        unsigned char s4:1;
        unsigned char s5:1;
        unsigned char s6:1;
        unsigned char s7:1;
    } b;
};

typedef union charByte cb;

int main()
{
    cb myChar;

    printf("Enter letter: ");
    myChar.ss=getchar();

    printf("Code: %d\n",myChar.ss);
    printf("Binary: %d%d%d%d%d%d%d%d\n", myChar.b.s7, myChar.b.s6, myChar.b.s5, myChar.b.s4, myChar.b.s3, myChar.b.s2, myChar.b.s1, myChar.b.s0);

    return 0;
}
