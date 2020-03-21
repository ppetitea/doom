# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/08 21:27:29 by lbenard           #+#    #+#              #
#    Updated: 2020/03/09 15:32:43 by ppetitea         ###   ########.fr        #
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
NAME		=	doom-nukem

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
				build/scenes/test/color_map_canvas.c						\
				build/scenes/test/world3d_canvas.c							\
				build/scenes/test/test_scene.c								\
																			\
				loop.c														\
				resources/game/game_init.c									\
				resources/images/image_get.c								\
				resources/images/image_load.c								\
				resources/buttons/button_init.c								\
				resources/canvas/canvas_init.c								\
				resources/canvas/canvas_update.c							\
				resources/maps/map_init.c									\
				resources/maps/map_get.c									\
				resources/players/player_init.c								\
				resources/scenes/scene_get.c								\
				resources/scenes/scene_init.c								\
				resources/scenes/scene_render.c								\
																			\
				events/handle.c												\
				events/actions/action_add.c									\
				events/actions/action_init.c								\
				events/actions/action_trigger.c								\
				events/keyboard/keyboard_handle.c							\
				events/keyboard/keyboard_init.c								\
				events/keyboard/keyboard_sub.c								\
				events/keyboard/keyboard_trigger.c							\
				events/mouse/mouse_get.c									\
				events/mouse/mouse_handle.c									\
				events/mouse/mouse_init.c									\
				events/mouse/mouse_sub.c									\
				events/mouse/mouse_trigger.c								\
				events/mouse/mouse_update.c									\
				events/observer/observer_init.c								\
				events/observer/observer_sub.c								\
				events/observer/observer_trigger.c							\
																			\
				interface/screen/screen_get.c								\
				interface/screen/screen_init.c								\
				interface/screen/screen_reset.c								\
				interface/sdl/sdl_init.c									\
				interface/sdl/sdl_destroy.c									\
																			\
				graphic/animations/animation_animate.c						\
				graphic/animations/animation_build.c						\
				graphic/animations/animation_copy.c							\
				graphic/animations/animation_init.c							\
				graphic/animations/animation_overwrite.c					\
				graphic/animations/animation_render.c						\
				graphic/animations/animation_observer.c						\
				graphic/animations/animation_sub.c							\
				graphic/animations/animation_transform.c					\
				graphic/animations/animation_update.c						\
				graphic/textures/texture_add.c								\
				graphic/textures/texture_build.c							\
				graphic/textures/texture_copy.c								\
				graphic/textures/texture_filter.c							\
				graphic/textures/texture_init.c								\
				graphic/textures/texture_render.c							\

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

#  SDL
SDL_FOLDER		=	./SDL
SDL				=	$(SDL_FOLDER)/build
SDL_CONFIGURE	=	$(SDL_FOLDER)/aclocal.m4
INCLUDES		:=	$(INCLUDES) -I $(SDL_FOLDER)/include
LDFLAGS			:=	$(LDFLAGS) -L $(SDL_FOLDER) -lSDL2

#  SDL Mixer
SDL_MIXER_FOLDER	=	./SDL_mixer
SDL_MIXER			=	$(SDL_MIXER_FOLDER)/build
SDL_MIXER_CONFIGURE	=	$(SDL_MIXER_FOLDER)/autom4te.cache
INCLUDES			:=	$(INCLUDES) -I $(SDL_MIXER_FOLDER)
LDFLAGS				:=	$(LDFLAGS) -Wl,-rpath=$(SDL_MIXER_FOLDER)/build/.libs -L $(SDL_MIXER_FOLDER)/build/.libs -lSDL2_mixer

#  SDL TTF
SDL_TTF_FOLDER		=	./SDL_ttf
SDL_TTF				=	$(SDL_TTF_FOLDER)/.libs
SDL_TTF_CONFIGURE	=	$(SDL_TTF_FOLDER)/autom4te.cache
INCLUDES			:=	$(INCLUDES) -I $(SDL_TTF_FOLDER)
LDFLAGS				:=	$(LDFLAGS) -Wl,-rpath=$(SDL_TTF_FOLDER) -L $(SDL_TTF_FOLDER) #-lSDL2_ttf

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

all: $(SDL) $(SDL_MIXER) $(SDL_TTF) $(LIBFT) $(NAME)

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

$(SDL_CONFIGURE):
	@printf "Configuring SDL...\n"
	@cd $(SDL_FOLDER) && \
	./autogen.sh && \
	./configure

$(SDL): $(SDL_CONFIGURE)
	@printf "Compiling SDL...\n"
	@cd $(SDL_FOLDER) && \
	make

$(SDL_MIXER_CONFIGURE):
	@printf "Configuring SDL Mixer...\n"
	@cd $(SDL_MIXER_FOLDER) && \
	./autogen.sh && \
	./configure

$(SDL_MIXER): $(SDL_MIXER_CONFIGURE)
	@printf "Compiling SDL Mixer...\n"
	@cd $(SDL_MIXER_FOLDER) && \
	make

$(SDL_TTF_CONFIGURE):
	@printf "Configuring SDL TTF...\n"
	@cd $(SDL_TTF_FOLDER) && \
	./autogen.sh && \
	./configure

$(SDL_TTF): $(SDL_TTF_CONFIGURE)
	@printf "Compiling SDL TTF...\n"
	@cd $(SDL_TTF_FOLDER) && \
	make

clean: libft-clean sdl-clean
	@rm -rf $(OBJS_FOLDER)

mostlyclean:
	@rm -rf $(OBJS_FOLDER)

libft-clean:
	@make -C $(LIBFT_FOLDER) clean

sdl-clean:
	# @make -C $(SDL_FOLDER) clean

sdl-mixer-clean:
	@make -C $(SDL_MIXER_FOLDER) clean

sdl-ttf-clean:
	@make -C $(SDL_TTF_FOLDER) clean

clean-binary:
	@rm -rf $(NAME)

fcl: mostlyclean clean-binary
	@rm -rf $(NAME)

fclean: clean libft-fclean sdl-fclean
	@rm -rf $(NAME)

libft-fclean:
	@make -C $(LIBFT_FOLDER) fclean

sdl-fclean: sdl-clean
	@rm -rf $(SDL_FOLDER)/build

sdl-mixer-fclean: sdl-mixer-clean
	@rm -rf $(SDL_MIXER_FOLDER)/build

sdl-ttf-fclean: sdl-ttf-clean
	@rm -rf $(SDL_TTF_FOLDER)/.libs

r: mostlyclean all

re: fclean all

relink: clean-binary $(NAME)

.PHONY: clean mostlyclean libft-clean sdl-clean sdl-mixer-clean sdl-ttf-clean clean-binary fcl fclean libft-fclean sdl-fclean sdl-mixer-fclean sdl-ttf-fclean r re relink
