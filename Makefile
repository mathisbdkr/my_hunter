##
## EPITECH PROJECT, 2022
## hunter
## File description:
## Makefile
##

SRC	=	src/anim.c	\
	src/bird.c	\
	src/display_all.c	\
	src/game_over.c	\
	src/init_struct.c	\
	src/main_menu_button.c	\
	src/main_menu.c	\
	src/main.c	\
	src/menu_game_over.c	\
	src/my_putchar.c	\
	src/set_sprite.c	\
	src/shout.c	\
	src/sprite_game_over.c	\
	src/sprite_main_menu.c	\
	src/time.c	\
	src/my_getnbr.c	\
	src/init_star.c	\
	src/display_game.c	\
	src/vader.c	\

OBJ	=	$(SRC/.c=.o)

NAME	=	my_hunter

LIB	=	-lcsfml-system -lcsfml-graphics -lcsfml-audio -lcsfml-window

$(NAME):
	gcc $(SRC) $(LIB) -o $(NAME)

all:	$(NAME) clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm $(NAME)

re:	fclean all

.PHONY:	$(NAME) all clean
