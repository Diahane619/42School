#include <stdio.h>

int	 main()
{
	int	a;
	int	b;
	int	c;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	if (a > b && a > c)
	printf("Maggiore: %d\n", a);
	if (b > a && b > c)
	printf("Maggiore: %d\n", b);
	if (c > a && c > b)
	printf("Maggiore: %d\n", c);
}