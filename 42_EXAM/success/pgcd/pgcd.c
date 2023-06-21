#include <stdio.h>
#include <stdlib.h>

void main(int ac, char **av)
{
    int i;
    int j;
    
    if (ac == 3)
    {   
        i = atoi(av[1]);
        j = atoi(av[2]);
        int n = i;

        while(n > 0)
        {
                if(i % n == 0 && j % n == 0)
                {
                    printf("%d\n", n);
                    return;
                }
                --n;
        }
    }
    printf("\n");
}