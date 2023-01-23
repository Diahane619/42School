#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100

int main()
{
	int a[MAXNUM], t, *p, *q;
	int n;

	printf("Quanti valori? ");
	scanf("%d", &n);
   
	while (n < 0 || n > MAXNUM);
		q = a + n;  /* punta all'elemento successivo all'ultimo */
	p = a;
	while (p < q)
	{
  		printf("inserisci il %do valore: ", p - a + 1);
  		scanf("%d", p);
		p++;
	}
	p = a;
	q = a + n - 1; /* a + n - 1 punta all'ultimo */  
	while (p < q)
	{
		t = *p;
		*p = *q;
		*q = t;
		p++;
		q--;
	}
	q = a + n;
	p = a;
	while (p < q)
	{	
		printf("%d ", *p);
		printf("\n");
		p++;
	}
	return EXIT_SUCCESS;
}
