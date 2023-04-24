/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:08:48 by francevi          #+#    #+#             */
/*   Updated: 2022/11/21 17:52:55 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	contains_newline(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0)gvgr
}

char	*ft_riga(char *left_str)
{
	int		i;
	char	*riga;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	riga = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		riga[i] = left_str[i];
		i++;
	}
	if (left_str[i] && left_str[i] == '\n')
	{
		riga[i] = '\n';
		i++;
	}
	return (riga);
}

char	*ft_resto(char *left_str)
{
	int		i;
	int		j;
	char	*riga;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	riga = ft_calloc((ft_strlen(left_str) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (left_str[i])
		riga[j++] = left_str[i++];
	free(left_str);
	return (riga);
}

void	ft_read_line(int fd, char **keep, char **tmp)
{
	char	*buf;
	int		r;

	buf = malloc(sizeof * buf * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	r = 1;
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			ft_free_strs(&buf, keep, tmp);
			return ;
		}
		buf[r] = '\0';
		*tmp = ft_strdup(*keep);
		ft_free_strs(keep, 0, 0);
		*keep = ft_strjoin(*tmp, buf);
		ft_free_strs(tmp, 0, 0);
		if (contains_newline(*keep))
			break ;
	}
	ft_free_strs(&buf, 0, 0);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*tmp;
	static char	*left_str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	tmp = NULL;
	ft_read_line(fd, &left_str[fd], &tmp);
	if (!left_str[fd])
		return (NULL);
	line = ft_riga(left_str[fd]);
	left_str[fd] = ft_resto(left_str[fd]);
	return (line);
}
