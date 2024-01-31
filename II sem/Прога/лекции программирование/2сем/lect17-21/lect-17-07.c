# include <stdio.h>

int numberOfOnes(char c)
{
	int i, count;
	char rest;

	count=0;
	for(i=0;i<8;i++)
	{
        rest=(c>>i)&(0x1);
		if(rest==1) ++count;
	}
	return count;
}

int main()
{
	char ch;
	int n;

	printf("Enter symbol: ");
	scanf("%c", &ch);
	n=numberOfOnes(ch);
	printf("Ones in code: %d\n",n);

	return 0;
}
