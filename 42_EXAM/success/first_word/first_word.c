#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;

<<<<<<< HEAD
	if(ac == 2)
	{
		while(av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		{
			while(av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
				write(1, &av[1][i++], 1);
		}
	}
	write(1, "\n", 1);
=======
    if(ac == 2)
    {
        while(av[1][i] == ' ' || av[1][i] == '\t')
            i++;
        while(av[1][i] != ' ' && av[1][i] != '\t' && av[1][i])
        {
            write(1, &av[1][i], 1);
            i++;
        }    
    }
    write(1, "\n", 1);
>>>>>>> 6c13fe5618ff81e6322af184600f0fed1503d01a
}