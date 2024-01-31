#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("MAX INT: %i\n",INT_MAX);
    printf("MAX DOUBLE: %G\n",DBL_MAX);
    printf("FLOAT MIN ERROR: %.20f\n",FLT_EPSILON);
    printf("DOUBLE MIN ERROR: %.30G\n", DBL_EPSILON);
    return 0;
}

