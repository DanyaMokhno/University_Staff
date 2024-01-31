/* Creating dynamic vector and
* printing it in reverse order
* Function malloc() is used    */
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i, n;
   int *a;

   printf("Number of elements to be entered: ");
   scanf("%d",&n);

   if((a=(int*)malloc(n*sizeof(int)))!=NULL)
   {
      puts("\n --------- ");
      printf("Array address is %p or %ld\n",a,(long)a);
      puts("Initial array:");
      for(i=0;i<n;i=i+1) printf("%d ",a[i]);

      printf("\nEnter %d values by lines:\n",n);

      for(i=0;i<n;i=i+1) scanf("%d",&a[i]);

      printf("The values entered are (reverse order): \n");

      for(i=n-1; i >=0; i=i-1) printf("%d ",a[i]);

      free(a);
      puts("\n --------- ");
      printf("After free() array address is %p or %ld\n",a,(long)a);
/* VERY IMPORTANT TIP!!! */
      a=NULL;

      puts("\n --------- ");
      printf("After NULL array address is %p or %ld\n",a,(long)a);
   }
   else puts("Error at memory allocation!");
   getchar();
   puts("Press ENTER when ready...");
   getchar();
   return 0;
}
