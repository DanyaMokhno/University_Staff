/* Creating dynamic vector by random numbers
* and printing it.
* Function malloc() is used    */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int i, n;
   float *m1=NULL;
   float **pF;

   printf("Number of elements to be entered: ");
   scanf("%d",&n);

   if((m1 = (float*)malloc(n*sizeof(float)))!=NULL)
   {
      srand(time(NULL));

      for(i=0;i<n;i=i+1) m1[i]=(float)n*rand()/(RAND_MAX+1.0);

      printf("Our array is: \n");

      for(i=0;i<n;i=i+1) printf("Index: %3d, address %p (or %ld), value %7.5f\n",i,(m1+i), (long)(m1+i),m1[i]);
      printf("\nArray address is %p (or %ld)\n", m1, (long)m1);
      pF=&m1;
      printf("\nPointer address is %p (or %ld)\n", pF, (long)pF);

      free(m1);
      m1=NULL;
      getchar();
      puts("Press ENTER when ready");
      getchar();
   }
   else puts("Error at memory allocation!! Try again.");
   return 0;
}
