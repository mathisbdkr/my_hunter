/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** display_score
*/

#include "hunter.h"
#include "struct.h"

void display_lvl(struct game_t *game)
{
    char *lvl = my_getchar(game->stat->level);
    char *text = "lvl: ";
    text = my_strcat(text, lvl);
    sfText *txt = made_txt(text, get_position(220, 0),
    get_position(1.5, 1.5), game->starjhol);
    sfRenderWindow_drawText(game->window, txt, 0);
}

void display_score(struct game_t *game)
{
    char *score = my_getchar(game->stat->score);
    char *text = "score: ";
    text = my_strcat(text, score);
    sfText *txt = made_txt(text, get_position(450, 0),
    get_position(1.5, 1.5), game->starjhol);
    sfRenderWindow_drawText(game->window, txt, 0);
}
