#include <unistd.h>
<<<<<<< HEAD

int putnumbr(int n)
{
    char number[10] = "0123456789";

    if(n > 9)
        putnumbr(n / 10);
    write(1, &number[n % 10], 1);
=======
void ft_write_number(int n)
{
	char s[10] = "0123456789";

	if(n > 9)
		ft_write_number(n / 10);
	write(1, &s[n % 10], 1);
>>>>>>> rht
}

int main()
{
    int n = 1;

<<<<<<< HEAD
    while(n <= 100)
    {
        if(n % 15 == 0)
            write(1, "fizzbuzz", 8);
        else if(n % 3 == 0)
            write(1, "fizz", 4);
        else if(n % 5 == 0)
            write(1, "buzz", 4);
        else
            putnumbr(n);
            write(1, "\n", 1);
        n++;
    }
=======
	while(n <= 100)
	{
		if(n % 15 == 0)
			write(1, "fizzbuzz\n", 9);
		else if(n % 3 == 0)
			write(1, "fizz\n", 5);
		else if(n % 5 == 0)
			write(1, "buzz\n", 5);
		else
		{
			ft_write_number(n);
			write(1, "\n", 1);
		}
		n++;
	}
>>>>>>> rht
}