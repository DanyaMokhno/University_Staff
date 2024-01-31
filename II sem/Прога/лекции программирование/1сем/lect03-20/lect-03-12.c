#include <stdio.h>

int main()
{
    int a[]={1,2,3,4,5,6,7,8};
    int i,k,n,tmp;

    n=sizeof(a)/sizeof(int);
    printf("Enter desired number: ");
    scanf("%d", &k);
    if((k>=0)&&(k<=n-1))
    {
        puts("Swap with next element");
        if(k<n-1)
        {
            tmp=a[k];
            a[k]=a[k+1];
            a[k+1]=tmp;
        }
        else puts("Swap is impossible!");
        for(i=0;i<n;i++) printf("%3d",a[i]);

        puts("\nSwap with previous element");
        if(k>0)
        {
            tmp=a[k];
            a[k]=a[k-1];
            a[k-1]=tmp;
        }
        else puts("Swap is impossible!");
        for(i=0;i<n;i++) printf("%3d",a[i]);
    }
    else puts("Incorrect data!! Try again!");
    getchar();
    puts("\nPress ENTER when ready");
    getchar();
    return 0;
}
