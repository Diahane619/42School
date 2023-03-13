#include <stdio.h>

int	 main()
{
	int	a;

	scanf("%d", &a);
	if (a == 1 || a == 4)
	printf("ROSSA\n", a);
	if (a == 2 || a == 5)
	printf("VERDE\n", a);
	if (a == 3)
	printf("BLU\n", a);
}