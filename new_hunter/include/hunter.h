/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** hunter
*/

#ifndef HUNTER_H_
    #define HUNTER_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <math.h>
    #include <sys/stat.h>
    #include <time.h>
    #include "stdbool.h"


//  launch the game //

int launch_game(void);


//  init structure  //

struct game_t *init_game(void);
struct ship_t **init_ship(struct game_t *game);

//  menu selector   //

void menu_selector(struct game_t *game);


//  main menu   //

void main_menu(struct game_t *game);


//  game functions  //

void game_main(struct game_t *game);


//  animation   //

sfIntRect anim_ship(struct game_t *game, int i);
sfIntRect anim_life(struct game_t *game);


//  lib //

sfSprite *set_sprite(char *path, float size);
void made_rond_rect(sfVector2f size, sfVector2f pos, sfColor color,
    sfRenderWindow *window);
sfVector2f get_position(float x, float y);
sfRectangleShape *made_button(sfVector2f size, sfVector2f pos, sfColor color);
sfText *made_txt(char *text, sfVector2f pos, sfVector2f size, sfFont *font);
int my_getnbr(char *str);
char **my_str_to_word_array(char *str, char sep);
char *my_strcat(char* src, char* dest);
char *my_strcpy(char* dest, char* src);
char *my_strdup(char *s1);
int my_strlen(char const *str);

#endif /* !HUNTER_H_ */
