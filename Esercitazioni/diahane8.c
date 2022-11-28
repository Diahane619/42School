#include <stdio.h>

int main()
{
   int	n;
   int	x;
   unsigned int somma;
   int i;
   
   somma = 0;
   i = 1;
   printf ("Valori totali: ", n);
   scanf ("%d", &n);
   while (i <= n)
   {
		printf ("inserire il %do valore: ", i);
		scanf ("%d", &x);
		somma += x;
		i++;
   }
      printf ("Somma: %d\n", somma);
	  printf ("Media: %d\n", somma/n);
	  return (0);
}