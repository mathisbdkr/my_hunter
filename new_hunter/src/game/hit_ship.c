/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** hit_ship
*/

#include "hunter.h"
#include "struct.h"

static void identify_hit(sfSprite *sprite, struct game_t *game, int i)
{
    sfFloatRect hitbox = sfSprite_getGlobalBounds(sprite);
    if ((sfFloatRect_contains(&hitbox, game->mous_pos.x, game->mous_pos.y)
    && sfMouse_isButtonPressed(0) && game->press == false) ||
    (sfFloatRect_contains(&hitbox, game->pos_manette.x, game->pos_manette.y)
    && sfJoystick_isButtonPressed(0, KEY_A) && game->press == false)) {
        game->ship[i]->hit = true;
        game->press = true;
        game->ship[i]->anim_frame = 0;
        game->stat->score += 100;
        sfMusic_stop(game->song->effect_fire);
        sfMusic_stop(game->song->effect_eplo);
        sfMusic_play(game->song->effect_fire);
        sfMusic_play(game->song->effect_eplo);
    }
}

void hit_ship(sfSprite *sprite, struct game_t *game, int i)
{
    identify_hit(sprite, game, i);
    if (!sfMouse_isButtonPressed(0) && !sfJoystick_isButtonPressed(0, KEY_A)
    && game->press == true)
        game->press = false;
    if (game->ship[i]->left &&
    game->ship[i]->pos.x <= -134 && !game->ship[i]->hit) {
        game->stat->life -= 1;
        game->ship[i]->hit = true;
    } else if (!game->ship[i]->left &&
    game->ship[i]->pos.x >= 2053 && !game->ship[i]->hit) {
        game->stat->life -= 1;
        game->ship[i]->hit = true;
    }
}
