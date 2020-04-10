# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/08 21:27:29 by lbenard           #+#    #+#              #
#    Updated: 2020/04/10 22:36:08 by ppetitea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#****************	RAPPEL	****************
#	commentaire mono-ligne

#	commentaire\
	multi-ligne

#	NAME = VALUE -> permet de definir une constante
#	NAME := VALUE -> permet de definir une variable

#	cible:dependance
#		commande

#	$@	Le nom de la cible
#	$<	Le nom de la première dépendance
#	$^	La liste des dépendances
#	$?	La liste des dépendances plus récentes que la cible
#	$*	Le nom du fichier sans suffixe
#	.PHONY -> cible dont les dependances sont systematiquement reconstruites

#	$(addprefix prefix, name) -> permet d'ajouter un prefix


# **************** VARIABLES ****************
UNAME		=	$(shell uname)
NAME		=	test

#SOURCES
SRCS_LIST	=	main.c														\
				log/log.c													\
				node/node.c													\
				data/data.c													\
				data/parser/token.c											\
				data/load/from_file.c										\


SRCS_FOLDER	=	./srcs/
SRCS		=	$(addprefix $(SRCS_FOLDER), $(SRCS_LIST))

#OBJECTS
OBJS_LIST	=	$(SRCS_LIST:.c=.o)	#Pour chaque .c de SRC on construit dans OBJ un .o
OBJS_FOLDER	=	./objs/
OBJS		=	$(addprefix $(OBJS_FOLDER), $(OBJS_LIST))

#HEADERS
INCLUDES_FOLDER	=	./includes/
INCLUDES	:=	-I includes

#COMPILATION
CC			=	gcc
LD			=	gcc
CFLAGS		:=	-Wall -Wextra -O3 -Ofast -flto
LDFLAGS		:=	-lm 

#LIBRARIES
#	libft
LIBFT_FOLDER=	./libft
LIBFT		=	$(LIBFT_FOLDER)/libft.a
INCLUDES	:=	$(INCLUDES) -I $(LIBFT_FOLDER)/includes
LDFLAGS		:=	$(LDFLAGS) -L $(LIBFT_FOLDER) -lft

# Colors
BOLD			=	\e[1m
DIM				=	\e[2m
ITALIC			=	\e[3m
UNDERLINED		=	\e[4m

BLACK			=	\e[30m
RED				=	\e[31m
GREEN			=	\e[32m
YELLOW			=	\e[33m
BLUE			=	\e[34m
MAGENTA			=	\e[35m
CYAN			=	\e[36m
LIGHT_GRAY		=	\e[37m
DARK_GRAY		=	\e[90m
LIGHT_RED		=	\e[91m
LIGHT_GREEN		=	\e[92m
LIGHT_YELLOW	=	\e[93m
LIGHT_BLUE		=	\e[94m
LIGHT_MAGENTA	=	\e[95m
LIGHT_CYAN		=	\e[96m
WHITE			=	\e[97m
RESET			=	\e[0m

PREFIX			=	$(BOLD)$(LIGHT_CYAN)[$(EXEC)]$(RESET):

# **************** RULES ****************

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@printf "Linking...\n"
	@$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

run: $(ALL)
	@./$(NAME)

$(OBJS_FOLDER)%.o: $(SRCS_FOLDER)%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@ $(INCLUDES) $(CFLAGS)

$(LIBFT):
	@make -C libft

clean: libft-clean
	@rm -rf $(OBJS_FOLDER)

mostlyclean:
	@rm -rf $(OBJS_FOLDER)

libft-clean:
	@make -C $(LIBFT_FOLDER) clean

clean-binary:
	@rm -rf $(NAME)

fcl: mostlyclean clean-binary
	@rm -rf $(NAME)

fclean: clean libft-fclean
	@rm -rf $(NAME)

libft-fclean:
	@make -C $(LIBFT_FOLDER) fclean

r: mostlyclean all

re: fclean all

relink: clean-binary $(NAME)

.PHONY: clean mostlyclean libft-clean clean-binary fcl fclean libft-fclean r re relink
