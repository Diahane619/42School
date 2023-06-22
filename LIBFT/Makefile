# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francevi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 09:57:49 by francevi          #+#    #+#              #
#    Updated: 2023/06/22 15:51:53 by francevi         ###   ########.fr        #
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

SRC_DIR     := src
BUILD_DIR   := .build
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)
CC          := clang
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := -MMD -MP -I include
AR          := ar
ARFLAGS     := -r -c -s
RM          := rm -rf
MAKEFLAGS   := --no-print-directory
DIR_DUP     = mkdir -p $(@D)

.PHONY: clean fclean re
.SILENT:

# Rules ----------------------------------------------------------------------->

all: header $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info ${BOLD}Creating  -> ${YELLOW}$(NAME)${NO_COLOR})

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	$(info ${BOLD}Compiling -> ${YELLOW}$@${NO_COLOR})

-include $(DEPS)

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

# Style ----------------------------------------------------------------------->

RED 		:= ${shell tput setaf 1}
YELLOW		:= ${shell tput setaf 3}
BLUE		:= ${shell tput setaf 4}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}

header:
	${info }
	${info ${BOLD}${YELLOW}LIBFT${NO_COLOR}}

# ------------------------------------------------------------------------------