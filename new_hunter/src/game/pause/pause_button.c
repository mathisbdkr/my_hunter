/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** pause_button
*/

#include "hunter.h"
#include "struct.h"

static void pause_button_pt2(struct game_t *game, sfRectangleShape *rect,
    int i)
{
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(rect);
    sfVector2f pos = game->mous_pos;
    if ((sfFloatRect_contains(&bound,pos.x, pos.y)
    && sfMouse_isButtonPressed(0) && i == 2)
    || (sfFloatRect_contains(&bound, game->pos_manette.x, game->pos_manette.y)
    && sfJoystick_isButtonPressed(0, KEY_A) && i == 2)) {
        back_to_menu(game);
    }
    if ((sfFloatRect_contains(&bound,pos.x, pos.y)
    && sfMouse_isButtonPressed(0) && i == 3) ||
    (sfFloatRect_contains(&bound, game->pos_manette.x, game->pos_manette.y)
    && sfJoystick_isButtonPressed(0, KEY_A) && i == 3)) {
        sfRenderWindow_close(game->window);
        game->end = 1;
    }
}

void pause_button(struct game_t *game, sfRectangleShape *rect, int i)
{
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(rect);
    sfVector2f pos = game->mous_pos;
    if ((sfFloatRect_contains(&bound,pos.x, pos.y)
    && sfMouse_isButtonPressed(0) && i == 0)
    || (sfFloatRect_contains(&bound, game->pos_manette.x, game->pos_manette.y)
    && sfJoystick_isButtonPressed(0, KEY_A) && i == 0))
        game->is_pause = false;
    if ((sfFloatRect_contains(&bound,pos.x, pos.y)
    && sfMouse_isButtonPressed(0) && i == 1)
    || (sfFloatRect_contains(&bound, game->pos_manette.x, game->pos_manette.y)
    && sfJoystick_isButtonPressed(0, KEY_A) && i == 1)) {
        game->is_settings = true;
    }
    pause_button_pt2(game, rect, i);
}
