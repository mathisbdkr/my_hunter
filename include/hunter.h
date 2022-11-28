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
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Vector3.h>
    #include <stddef.h>
    #include <time.h>
    #include <fcntl.h>
    #include <math.h>

struct hunter_t {
    int score;
    int vie;
    sfTime time;
    int speed;
    int haut;
    int ondulation_check;
    int pos_bird_start;
    char score_char[1];
    sfText *txt_score;
    sfRenderWindow *window;
    sfSprite *bird;
    sfSprite *scope;
    sfSprite *background;
    sfSprite *game_over;
    sfSprite *retry;
    sfSprite *quit;
    sfSprite *game_name;
    sfSprite *play;
    sfSprite *explo;
    sfSprite *coeur;
    sfVector2f pos_bird;
    sfVector2f pos_retry;
    sfVector2f pos_quit;
    sfVector2f pos_play;
    sfMusic *menu_music;
    sfMusic *game_music;
    sfMusic *explosion_music;
    sfMusic *fire_music;
    sfText *txt_bestscore;
    sfText *txt_msg_best_score;
    int bestscore;
    char bestscore_char[2];
};

void my_putstr(char const *str);
sfIntRect get_rect(int top, int left, int width, int height);
sfVector2f get_position(int x, int y);
sfIntRect anim_dg(int i, struct hunter_t *hunter);
sfIntRect anim_gd(int i, struct hunter_t *hunter);
sfSprite *sprite_bird(struct hunter_t *hunter);
sfSprite *sprite_scope1(struct hunter_t *hunter);
int shout(sfVector2f mouse_pos, struct hunter_t *hunter, sfEvent event);
int display_bird(struct hunter_t *hunter, sfEvent event);
int timing(struct hunter_t *hunter,int resstart);
int window_end(struct hunter_t *hunter);
sfSprite *set_background(struct hunter_t *hunter);
sfSprite *set_game_over(struct hunter_t *hunter);
sfSprite *set_retry(struct hunter_t *hunter);
sfSprite *set_quit(struct hunter_t *hunter);
int menu_game_over(sfVector2f mouse_pos, struct hunter_t *hunter);
int main_menu(struct hunter_t *hunter);
int main_menu_button(sfVector2f mouse_pos, struct hunter_t *hunter);
sfSprite *set_play(struct hunter_t *hunter);
sfSprite *set_game_name(struct hunter_t *hunter);
sfSprite *set_coeur(struct hunter_t *hunter);
sfIntRect anim_coeur(struct hunter_t *hunter);
sfSprite *set_explosion(struct hunter_t *hunter);
sfIntRect set_anim_explosion(int i, struct hunter_t *hunter);
void init_struct(struct hunter_t *hunter);
void init_struct2(struct hunter_t *hunter);
int my_strlen(char *str);
void txt_score(struct hunter_t *hunter);
void my_putchar(char c);
void display_score(struct hunter_t *hunter, sfText *nbr_score, char *buf);
char* get_score_char(struct hunter_t *hunter);
int display_game(struct hunter_t *hunter, sfEvent event, sfVector2f pos);
int ondulation(struct hunter_t *hunter);
void disp_window_end(struct hunter_t *hunter);
void txt_score_fin(struct hunter_t *hunter);
int my_getnbr(char* nb);
void txt_bestscore_fin(struct hunter_t *hunter);

#endif /* !HUNTER_H_ */
