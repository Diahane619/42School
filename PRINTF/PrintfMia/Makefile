NAME = libprintf.a
SRCS =  \

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

.PHONY: all, clean, fclean, re