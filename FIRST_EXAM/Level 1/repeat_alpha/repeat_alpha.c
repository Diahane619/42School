#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        while (av[1][i])
        {
            if (av[1][i] >= 'a' && av[1][i] <= 'z')
            {
                int j = av[1][i] + 1 - 'a';
                while (j > 0)
                {
                    write(1, &av[1][i], 1);
                    --j;
                }
            }
            else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
            {
                int j = av[1][i] + 1 - 'A';
                while (j > 0)
                {
                    write(1, &av[1][i], 1);
                    --j;
                }
            }
            else
                write(1, &av[1][i], 1);
            ++i;
        }
    }
    write(1, "\n", 1);
    return (0);
}
