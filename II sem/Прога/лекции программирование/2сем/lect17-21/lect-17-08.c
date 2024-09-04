# include <stdio.h>

void codeOfChar(char c)
{
	int i;

	for(i=7;i>=0;i--) printf("%d",(c>>i)&(0x1));
}

int main()
{
	char ch;

	printf("Enter symbol: ");
	scanf("%c", &ch);
	printf("Code: ");
	codeOfChar(ch);
	puts("");
	return 0;
}

