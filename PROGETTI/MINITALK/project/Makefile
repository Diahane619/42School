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
# Definisce una variabile NAME con il valore "minitalk", che rappresenta il nome dell'eseguibile da generare.
 NAME_SERVER	:= server
# Definisce una variabile NAME_SERVER con il valore "server", che rappresenta il nome dell'eseguibile del server.
 NAME_CLIENT	:= client
# Definisce una variabile NAME_CLIENT con il valore "client", che rappresenta il nome dell'eseguibile del client.
 SRCS_SERVER := server.c
# Definisce una variabile SRCS_SERVER con il valore "server.c", che rappresenta il file sorgente del server.
 SRCS_CLIENT := client.c
# Definisce una variabile SRCS_CLIENT con il valore "client.c", che rappresenta il file sorgente del client.
 SRC_DIR     := src
# Definisce una variabile SRC_DIR con il valore "src", che rappresenta la directory in cui si trovano i file sorgente.
 SRCS_SERVER := $(SRCS_SERVER:%=$(SRC_DIR)/%)
# Aggiunge il percorso della directory SRC_DIR al file sorgente del server.
 SRCS_CLIENT := $(SRCS_CLIENT:%=$(SRC_DIR)/%)
# Aggiunge il percorso della directory SRC_DIR al file sorgente del client.
 BUILD_DIR   := .build
# Definisce una variabile BUILD_DIR con il valore ".build", che rappresenta la directory in cui verranno generati gli oggetti e le dipendenze.
 OBJS_SERVER := $(SRCS_SERVER:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
# Definisce una variabile OBJS_SERVER che rappresenta gli oggetti generati dai file sorgente del server.
 OBJS_CLIENT := $(SRCS_CLIENT:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
# Definisce una variabile OBJS_CLIENT che rappresenta gli oggetti generati dai file sorgente del client.
 DEPS_SERVER := $(OBJS_SERVER:.o=.d)
# Definisce una variabile DEPS_SERVER che rappresenta le dipendenze dei file oggetto del server.
 DEPS_CLIENT := $(OBJS_CLIENT:.o=.d)
# Definisce una variabile DEPS_CLIENT che rappresenta le dipendenze dei file oggetto del client.
 LIB         := ft
# Definisce una variabile LIB con il valore "ft", che rappresenta il nome della libreria da utilizzare.
 LIB_TARGET  := ./libft/libft.a 
# Definisce una variabile LIB_TARGET con il valore "./libft/libft.a", che rappresenta il percorso del file della libreria.
 INCS        := ./includes ./libft/include
# Definisce una variabile INCS con i valori "./includes" e "./libft/include", che rappresentano le directory in cui si trovano gli header file.
 CC          := clang
# Definisce una variabile CC con il valore "clang", che rappresenta il compilatore da utilizzare.
 CFLAGS      := -Wall -Wextra -Werror
# Definisce una variabile CFLAGS con i valori "-Wall -Wextra -Werror", che rappresentano le opzioni di compilazione.
 CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
# Definisce una variabile CPPFLAGS con i valori "-I./includes -I./libft/include -MMD -MP", che rappresentano le opzioni di pre-processore.
 LDFLAGS     := $(addprefix -L,$(dir $(LIB_TARGET)))
# Definisce una variabile LDFLAGS con il valore "-L./libft/", che rappresenta l'opzione di linking.
 LDLIBS      := $(addprefix -l,$(LIB))
# Definisce una variabile LDLIBS con il valore "-lft", che rappresenta il nome della libreria da linkare.
 RM          := rm -rf
# Definisce una variabile RM con il valore "rm -rf", che rappresenta il comando per rimuovere file e directory.
 MAKEFLAGS   := --no-print-directory
# Definisce una variabile MAKEFLAGS con il valore "--no-print-directory", che disabilita la stampa del nome delle directory durante l'esecuzione di make.
 DIR_DUP     = mkdir -p $(@D)
# Definisce una variabile DIR_DUP che crea una directory se non esiste già.
 .PHONY: all clean fclean re
# Definisce una lista di target che non rappresentano file.
 .SILENT:
# Disabilita la stampa dei comandi eseguiti da make.
 # Rules ----------------------------------------------------------------------->
 all: header $(NAME)
# Target "all": dipende dal target "header" e dal target con nome $(NAME).
 $(NAME): $(NAME_SERVER) $(NAME_CLIENT)
# Target $(NAME): dipende dai target $(NAME_SERVER) e $(NAME_CLIENT).
$(NAME_SERVER): $(OBJS_SERVER) $(LIB_TARGET)
	$(CC) $(LDFLAGS) $(OBJS_SERVER) $(LDLIBS) -o $(NAME_SERVER)
	${info ${BOLD}Creating  -> ${BLUE}$(NAME_SERVER)${NO_COLOR}}
# Target $(NAME_SERVER): dipende dagli oggetti $(OBJS_SERVER) e dalla libreria $(LIB_TARGET).
$(NAME_CLIENT): $(OBJS_CLIENT) $(LIB_TARGET)
	$(CC) $(LDFLAGS) $(OBJS_CLIENT) $(LDLIBS) -o $(NAME_CLIENT)
	${info ${BOLD}Creating  -> ${BLUE}$(NAME_CLIENT)${NO_COLOR}}
# Target $(NAME_CLIENT): dipende dagli oggetti $(OBJS_CLIENT) e dalla libreria $(LIB_TARGET).
 $(LIB_TARGET):
# Target $(LIB_TARGET): dipende dalla libreria $(LIB_TARGET).
	$(MAKE) -C $(@D)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
# Target $(BUILD_DIR)/%.o: dipende dal file sorgente $(SRC_DIR)/%.c.
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	${info ${BOLD}Compiling -> ${BLUE}$@${NO_COLOR}}
-include $(DEPS_SERVER)
-include $(DEPS_CLIENT)
clean:
# Target "clean": rimuove gli oggetti generati e le directory delle librerie.
	for f in $(dir $(LIB_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(BUILD_DIR)
	${info }
	${info ${BOLD}${YELLOW}Cleaning in progress...${NO_COLOR}	🧹 🧹 🧹}
fclean: clean
# Target "fclean": dipende dal target "clean" e rimuove anche gli eseguibili generati.
	for f in $(dir $(LIB_TARGET)); do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
re:
# Target "re": dipende dai target "fclean" e "all".
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