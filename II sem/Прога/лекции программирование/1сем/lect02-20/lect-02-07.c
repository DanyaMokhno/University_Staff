/* (!! UTF-8 !!) Последовательно вводятся  и суммируются целые числа, пока не
считано число 9999.
Из суммы требуется исключить числа, кратные 5.
При вводе отрицательного числа вывести текущее значение суммы
и закончить работу.
При вводе числа 9999 вывести значение суммы и общее количество чисел. */

#include <stdio.h>

int main()
{
    int value, sum, n;
    int key;

    for(n=0,value=0,sum=0,key=1;(value!=9999)&&key;n=n+1)
    {
        printf("Please enter value: ");
        scanf("%d", &value);

        if(((value%5)!=0)&&(value!=9999)) sum=sum+value;
        if(value<0)
        {
                printf("Current sum: %d\n", sum);
                key=0;
        }
    }
    printf("Total sum: %d, total count: %d\n", sum, n);
    return 0;
}

