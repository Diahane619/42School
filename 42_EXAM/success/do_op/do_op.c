/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:22:45 by francevi          #+#    #+#             */
/*   Updated: 2023/06/04 09:29:43 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main (int ac, char **av)
{
	int n1;
	int n2;
	int res;

	if (ac == 4)
	{
		n1 = atoi(av[1]);
		n2 = atoi(av[3]);

		if(av[2][0] == '+')
			res = n1 + n2;
		if(av[2][0] == '-')
			res = n1 - n2;
		if(av[2][0] == '*')
			res = n1 * n2;
		if(av[2][0] == '/')
			res = n1 / n2;
		if(av[2][0] == '%')
			res = n1 % n2;
		printf("%d", res);
	}
	printf("\n");
}