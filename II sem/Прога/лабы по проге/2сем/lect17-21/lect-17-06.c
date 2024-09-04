# include <stdio.h>

int main()
{
	unsigned short x=0x800;
	unsigned short y;

	y=~x;
	printf("%x %x\n",x,y);

	return 0;
}
