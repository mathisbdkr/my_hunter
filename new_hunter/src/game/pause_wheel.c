/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** settings_wheel
*/

#include "hunter.h"
#include "struct.h"

void display_pause(struct game_t *game)
{
    sfFloatRect hitbox = sfSprite_getGlobalBounds(game->sprite[PAUSE]->sprite);
    if ((sfFloatRect_contains(&hitbox, game->mous_pos.x, game->mous_pos.y)
    && sfMouse_isButtonPressed(0) && game->is_press == false) ||
    (sfFloatRect_contains(&hitbox, game->pos_manette.x, game->pos_manette.y)
    && sfJoystick_isButtonPressed(0, KEY_A) && game->is_press == false)) {
        game->is_pause = !game->is_pause;
        game->is_press = true;
    }
    if (!sfMouse_isButtonPressed(0) && !sfJoystick_isButtonPressed(0, KEY_A)
    && game->is_press == true)
        game->is_press = false;
    sfRenderWindow_drawSprite(game->window, game->sprite[PAUSE]->sprite, 0);
}
