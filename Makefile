# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/08 21:27:29 by lbenard           #+#    #+#              #
#    Updated: 2020/02/29 17:21:30 by ppetitea         ###   ########.fr        #
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



#****************	VARIABLES	****************
UNAME		=	$(shell uname)
EXEC		=	doom-nukem

#SOURCES
SRCS_LIST	=	main.c														\
																			\
				utils/color/add_blend.c										\
				utils/error/debug_mode.c									\
				utils/error/throw_null.c									\
				utils/error/throw_void.c									\
				utils/error/throw_error.c									\
				utils/error/throw_warning.c									\
				utils/matrix/mult.c											\
				utils/matrix/rotate.c										\
				utils/matrix/scale.c										\
				utils/matrix/to_vtx.c										\
				utils/matrix/translate.c									\
				utils/time/get_delta_ptr.c									\
				utils/time/set_delta.c										\
				utils/time/get_delta.c										\
				utils/time/delta.c											\
				utils/time/get_wall_time.c									\
				utils/parser/check/close_curly_braces.c						\
				utils/parser/check/curly_braces.c							\
				utils/parser/check/open_curly_braces.c						\
				utils/parser/check/utility.c								\
				utils/parser/debug/debug.c									\
				utils/parser/get_data_in_string/get_index.c					\
				utils/parser/get_data_in_string/get_key.c					\
				utils/parser/get_data_in_string/get_value_type.c			\
				utils/parser/get_data_in_string/get_value.c					\
				utils/parser/object/getter/get_child_object.c				\
				utils/parser/object/getter/get_float_value.c				\
				utils/parser/object/getter/get_int_value.c					\
				utils/parser/object/getter/get_string_value.c				\
				utils/parser/object/getter/init_with_obj.c					\
				utils/parser/object/getter/strcmp_obj.c						\
				utils/parser/object/create.c								\
				utils/parser/object/free.c									\
				utils/parser/read_file/get_file_datas.c						\
				utils/parser/split_data/free_string_array.c					\
				utils/parser/split_data/new_string_array.c					\
				utils/parser/split_data/split_data.c						\
				utils/parser/parser.c										\
				utils/parser/to_object.c									\
																			\
				build.c														\
				build/scenes/test/play_button.c								\
				build/scenes/test/test_scene.c								\
																			\
				loop.c														\
				resources/game/game_init.c									\
				resources/images/image_get.c								\
				resources/images/image_load.c								\
				resources/buttons/button_init.c								\
				resources/scenes/scene_init.c								\
				resources/scenes/scene_render.c								\
				resources/maps/map_config_init.c							\
				resources/maps/map_init.c									\
																			\
				events/handle.c												\
				events/actions/action_add.c									\
				events/actions/action_init.c								\
				events/mouse/mouse_handle.c									\
				events/keyboard/keyboard_handle.c							\
				events/observer/observable_init.c							\
				events/observer/observer_init.c								\
				events/observer/observer_sub.c								\
																			\
				interface/screen/screen_get.c								\
				interface/screen/screen_init.c								\
				interface/screen/screen_reset.c								\
				interface/sdl/sdl_init.c									\
				interface/sdl/sdl_destroy.c									\
																			\
				graphic/animations/animation_build.c						\
				graphic/animations/animation_collide.c						\
				graphic/animations/animation_copy.c							\
				graphic/animations/animation_init.c							\
				graphic/animations/animation_overwrite.c					\
				graphic/animations/animation_sub.c							\
				graphic/animations/animation_update.c						\
				graphic/textures/texture_add.c								\
				graphic/textures/texture_build.c							\
				graphic/textures/texture_copy.c								\
				graphic/textures/texture_filter.c							\
				graphic/textures/texture_init.c								\

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
CFLAGS		:=	-Wall -Werror -Wextra -O3 -Ofast -flto
LDFLAGS		:=	-lm 

#LIBRARIES
#	libft
LIBFT_FOLDER=	./libft
LIBFT		=	$(LIBFT_FOLDER)/libft.a
INCLUDES	:=	$(INCLUDES) -I $(LIBFT_FOLDER)/includes
LDFLAGS		:=	$(LDFLAGS) -L $(LIBFT_FOLDER) -lft

#	SDL
SDL_FOLDER	=	./SDL
SDL			=	$(SDL_FOLDER)/build/.libs/libSDL2.a
INCLUDES	:=	$(INCLUDES) -I $(SDL_FOLDER)/include
LDFLAGS		:=	$(LDFLAGS) -L $(SDL_FOLDER) `sdl2-config --libs`

#	SDL_ttf
#SDL_TTF_FOLDER	=	./SDL2_ttf
#SDL_TTF			=	$(SDL_TTF_FOLDER)/.libs/libSDL2_ttf.a
#INCLUDES		:=	$(INCLUDES) -I $(SDL_TTF_FOLDER)
#LDFLAGS			:=	$(LDFLAGS) -L $(SDL_TTF_FOLDER)/.libs -lSDL2_ttf

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

#****************	RULES	****************
all: $(SDL) $(SDL_TTF) $(LIBFT) $(EXEC)

$(EXEC): $(OBJS)
	@$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)
	@printf "\e[0K$(PREFIX) done\n"

$(OBJS_FOLDER)%.o: $(SRCS_FOLDER)%.c
	@printf "$(PREFIX) $<\n"
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@ $(INCLUDES) $(CFLAGS)
	@printf "\e[1A\e[0K"

$(LIBFT):
	@make -C libft

$(SDL):
	@printf "compiling SDL it may takes long time ~3mn <3\n";
	@cd $(SDL_FOLDER) &&\
	./configure > /dev/null &&\
	make > /dev/null;

$(SDL_TTF):
	@printf "compiling SDL it may takes long time ~3mn <3\n";
	@cd $(SDL_TTF_FOLDER) &&\
	./configure > /dev/null &&\
	make > /dev/null;

run: all
	@./$(EXEC)

cl:
	@rm -rf $(OBJS_FOLDER)

clean: libft-clean sdl-clean
	@rm -rf $(OBJS_FOLDER)

libft-clean:
	@make -C $(LIBFT_FOLDER) clean > /dev/null

sdl-clean:
	@cd $(SDL_FOLDER) &&\
	make clean > /dev/null;

fcl: cl
	@rm -rf $(EXEC)

fclean: clean libft-fclean sdl-fclean
	@rm -rf $(EXEC)

libft-fclean:
	@make -C $(LIBFT_FOLDER) fclean > /dev/null

sdl-fclean:
	@make -C $(SDL_FOLDER) clean > /dev/null

r: cl all

re: fclean all

.PHONY: clean libft-clean sdl-clean fclean libft-fclean sdl-fclean re
