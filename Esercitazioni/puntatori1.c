#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100

int main()
{
   int a[MAXNUM], t;
   int i, j, n;

   printf("Quanti valori? ");
   scanf("%d", &n);

   for (i=0; i<n; i++)
   {
      printf("inserisci il %do valore: ", i+1);
      scanf("%d", &a[i]);
   }

   for (i=0, j=n-1; i<j; i++, j--)
   {
      t = a[i];
      a[i] = a[j];
      a[j] = t;
   }

   for (i=0; i<n; i++)
      printf("%d ", a[i]);
   printf("\n");

   return EXIT_SUCCESS;
}
