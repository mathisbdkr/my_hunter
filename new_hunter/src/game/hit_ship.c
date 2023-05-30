/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** hit_ship
*/

#include "hunter.h"
#include "struct.h"

static void identify_hit_bosse(sfSprite *sprite, struct game_t *game, int i)
{
    sfFloatRect hitbox = sfSprite_getGlobalBounds(sprite);
    if ((sfFloatRect_contains(&hitbox, game->mous_pos.x, game->mous_pos.y)
    && sfMouse_isButtonPressed(0) && game->is_press == false) ||
    (sfFloatRect_contains(&hitbox, game->pos_manette.x, game->pos_manette.y)
    && sfJoystick_isButtonPressed(0, KEY_A) && game->is_press == false)) {
        game->ship[0]->boss_nb_hit++;
        if (game->ship[0]->boss_nb_hit >= game->stat->level * 1.5) {
            game->ship[0]->hit = true;
            game->ship[0]->anim_frame = 0;
            game->stat->score += 1000;
            sfMusic_stop(game->song.effect_eplo);
            sfMusic_play(game->song.effect_eplo);
        }
        sfMusic_stop(game->song.effect_fire);
        sfMusic_play(game->song.effect_fire);
        game->is_press = true;
    }
}

static void identify_hit(sfSprite *sprite, struct game_t *game, int i)
{
    sfFloatRect hitbox = sfSprite_getGlobalBounds(sprite);
    if ((sfFloatRect_contains(&hitbox, game->mous_pos.x, game->mous_pos.y)
    && sfMouse_isButtonPressed(0) && game->is_press == false) ||
    (sfFloatRect_contains(&hitbox, game->pos_manette.x, game->pos_manette.y)
    && sfJoystick_isButtonPressed(0, KEY_A) && game->is_press == false)) {
        game->ship[i]->hit = true;
        game->is_press = true;
        game->ship[i]->anim_frame = 0;
        game->stat->score += 100;
        sfMusic_stop(game->song.effect_fire);
        sfMusic_stop(game->song.effect_eplo);
        sfMusic_play(game->song.effect_fire);
        sfMusic_play(game->song.effect_eplo);
    }
}

void hit_ship(sfSprite *sprite, struct game_t *game, int i)
{
    int nb_border = 0;
    if (game->stat->is_bosse) {
        nb_border = 1;
        identify_hit_bosse(sprite, game, i);
    } else {
        identify_hit(sprite, game, i);
    }
    if (!sfMouse_isButtonPressed(0) && !sfJoystick_isButtonPressed(0, KEY_A)
    && game->is_press == true)
        game->is_press = false;
    if (game->ship[i]->left &&
    game->ship[i]->pos.x <= win_border[nb_border].x && !game->ship[i]->hit) {
        game->stat->life -= 1;
        game->ship[i]->hit = true;
    } else if (!game->ship[i]->left &&
    game->ship[i]->pos.x >= win_border[nb_border].y && !game->ship[i]->hit) {
        game->stat->life -= 1;
        game->ship[i]->hit = true;
    }
}
