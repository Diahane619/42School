/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:31:48 by francevi          #+#    #+#             */
/*   Updated: 2022/12/11 18:31:48 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <limits.h>

void	ft_placeholder(va_list args, const char *format, int *res, int *i);
int		ft_printf(const char *format, ...);
void	ft_putchar(int c, int *res);
void	ft_puthex(unsigned long n, int *res);
void	ft_putnbr(int n, int *res);
void	ft_putstr(const char *str, int *res);
void	ft_putuphex(unsigned int n, int *res);
void	ft_putpointer(void *p, int *res);
void	ft_putunbr(unsigned int n, int *res);
size_t	ft_strlen(const char *s);

#endif
