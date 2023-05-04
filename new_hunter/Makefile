##
## EPITECH PROJECT, 2023
## hunter_v2
## File description:
## Makefile
##

CC	=	gcc

SRC	=	./src/main.c				\
		./src/launch_game.c			\
		./src/menu_selector.c		\
		./src/init/init_game.c		\
		./src/init/init_ship.c		\
		./src/main_menu/main_menu.c	\
		./src/game/game_main.c		\
		./src/game/anim.c			\
		./src/lib/get_position.c	\
		./src/lib/made_round_rect.c	\
		./src/lib/make_button.c		\
		./src/lib/make_text.c		\
		./src/lib/my_getnbr.c		\
		./src/lib/my_strcat.c		\
		./src/lib/my_strcpy.c		\
		./src/lib/my_strdup.c		\
		./src/lib/my_strlen.c		\
		./src/lib/word_array.c		\

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
