/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:02:58 by francevi          #+#    #+#             */
/*   Updated: 2022/10/07 15:16:36 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LIBFT_H
# define  LIBFT_H

// Libraries ------------------------------------------------------------------>

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>

// Constants ------------------------------------------------------------------>

# define RESET		"\x1b[0m"
# define WHITE		"\033[1m"
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define WHITE_B	"\033[1;1m"
# define RED_B		"\033[1;31m"
# define GREEN_B	"\x1b[1;32m"
# define YELLOW_B	"\x1b[1;33m"
# define BLUE_B		"\x1b[1;34m"
# define MAGENTA_B	"\x1b[1;35m"
# define CYAN_B		"\033[1;36m"

# define MAX_INT	2147483647
# define MIN_INT	-2147483648

// Libft Base ----------------------------------------------------------------->

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(void *dest, const void *src, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// Custom Functions ----------------------------------------------------------->

void	*ft_free(void **ptr);
void	ft_exit(char *msg, char *color, int fd, int exit_code);
char	*ft_char_append(char *s, char c, bool need_to_free);
char	*ft_strappend(char *s1, char *s2, bool free_s1, bool free_s2);
char	*ft_strrev(char *str);
ssize_t	ft_stridx(char *s, int c);
char	*ft_split_substr(char **s, int start, size_t len, char split);
size_t	ft_hexlen(size_t n);
char	*ft_utoa(unsigned int nb);
char	*ft_utoa_hex(unsigned int n, bool is_upper);
char	*ft_ultoa_hex(uintptr_t n);

// Get-Next-Line -------------------------------------------------------------->

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 420
# endif

char	*get_next_line(int fd);
char	*ft_riga(char *left_str);
char	*ft_resto(char *left_str);
void	ft_read_line(int fd, char **keep, char **tmp);
void	ft_free_strs(char **str, char **str2, char **str3);
int		contains_newline(const char *s);

// Printf --------------------------------------------------------------------->

void	ft_placeholder(va_list args, const char *format, int *res, int *i);
int		ft_printf(const char *format, ...);
void	ft_putchar(int c, int *res);
void	ft_puthex(unsigned long n, int *res);
void	ft_putnbr(int n, int *res);
void	ft_putstr(const char *str, int *res);
void	ft_putuphex(unsigned int n, int *res);
void	ft_putpointer(void *p, int *res);
void	ft_putunbr(unsigned int n, int *res);

#endif
