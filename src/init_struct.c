/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** init_struct
*/

#include "../include/hunter.h"

void volume(struct hunter_t *hunter)
{
    sfMusic_setVolume(hunter->vader_music, 70);
}

void init_struct(struct hunter_t *hunter)
{
    sfVideoMode mode = { 1366, 716, 32 };
    sfRenderWindow* window = sfRenderWindow_create(mode, "my hunter",
        sfTitlebar | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    hunter->score = 0;
    hunter->vie = 3;
    hunter->ondulation_check = 0;
    hunter->window = window;
    hunter->game_music = sfMusic_createFromFile ("song/game.ogg");
    hunter->explosion_music = sfMusic_createFromFile ("song/explosion.ogg");
    hunter->menu_music = sfMusic_createFromFile ("song/menu.ogg");
    hunter->fire_music = sfMusic_createFromFile ("song/fire.ogg");
    hunter->vader_music = sfMusic_createFromFile ("song/you_lose.wav");
    volume(hunter);
}

void init_struct2(struct hunter_t *hunter, struct star_t *star)
{
    set_background(hunter);
    set_back_game(hunter);
    sprite_bird(hunter);
    sprite_scope1(hunter);
    int fx = open("best/bestscore.txt", O_RDONLY);
    read(fx, hunter->bestscore_char, 2);
    close(fx);
    int best_score = my_getnbr(hunter->bestscore_char);
    hunter->bestscore = best_score;
    sfText *txt_msg_best_score = sfText_create();
    sfText_setFont(txt_msg_best_score,sfFont_createFromFile("text/score.otf"));
    sfText_setCharacterSize(txt_msg_best_score, 42);
    sfText_setString(txt_msg_best_score, "best score : ");
    sfText_setColor(txt_msg_best_score, sfYellow);
    hunter->txt_msg_best_score = txt_msg_best_score;
    hunter->star = star;
    set_vader(hunter);
}
