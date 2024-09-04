#include <stdio.h>
#include <math.h>

int main()
{
    struct
    {
        float x;
        float y;
    } t0, t1;
    float r;

    printf("Point 1 (X Y): ");
    scanf("%f %f", &t0.x, &t0.y);
    printf("Point 2 (X Y): ");
    scanf("%f %f", &t1.x, &t1.y);
    r=sqrt(pow((t0.x-t1.x),2)+pow((t0.y-t1.y),2));
    printf("Distance between points: %.3f\n",r);
    return 0;
}
