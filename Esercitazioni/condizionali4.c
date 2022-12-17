#include <stdio.h>

int	 main()
{
	int	a;

	scanf("%d", &a);
	if (a >= 0 && a <= 30)
	{
		if (a > 0 && a < 18)
		printf("Insufficiente\n");
		if (a == 18)
		printf("Appena sufficiente\n");
		if (a == 19 || a == 20)
		printf("Basso\n");
		if (a >= 21 && a <= 23)
		printf("Medio\n");
		if (a >= 24 && a <= 26)
		printf("Buono\n");
		if (a >= 27 && a <= 29)
		printf("Alto\n");
		if (a == 30)
		printf("Massimo\n");
	}
	else
	printf("Impossibile\n");
}