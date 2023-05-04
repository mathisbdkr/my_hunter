/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** sprite_main_menu
*/

#include "../include/hunter.h"

sfSprite *set_game_name(struct hunter_t *hunter)
{
    sfSprite *game_name = sfSprite_create();
    sfSprite_setTexture(game_name,
    sfTexture_createFromFile("img/game_name.png", NULL), 0);
    hunter->game_name = game_name;
}

sfSprite *set_play(struct hunter_t *hunter)
{
    sfSprite *play = sfSprite_create();
    sfSprite_setTexture(play,
    sfTexture_createFromFile("img/play.png", NULL), 0);
    hunter->play = play;
}

sfSprite *set_cockpit(struct hunter_t *hunter)
{
    sfSprite *cockpit = sfSprite_create();
    sfSprite_setTexture(cockpit,
    sfTexture_createFromFile("img/cockpit.png", NULL), 0);
    hunter->star->cockpit = cockpit;
}
