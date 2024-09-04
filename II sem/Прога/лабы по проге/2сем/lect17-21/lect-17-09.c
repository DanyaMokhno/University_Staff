#pragma pack(1)
# include <stdio.h>
/* Need to remove -pedantic mode! */
struct BP
{
unsigned a1:1;
unsigned a2:1;
unsigned a3:1;
unsigned a4:1;
unsigned a5:1;
unsigned a6:1;
unsigned a7:1;
unsigned a8:1;
};

struct BP1
{
unsigned short a1:1;
unsigned short a2:1;
unsigned short a3:1;
unsigned short a4:1;
unsigned short a5:1;
unsigned short a6:1;
unsigned short a7:1;
unsigned short a8:1;
};

struct BP2
{
unsigned char a1:1;
unsigned char a2:1;
unsigned char a3:1;
unsigned char a4:1;
unsigned char a5:1;
unsigned char a6:1;
unsigned char a7:1;
unsigned char a8:1;
};


int main()
{
    struct BP x={0,1,1,1,0,0,1,1};
    struct BP1 y={0,1,1,1,0,0,1,1};
    struct BP2 z={0,1,1,1,0,0,1,1};
/*    scanf("%d",&x.a3); */
    printf("%d%d%d%d%d%d%d%d\n", x.a1,x.a2,x.a3,x.a4,x.a5,x.a6,x.a7,x.a8);
    printf("%d%d%d%d%d%d%d%d\n", y.a1,y.a2,y.a3,y.a4,y.a5,y.a6,y.a7,y.a8);
    printf("%d%d%d%d%d%d%d%d\n", z.a1,z.a2,z.a3,z.a4,z.a5,z.a6,z.a7,z.a8);

    printf("%ld\n", sizeof(struct BP));
    printf("%ld\n", sizeof(y));
    printf("%ld\n", sizeof(z));

    return 0;
}
