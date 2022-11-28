/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** sprite_game_over
*/

#include "../include/hunter.h"

sfSprite *set_game_over(struct hunter_t *hunter)
{
    sfSprite *game_over = sfSprite_create();
    sfSprite_setTexture(game_over,
    sfTexture_createFromFile("img/game_over.png", NULL), 0);
    hunter->game_over = game_over;
}

sfSprite *set_retry(struct hunter_t *hunter)
{
    sfSprite *retry = sfSprite_create();
    sfSprite_setTexture(retry,
    sfTexture_createFromFile("img/retry.png", NULL), 0);
    hunter->retry = retry;
}

sfSprite *set_quit(struct hunter_t *hunter)
{
    sfSprite *quit = sfSprite_create();
    sfSprite_setTexture(quit,
    sfTexture_createFromFile("img/quit.png", NULL), 0);
    hunter->quit = quit;
}
