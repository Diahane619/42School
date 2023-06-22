# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francevi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 09:57:49 by francevi          #+#    #+#              #
#    Updated: 2023/06/22 13:38:01 by francevi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a
SRCS	:= \
	get_next_line/get_next_line.c get_next_line_utils.c
	\
	printf/ft_printf.c ft_putstr.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putunmbr.c ft_putuphex.c ft_putpointer.c \
	\
	mem/ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_free.c
	\
	is/ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	\
	str/ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \ 
	str/ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_atoi.c ft_strdup.c ft_substr.c ft_char_append.c \
	str/ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c ft_itoa.c \
	str/ft_strappend.c ft_strrev.c ft_stridx.c ft_split_substr.c ft_utoa.c
	\
	hex/ft_hexlen.c ft_utoa_hex.c ft_ultoa_hex.c
	\
	fd/ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_exit.c \

OBJS = $(SRCS:.c=.o)

GCC = gcc
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = -rcs
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME).so

re: fclean all

