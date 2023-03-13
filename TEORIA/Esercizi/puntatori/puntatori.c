#include <stdio.h>
#include <stdlib.h>

int count(char *s)
{
	int	i = 0;

	while (s[i])
		i++;
	return(i);
}


int main()
{
	char	*s;

	s = malloc(sizeof(s));
	printf("Stringa: ");
	scanf("%s", s);
	printf("Numero caratteri: %d\n", count(s));

}