##
## EPITECH PROJECT, 2022
## hunter
## File description:
## Makefile
##

SRC	=	src/*.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

$(NAME):
	gcc $(SRC) -lcsfml-system -lcsfml-graphics -lcsfml-audio -lcsfml-window -I include -o $(NAME)

all:	$(NAME) clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm $(NAME)

re:	fclean all

.PHONY:	$(NAME) all clean