# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iragusa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 15:56:08 by iragusa           #+#    #+#              #
#    Updated: 2023/01/18 18:25:36 by iragusa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# \ = is used to Splitting Long Lines 3.1.1

# ;\ = indicates a multiline command and keeps the instance of the terminal for
# the next command

# % = the same as * 'wildcard'
# $@ = means what is before the : in the target
# $^ = means what is after the : in the target
# $< = the first prerequisite (usually a source file)
# -I.  = adds include directory of header files.
# -f = force the removal even if the files have been already deleted.

# -c = Compile or assemble the source files, but do not link.
# cp = copy.
# The linking stage simply is not done. The ultimate output is
# in the form of an object file for each source file.
# By default, the object file name for a source file is made by replacing
# the suffix .c, .i, .s, etc., with .o. Unrecognized input files,
# not requiring compilation or assembly, are ignored.

NAME = minitalk.a

CC = gcc

AR = ar -rcs

FLAG = -Werror -Wall -Wextra -g

SRC = client.c server.c

LIB = libft/libft.a -o

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(FLAG) client.c $(LIB) client
	$(CC) $(FLAG) server.c $(LIB) server

%.o: %.c
	$(CC) -c $(FLAG) -I. $< -o $@
	
bonus: all

clean: 
	$(MAKE) clean -C ./libft
	@rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all
 
.PHONY: all clean fclean re
.SILENT:
