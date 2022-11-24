/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** hunter
*/

#ifndef HUNTER_H_
#define HUNTER_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

struct hunter_t {
    int score;
    int vie;
    sfTime time;
    int speed;
    int haut;
    sfRenderWindow *window;
    sfSprite *bird;
    sfSprite *scope;
    sfSprite *background;
    sfSprite *game_over;
    sfSprite *retry;
    sfSprite *quit;
    sfVector2f pos_retry;
    sfVector2f pos_quit;
};

void my_putstr(char const *str);
sfIntRect get_rect(int top, int left, int width, int height);
sfVector2f get_position(int x, int y);
sfIntRect anim_dg(int i, struct hunter_t *hunter);
sfIntRect anim_gd(int i, struct hunter_t *hunter);
sfSprite *sprite_bird(void);
sfSprite *sprite_scope1(void);
int shout(sfVector2f mouse_pos, sfVector2f bird_pos, struct hunter_t *hunter, sfEvent event);
int display_bird(struct hunter_t *hunter, sfEvent event);
sfIntRect get_rect(int top, int left, int width, int height);
int timing(struct hunter_t *hunter,int resstart);
int window_end(struct hunter_t *hunter);
sfSprite *set_background(struct hunter_t *hunter);
sfSprite *set_game_over(struct hunter_t *hunter);
sfSprite *set_retry(struct hunter_t *hunter);
sfSprite *set_quit(struct hunter_t *hunter);
int menu_game_over(sfVector2f mouse_pos, struct hunter_t *hunter);
int main(int ac, char **av);

#endif /* !HUNTER_H_ */
