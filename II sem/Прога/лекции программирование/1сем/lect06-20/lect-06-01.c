/* Artificial example of using pointer
* to function                          */
#include <stdio.h>
#include <stdlib.h>

/* Functions to calculate */
long fact(unsigned n);

long qube(unsigned n);

long fibon(unsigned n);

/* Function for using pointer to calc functions */
void convol(unsigned n, long (*funcName)(unsigned), long *res);

int main()
{
    unsigned value;
    long result;

    printf("Please enter value (less than 20!): ");
    scanf("%u", &value);
/* We need only set 2nd argument */
    convol(value,fibon,&result);

    printf("Result: %ld\n", result);

    return 0;
}

long fact(unsigned n)
{
    long res0;
    int i;

    res0=1;
    for(i=2;i<=n;i++) res0=i*res0;
    return res0;
}

long qube(unsigned n)
{
    return n*n*n;
}

long fibon(unsigned n)
{
	long res1,res0;
	int i;
	res1=1;
	res0=0;
	for (i=0;i<n;i++)
	{
		res1+=res0;
		res0=res1-res0;
	}
	return res0;
}

void convol(unsigned n, long (*funcName)(unsigned), long *res)
{

    *res=funcName(n);
}
