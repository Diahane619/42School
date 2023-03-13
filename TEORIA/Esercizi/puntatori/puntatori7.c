#include <stdio.h>

#define MAXNUM 100

int	main()
{
	int n[MAXNUM];
	int	b;
	int	a;

	printf("Numeri richiesti: ");
	scanf("%d", &b);
	
	a = 0;
	while(a < b)
	{
		printf("Inseriscri %do valore: ", a + 1);
		scanf("%d", &n[a]);
		a++;
	}
	a = 0;
	while(a < b)
	{
		printf("%d\n", n[a]);
		a++;
	}
	return(0);
}
