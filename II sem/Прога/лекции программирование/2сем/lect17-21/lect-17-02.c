# include <stdio.h>
int main()
{
	char a='\x2C';
	char b='\x71';
	char c;

	c=a^b;

	printf("a=%c b=%c c=%c\n",a,b,c);
	return 0;
}
