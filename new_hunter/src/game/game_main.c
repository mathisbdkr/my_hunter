/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** game_main
*/

#include "hunter.h"
#include "struct.h"

static void hit_ship(sfSprite *sprite, struct game_t *game, int i)
{
    sfFloatRect hitbox = sfSprite_getGlobalBounds(sprite);
    if ((sfFloatRect_contains(&hitbox, game->mous_pos.x, game->mous_pos.y)
    && sfMouse_isButtonPressed(0) && game->press == false) ||
    (sfFloatRect_contains(&hitbox, game->pos_manette.x, game->pos_manette.y)
    && sfJoystick_isButtonPressed(0, KEY_A) && game->press == false)) {
        game->ship[i]->hit = true;
        game->press = true;
    }
    if (!sfMouse_isButtonPressed(0) && !sfJoystick_isButtonPressed(0, KEY_A))
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

static void round_end(struct game_t *game)
{
    for (int i = 0; i < game->stat->level; i++) {
        if (game->ship[i]->hit == false) {
            return;
        }
    }
    for (int i = 0; i < game->stat->level; i++) {
        free(game->ship[i]);
    }
    free(game->ship);
    game->stat->level += 1;
    game->ship = init_ship(game);
}

static void display_life(struct game_t *game)
{
    sfSprite_setTextureRect(game->sprite[HEART]->sprite, anim_life(game));
    sfRenderWindow_drawSprite(game->window, game->sprite[HEART]->sprite, 0);
    if (game->stat->life <= 0) {
        game->menu = 0;
        game->stat->life = 3;
        game->stat->level = 1;
    }
}

void game_main(struct game_t *game)
{
    for (int i = 0; i < game->stat->level; i++) {
        if (game->ship[i]->hit)
            continue;
        game->ship[i]->anim_frame += 1;
        sfSprite_setTextureRect(game->ship[i]->ship, anim_ship(game, i));
        hit_ship(game->ship[i]->ship, game, i);
        if (game->ship[i]->left == true) {
            game->ship[i]->pos.x -= 1 + ((float)game->stat->level / 4);
        } else {
            game->ship[i]->pos.x += 1 + ((float)game->stat->level / 4);
        }
        sfSprite_setPosition(game->ship[i]->ship, game->ship[i]->pos);
        sfRenderWindow_drawSprite(game->window, game->ship[i]->ship, 0);
    }
    round_end(game);
    display_life(game);
}
