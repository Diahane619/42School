/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:59:42 by aperez-b          #+#    #+#             */
/*   Updated: 2022/11/21 14:57:12 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

/* Recupera la riga successiva dal descrittore di file specificato */
char	*get_next_line(int fd);

/* Ritorna la lunghezza della stringa */
size_t	gnl_strlen(const char *s);

/* Recupera l'indice della prima apparizione di i in s, o -1 */
int		gnl_strchr_i(const char *s, int c);

/* Copia i caratteri da src a dst assicurando la terminazione nulla */
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);

/* Alloca memoria sufficiente per eseguire una copia di s dall'inizio, copiando len byte */
char	*gnl_substr(char const *s, unsigned int start, size_t len);

/* Concatena due stringhe, garantendo la terminazione null */
size_t	gnl_strlcat(char *dst, const char *src, size_t size);

/* Rimuove la riga dalla variabile statica buf */
char	*gnl_shrink_buffer(char *buf, char *line);

/* Esegue una nuova lettura e la aggiunge alla variabile statica buf */
char	*gnl_expand_buffer(char *buf, int fd);

/* Esegue una nuova lettura e restituisce la stringa di lettura */
char	*gnl_newread(int fd);

#endif
