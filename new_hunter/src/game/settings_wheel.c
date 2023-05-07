/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** settings_wheel
*/

#include "hunter.h"
#include "struct.h"

void display_settings(struct game_t *game)
{
    sfFloatRect hitbox = sfSprite_getGlobalBounds(game->sprite[SETTINGS]->sprite);
    if ((sfFloatRect_contains(&hitbox, game->mous_pos.x, game->mous_pos.y)
    && sfMouse_isButtonPressed(0) && game->press == false) ||
    (sfFloatRect_contains(&hitbox, game->pos_manette.x, game->pos_manette.y)
    && sfJoystick_isButtonPressed(0, KEY_A) && game->press == false)) {
        game->settings = !game->settings;
        game->press = true;
    }
    if (!sfMouse_isButtonPressed(0) && !sfJoystick_isButtonPressed(0, KEY_A)
    && game->press == true)
        game->press = false;
    sfRenderWindow_drawSprite(game->window, game->sprite[SETTINGS]->sprite, 0);
}
