NAME = libftgetnextline.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = 
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) ft_get_next_line.h
		@ar rc $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)
fclean: clean
	@$(RM) $(NAME)