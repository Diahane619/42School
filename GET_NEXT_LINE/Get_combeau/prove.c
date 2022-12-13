/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:06:51 by mcombeau          #+#    #+#             */
/*   Updated: 2021/12/19 03:32:49 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void function(void)
{
	static int	x;
// The default value of a static variable is 0
	printf("x = %d\n", x);
	x = x + 1;
}

int main(void)
{
	int i;
	i = 0;
	
	while (i <= 10)
	{
		function();
		i++;
	}
	return (0);
//It is only here, at the end of the program,that the static variable ceases to exist
}
