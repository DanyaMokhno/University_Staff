# include <stdio.h>
int main()
{
	char c;
	char mask;
	char res;

	c='\x7A';
	mask='\x77';
	res = c & mask;

	printf("%c %c %c\n", c, mask, res);
	return 0;
}
