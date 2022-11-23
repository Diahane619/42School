/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:08:56 by francevi          #+#    #+#             */
/*   Updated: 2022/11/23 13:00:07 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	if (len > s_len)
		len = s_len;
	if (start >= s_len)
	{
		substr = (char *)malloc(1);
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	substr = (char *)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	while (i++ < start)
		s++;
	ft_strlcpy(substr, s, len + 1);
	return (substr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (ft_strlen(src));
	while (src[i] && (i < n - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s && *s != uc)
		s++;
	if (*s == uc)
		return ((char *)s);
	else
		return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*ptr;
	unsigned int	i;

	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	ptr = dst + ft_strlen(dst);
	i = ft_strlen(dst);
	while (i < size - 1 && *src != '\0' && size >= 2)
	{
		*ptr = *src;
		ptr++;
		src++;
		i++;
	}
	if (size != 0)
		*ptr = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	len;

	len = ft_strlen(s) + 1;
	new = (char *)malloc(sizeof(*new) * len);
	if (!new)
		return (NULL);
	else
		return ((char *)ft_memcpy(new, s, len));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}