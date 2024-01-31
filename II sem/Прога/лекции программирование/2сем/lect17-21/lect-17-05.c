# include <stdio.h>

int main()
{
	short x=0x8000;
	int y=8;
	unsigned int z=0x8000;

	printf("%x %x %x\n",x,x>>1,x>>2);
	printf("%x %x %x\n",y,y>>1,y>>2);
	printf("%x %x %x\n",z,z>>1,z>>2);

	return 0;
}
