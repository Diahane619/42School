/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:07:48 by francevi          #+#    #+#             */
/*   Updated: 2023/05/31 11:32:44 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void inter(char *s1, char *s2)
{
	int ascii[128] = {0};
	int i = 0;

	while(s2[i])
	{
		ascii[(int)s2[i]] = 1;
		i++;
	}
	i = 0;
	while (s1[i])
	{
		if (ascii[(int)s1[i]] == 1)
		{
			write(1, &s1[i], 1);
			ascii[(int)s1[i]] = 2;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if(ac == 3)
	{
		inter(av[1], av[2]);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}