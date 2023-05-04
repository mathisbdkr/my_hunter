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
    hunter->star->game_over = game_over;
}

sfSprite *set_retry(struct hunter_t *hunter)
{
    sfSprite *retry = sfSprite_create();
    sfSprite_setTexture(retry,
    sfTexture_createFromFile("img/retry.png", NULL), 0);
    hunter->star->retry = retry;
}

sfSprite *set_quit(struct hunter_t *hunter)
{
    sfSprite *quit = sfSprite_create();
    sfSprite_setTexture(quit,
    sfTexture_createFromFile("img/quit.png", NULL), 0);
    hunter->star->quit = quit;
}

sfSprite *set_vader(struct hunter_t *hunter)
{
    sfSprite *vader = sfSprite_create();
    sfSprite_setTexture(vader,
    sfTexture_createFromFile("img/vader.jpg", NULL), 0);
    hunter->star->vader_sprite = vader;
}

sfSprite *set_quit_end(struct hunter_t *hunter)
{
    sfSprite *quit = sfSprite_create();
    sfSprite_setTexture(quit,
    sfTexture_createFromFile("img/quite_end.png", NULL), 0);
    hunter->star->quit_end = quit;
}
