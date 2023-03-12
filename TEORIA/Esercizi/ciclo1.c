ds#include <stdio.h>

int main()
{
   int	v;
   int somma;
   
   somma = 0;
   scanf("%d", &v);
   while (v != 0)
   {
		somma += v;
		scanf("%d", &v);
   }
      printf("Somma: %d\n", somma);
}