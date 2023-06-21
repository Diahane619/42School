#include <unistd.h>

void ft_putnbr(int n)
{
	char	str[10] = "0123456789";
	
	if(n >= 10)
		ft_putnbr(n / 10);
	write (1, &str[n % 10], 1);
}

int main(int ac, char **av)
{
	ft_putnbr(ac - 1);
	write(1, "\n", 1);
	return(0);
}