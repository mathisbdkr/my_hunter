##
## EPITECH PROJECT, 2023
## hunter_v2
## File description:
## Makefile
##

CC	=	gcc

INIT	=	./src/init/

GAME	=	./src/game/

LIB		=	./src/lib/

SETTINGS	=	./src/settings/

GAME_OVER	=	./src/menu_game_over/

SRC	=	./src/main.c							\
		./src/launch_game.c						\
		./src/menu_selector.c					\
		./src/main_menu/main_menu.c				\
		./src/main_menu/difficulty.c			\
		$(INIT)init_game.c						\
		$(INIT)init_ship.c						\
		$(INIT)init_song.c						\
		$(INIT)init_settings.c					\
		$(INIT)init_sprite.c					\
		$(GAME)game_main.c						\
		$(GAME)anim.c							\
		$(GAME)display_score.c					\
		$(GAME)hit_ship.c						\
		$(GAME)pause_wheel.c					\
		$(GAME)pause/menu_pause.c				\
		$(GAME)pause/back_to_menu.c				\
		$(GAME)pause/pause_button.c				\
		$(SETTINGS)volume/box.c					\
		$(SETTINGS)volume/center_bare.c			\
		$(SETTINGS)volume/curseur_bare.c		\
		$(SETTINGS)volume/song_manager.c		\
		$(SETTINGS)volume/volume_bare.c			\
		$(SETTINGS)display_settings.c			\
		$(SETTINGS)window/fps_manager.c			\
		$(SETTINGS)window/size_win_manager.c	\
		$(SETTINGS)controler/controler_manager.c\
		$(SETTINGS)save_settings.c				\
		$(GAME_OVER)game_over_main.c			\
		$(LIB)get_position.c					\
		$(LIB)set_music.c						\
		$(LIB)made_round_rect.c					\
		$(LIB)make_button.c						\
		$(LIB)make_text.c						\
		$(LIB)my_getnbr.c						\
		$(LIB)my_strcat.c						\
		$(LIB)my_strcpy.c						\
		$(LIB)my_strdup.c						\
		$(LIB)my_strlen.c						\
		$(LIB)word_array.c						\
		$(LIB)my_getchar.c						\

OBJ	=	$(SRC:.c=.o)

CSFML_FLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS  =	-Wall -Wextra

CPPFLAGS	=	-I include

BIN_NAME	=	hunter

all:	$(OBJ)
	$(CC) -o $(BIN_NAME) $(OBJ) $(CSFML_FLAGS) $(CFLAGS) -lm -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(BIN_NAME)

re: fclean all

.PHONY: clean fclean re
