#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;
	int j;

	if(ac == 2)
	{
		j = 0;
		while(av[1][i])
			i++;
		i -= 1;
		while(av[1][i] == ' ' || av[1][i] == '\t')
			i--;
		while(av[1][i] != ' ' && av[1][i] != '\t')
			i--;
		i += 1;
		while(av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
			write(1, &av[1][i++], 1);
	}
	write(1, "\n", 1);
}