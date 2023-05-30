/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** display_settings
*/

#include "hunter.h"
#include "struct.h"

void display_settings(struct game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->sprite[BACK_MENU]->sprite, 0);
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    song_manager(game);
    fps_manager(game);
    size_win_manager(game);
    if (sfJoystick_isConnected(0)) {
        controler_manager(game);
        sfSprite_setPosition(game->sprite[SCOPE]->sprite, game->pos_manette);
        sfRenderWindow_drawSprite(game->window,
        game->sprite[SCOPE]->sprite, 0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue
    || sfJoystick_isButtonPressed(0, KEY_B)) {
        game->is_settings = false;
    }
}
