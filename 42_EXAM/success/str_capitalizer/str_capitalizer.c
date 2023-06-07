/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:16:08 by francevi          #+#    #+#             */
/*   Updated: 2023/06/02 18:36:33 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	str_capitalizer(char *str)
{
	int i = 0;

	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		{
			write(1, &str[i], 1);
			i++;
		}

		if (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			write(1, &str[i], 1);
			i++;
		}

		while (str[i] && str[i] != ' ' && str[i] != '\t')
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		int i = 1;
		while (i < argc)
		{
			str_capitalizer(argv[i]);
			++i;
		}
	}

	return (0);
}