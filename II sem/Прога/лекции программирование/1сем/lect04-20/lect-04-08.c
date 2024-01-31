/* Creating dynamic vector by random numbers
* and adjust odd/even relation by realloc(). */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int i, k, n, maxval;
   int n_even, n_odd;
   int even_value,odd_value, value;
   int *m1;

   printf("Number of elements to be entered: ");
   scanf("%d",&n);
   printf("Enter MAX value for array: ");
   scanf("%d",&maxval);

   if((m1 = (int*)calloc(n,sizeof(int)))!=NULL)
   {
      srand(time(NULL));
      even_value=2;
      odd_value=3;
      n_even=0;
      n_odd=0;

      for(i=0;i<n;i=i+1) m1[i]=(int)(maxval*(float)(rand()/(RAND_MAX+1.0)));

      puts("Initial array is:");

      for(i=0;i<n;i=i+1)
      {
          printf("%3d ",m1[i]);
          if(m1[i]%2==0) n_even=n_even+1;
          else n_odd=n_odd+1;
      }
      printf("\nInitial array address is %p (or %ld)\n", m1, (long)m1);
      if(n_even>n_odd) value=odd_value;
      else value=even_value;
      k=abs(n_even-n_odd);

      if((m1=realloc(m1,(n+k)*sizeof(int)))!=NULL)
      {
          printf("\nFinal array address is %p (or %ld)\n", m1, (long)m1);
          for(i=n;i<(n+k);i=i+1) m1[i]=value;
          puts("Final array is:");
          for(i=0;i<(n+k);i=i+1) printf("%3d ",m1[i]);
      }
      else puts("Error at REALLOC!");
      free(m1);
      m1=NULL;
   }
   else puts("Error at memory allocation!");

   getchar();
   puts("\nPress ENTER when ready...");
   getchar();
   return 0;
}

