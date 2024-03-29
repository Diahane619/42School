# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 14:51:06 by kichkiro          #+#    #+#              #
#    Updated: 2023/03/30 01:58:16 by kichkiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config ---------------------------------------------------------------------->

NAME 		:= philo
INCS 		:= ./include
SRC_DIR 	:= src
SRCS 		:= main.c thread_handler.c state_handler.c utils.c
SRCS 		:= $(SRCS:%=$(SRC_DIR)/%)
BUILD_DIR 	:= .build
OBJS 		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS 		:= $(OBJS:.o=.d)
CC 			:= gcc
CFLAGS 		:= -g -Wall -Wextra -Werror -pthread
CPPFLAGS 	:= $(addprefix -I,$(INCS)) -MMD -MP
RM 			:= rm -rf
MAKEFLAGS 	:= --no-print-directory
DIR_DUP 	= mkdir -p $(@D)

.PHONY: clean fclean re
.SILENT:

# Rules ----------------------------------------------------------------------->

all: header $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	${info }
	${info ${BOLD}Creating -> ${YELLOW}$(NAME)${NO_COLOR}}

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	${info ${BOLD}Compiling -> ${YELLOW}$@${NO_COLOR}}

-include $(DEPS)

clean:
	$(RM) $(BUILD_DIR)
	${info }
	${info ${BOLD}${YELLOW}Cleaning in progress...${NO_COLOR} 🧹 🧹 🧹}

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
	${info ${YELLOW}}	
	${info █████████████████████████████████████████████████████████████████ }
	${info █▄─▄▄─█─█─█▄─▄█▄─▄███─▄▄─█─▄▄▄▄█─▄▄─█▄─▄▄─█─█─█▄─▄▄─█▄─▄▄▀█─▄▄▄▄█ }
	${info ██─▄▄▄█─▄─██─███─██▀█─██─█▄▄▄▄─█─██─██─▄▄▄█─▄─██─▄█▀██─▄─▄█▄▄▄▄─█ }
	${info ▀▄▄▄▀▀▀▄▀▄▀▄▄▄▀▄▄▄▄▄▀▄▄▄▄▀▄▄▄▄▄▀▄▄▄▄▀▄▄▄▀▀▀▄▀▄▀▄▄▄▄▄▀▄▄▀▄▄▀▄▄▄▄▄▀ }
	${info ${NO_COLOR}}

# ------------------------------------------------------------------------------
