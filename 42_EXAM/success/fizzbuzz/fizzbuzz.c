/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 10:55:11 by francevi          #+#    #+#             */
/*   Updated: 2023/06/04 11:37:38 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int n)
{
    if (n >= 10)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else
        ft_putchar(n + '0');
}

int main()
{
	int n = 1;

	while(n <= 100)
	{
		if(n % 3 == 0 && n % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if(n % 3 == 0)
			write(1, "fizz", 4);
		else if(n % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(n);
			n++;
		write(1, "\n", 1);
	}
}