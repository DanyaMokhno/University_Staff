#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len = 1;
    int n;
    int temp;
    int counter = 0;
    int i = 1;
    int j;
    int arr[100];

    scanf("%i",&n);
    arr[0] = n;

    do
    {
        scanf("%i", &n);
        arr[i] = n;
        i++; len++;
    } while ((arr[0] < 0 && n < 0) || (arr[0] >= 0 && n >= 0));


    for(j=0, i=len/2-1; j<i; j++, i--)
    {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }


    if (len%2 == 0)
        i = len/2;
    else
        i  = len/2+1;

    for(; i<len; i++){
        for (j = i; j<len; j++)
        {
            if (abs(arr[i])%2 == 0)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }


    if (len%2 == 0)
        i = len;
    else
        i = len-1;

    for (; i > len/2; i--)
        if (abs(arr[i])%2 == 0) counter++;


    for (i = 0; i < len-counter; i++)
        printf("%i ", arr[i]);

    return 0;
}