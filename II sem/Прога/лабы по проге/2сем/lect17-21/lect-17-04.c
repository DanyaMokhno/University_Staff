# include <stdio.h>
char switchbit(char c, int n)
{
	return c^(1 << n);
}

int main()
{
	char nc;
	char c='\x79'; /* char "y" */
	short n;

	printf("Enter position from right: ");
	scanf("%hd",&n);
	nc=switchbit(c,n);
	printf("%d New char: %c\n",1<<n,nc);

	return 0;
}
