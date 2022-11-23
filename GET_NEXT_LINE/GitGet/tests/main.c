/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:14:39 by aperez-b          #+#    #+#             */
/*   Updated: 2022/11/21 16:17:03 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("tests/J. K. Rowling - Harry Potter 1 - Sorcerer's Stone.txt", \
					O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%d && %s\n", fd, line);
		if (!line)
			return (0);
		free(line);
	}
}
