#include <stdio.h>
#define n 10

int main()
{
   int	x;
   unsigned int somma;
   int i;
   
   somma = 0;
   i = 1;
   while (i <= n)
   {
		printf ("inserire il %do valore: ", i);
		scanf ("%d", &x);
		somma += x;
		i++;
   }
      printf ("Media: %d\n", somma/n);
	  return (0);
}