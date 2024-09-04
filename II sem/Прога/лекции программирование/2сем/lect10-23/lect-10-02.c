#include <stdio.h>

int main()
{
    struct sample
    {
        float x;
        char c0;
        int j;
        double q;
    } samp0;

    printf("%p\n", (void*)&samp0.x);
    printf("%p\n", (void*)&samp0.c0);
    printf("%p\n", (void*)&samp0.j);
    printf("%p\n", (void*)&samp0.q);
    printf("Total size of types: %ld\n", sizeof(float)+sizeof(char)+sizeof(int)+sizeof(double));
    printf("Size of structure: %ld\n", sizeof(samp0));
    return 0;
}

