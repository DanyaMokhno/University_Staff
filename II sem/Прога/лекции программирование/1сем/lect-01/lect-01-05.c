#include <stdio.h>
#include <locale.h>

int main()
{
   int a, b, c; /* declarations of variables */

    printf ("Enter two integers by space \n"); /* help to input data */
    scanf ("%d %d", &a, &b); /* reading data */
    c = a + b; /* calculations (assignment operator) */

    printf ("Result: %d + %d = %d\n", a, b, c); /* output data */
    puts("Program finished!");

    return 0;
}
