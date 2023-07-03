# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francevi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 10:08:18 by francevi          #+#    #+#              #
#    Updated: 2023/07/03 07:46:10 by francevi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minitalk
NAME_SERVER	:= server
NAME_CLIENT	:= client
SRCS_SERVER := server.c
SRCS_CLIENT := client.c
SRC_DIR     := src
SRCS_SERVER := $(SRCS_SERVER:%=$(SRC_DIR)/%)
SRCS_CLIENT := $(SRCS_CLIENT:%=$(SRC_DIR)/%)
BUILD_DIR   := .build
OBJS_SERVER := $(SRCS_SERVER:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_CLIENT := $(SRCS_CLIENT:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS_SERVER := $(OBJS_SERVER:.o=.d)
DEPS_CLIENT := $(OBJS_CLIENT:.o=.d)
LIB         := ft
LIB_TARGET  := ./libft/libft.a 
INCS        := ./includes ./libft/include
CC          := clang
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS     := $(addprefix -L,$(dir $(LIB_TARGET)))
LDLIBS      := $(addprefix -l,$(LIB))
RM          := rm -rf
MAKEFLAGS   := --no-print-directory
DIR_DUP     = mkdir -p $(@D)

.PHONY: all clean fclean re
.SILENT:

# Regole ----------------------------------------------------------------------->

all: header $(NAME)

$(NAME): $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER) $(LIB_TARGET)
	$(CC) $(LDFLAGS) $(OBJS_SERVER) $(LDLIBS) -o $(NAME_SERVER)
	${info ${BOLD}Creazione -> $(NAME_SERVER)}

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIB_TARGET)
	$(CC) $(LDFLAGS) $(OBJS_CLIENT) $(LDLIBS) -o $(NAME_CLIENT)
	${info ${BOLD}Creazione -> $(NAME_CLIENT)}

$(LIB_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	${info ${BOLD}Compilazione -> $@}

-include $(DEPS_SERVER)
-include $(DEPS_CLIENT)

clean:
	for f in $(dir $(LIB_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(BUILD_DIR)
	${info }
	${info ${BOLD}Pulisci...${NO_COLOR}	🧹 🧹 🧹}

fclean: clean
	for f in $(dir $(LIB_TARGET)); do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	
re:
	$(MAKE) fclean
	$(MAKE) all

header:
	${info ${NO_COLOR}}	
	${info ███    ███ ██ ███    ██ ██ ████████  █████  ██      ██   ██ }
	${info ████  ████ ██ ████   ██ ██    ██    ██   ██ ██      ██  ██  }
	${info ██ ████ ██ ██ ██ ██  ██ ██    ██    ███████ ██      █████   }
	${info ██  ██  ██ ██ ██  ██ ██ ██    ██    ██   ██ ██      ██  ██  }
	${info ██      ██ ██ ██   ████ ██    ██    ██   ██ ███████ ██   ██ }
	${info ${NO_COLOR}}
	
# ------------------------------------------------------------------------------
