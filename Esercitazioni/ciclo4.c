#include <stdio.h>

int main()
{
   int	x;
   unsigned int somma;
   int i;
   int n = 2000;
   
   somma = 0;
   i = 1;
   while (i <= n)
   {
		printf ("inserire il %do valore: ", i);
		scanf ("%d", &x);
		if (x < 30 && x > 18)
			somma += x;
		else
			break;
		i++;
   }
	  printf ("i: %d\n", i);
	  printf ("Somma: %d\n", somma);
	  printf ("Media: %f\n", (double)somma/(i - 1));
	  return (0);
}