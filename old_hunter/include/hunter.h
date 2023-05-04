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
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>

struct hunter_t {
    int score;
    int vie;
    sfTime time;
    int speed;
    int ondulation_check;
    int pos_bird_start;
    char score_char[1];
    sfText *txt_score;
    sfRenderWindow *window;
    sfSprite *bird;
    sfSprite *scope;
    sfSprite *game_name;
    sfSprite *play;
    sfSprite *explo;
    sfSprite *coeur;
    sfSprite *back_game;
    sfVector2f pos_bird;
    sfVector2f pos_retry;
    sfVector2f pos_quit;
    sfVector2f pos_play;
    sfMusic *game_music;
    sfMusic *explosion_music;
    sfMusic *fire_music;
    sfMusic *menu_music;
    sfMusic *vader_music;
    sfText *txt_bestscore;
    sfText *txt_msg_best_score;
    int bestscore;
    char bestscore_char[2];
    sfClock *cloky;
    struct star_t *star;
    sfSprite *background;
};

struct star_t {
    int speed;
    int pos_star_start;
    sfSprite *sprite_star;
    sfVector2f pos_star;
    int pos_star_two_start;
    sfSprite *sprite_star_two;
    sfVector2f pos_star_two;
    sfSprite *cockpit;
    sfSprite *game_over;
    sfSprite *retry;
    sfSprite *quit;
    sfSprite *quit_end;
    sfSprite *light;
    sfSprite *vader_sprite;
};

void bird_gd(struct hunter_t *hunter, sfEvent event, struct star_t *star);
void bird_dg(struct hunter_t *hunter, sfEvent event, struct star_t *star);
int ondulation(struct hunter_t *hunter);

void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char* nb);

int window_end(struct hunter_t *hunter);
int shout(sfVector2f mouse_pos, struct hunter_t *hunter, sfEvent event);

sfIntRect get_rect(int top, int left, int width, int height);
sfIntRect anim_coeur(struct hunter_t *hunter);
sfIntRect set_anim_explosion(int i, struct hunter_t *hunter);
sfIntRect anim_dg(int i, struct hunter_t *hunter);
sfIntRect anim_gd(int i, struct hunter_t *hunter);

sfSprite *set_vader(struct hunter_t *hunter);
sfSprite *set_play(struct hunter_t *hunter);
sfSprite *set_quit(struct hunter_t *hunter);
sfSprite *set_retry(struct hunter_t *hunter);
sfSprite *set_game_over(struct hunter_t *hunter);
sfSprite *set_quit_end(struct hunter_t *hunter);
sfSprite *set_game_name(struct hunter_t *hunter);
sfSprite *set_cockpit(struct hunter_t *hunter);
sfSprite *set_coeur(struct hunter_t *hunter);
sfSprite *sprite_scope1(struct hunter_t *hunter);
sfSprite *set_explosion(struct hunter_t *hunter);
sfSprite *sprite_bird(struct hunter_t *hunter);
sfSprite *set_background(struct hunter_t *hunter);
sfSprite *set_back_game(struct hunter_t *hunter);

int vader(struct hunter_t *hunter);
int main_menu(struct hunter_t *hunter);
int menu_game_over(sfVector2f mouse_pos, struct hunter_t *hunter);

void init_struct(struct hunter_t *hunter);
void init_struct2(struct hunter_t *hunter, struct star_t *star);
void init_star(struct star_t *star);

sfVector2f get_position(float x, float y);

int display_bird(struct hunter_t *hunter, sfEvent event, struct star_t *star);
void disp_window_end(struct hunter_t *hunter);
void display_score(struct hunter_t *hunter, sfText *nbr_score, char *buf);
int display_game(struct hunter_t *hunter, sfEvent event, sfVector2f pos);

char* get_score_char(struct hunter_t *hunter);
void txt_score_fin(struct hunter_t *hunter);
void txt_score(struct hunter_t *hunter);
void txt_bestscore_fin(struct hunter_t *hunter);

int timing(struct hunter_t *hunter, int resstart);

#endif /* !HUNTER_H_ */
