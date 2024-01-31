/* Creating dynamic vector by random numbers
* and printing it.
* Function calloc() is used    */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int i, n, maxval;
   float *m1;

   printf("Number of elements to be entered: ");
   scanf("%d",&n);
   printf("Enter MAX value for array: ");
   scanf("%d",&maxval);

   if((m1 = (float*)calloc(n,sizeof(float)))!=NULL)
   {
      srand(time(NULL));

      for(i=0;i<n;i=i+1) m1[i]=maxval*(float)(rand()/(RAND_MAX+1.0));

      puts("Our array is:");

      for(i=0;i<n;i=i+1) printf("%6.2f\n",m1[i]);

      free(m1);
      printf("\nArray address is %p (or %ld)\n", m1, (long)m1);
      m1=NULL;
   }
   else puts("Error at memory allocation!");
   getchar();
   puts("\nPress ENTER when ready...");
   getchar();

   return 0;
}
