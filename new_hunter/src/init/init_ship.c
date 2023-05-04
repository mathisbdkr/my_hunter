/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** init_ship
*/

#include "hunter.h"
#include "struct.h"

static sfSprite *reverse_dir(sfSprite *sprite)
{
    sfSprite_setRotation(sprite, 180);
    sfVector2f scale = sfSprite_getScale(sprite);
    scale.y *= 0.8;
    scale.x *= -0.8;
    sfSprite_setScale(sprite, scale);
    return sprite;
}

static void set_ship(struct ship_t **ship, int i, sfVector2u size_win)
{
    if (rand() % 100 >= 50) {
        ship[i]->ship = reverse_dir(ship[i]->ship);
        ship[i]->pos = get_position((rand() % 400) + size_win.x,
        rand() % (size_win.y));
        ship[i]->left = true;
    } else {
        sfSprite_setRotation(ship[i]->ship, 180);
        ship[i]->pos = get_position((rand() % 400) * -1,
        rand() % (size_win.y));
        ship[i]->left = false;
    }
    if (ship[i]->pos.y <= 100) {
        ship[i]->pos.y += 100;
    }
    if (ship[i]->pos.y >= size_win.y - 100) {
        ship[i]->pos.y -= 100;
    }
}

struct ship_t **init_ship(struct game_t *game)
{
    struct ship_t **ship = malloc(game->stat->level * sizeof(struct ship_t *));
    srand(time(NULL));
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    for (int i = 0; i < game->stat->level; i++) {
        ship[i] = malloc(sizeof(struct ship_t));
        ship[i]->ship = set_sprite(sprite_path[TIE], 0.8);
        ship[i]->anim_frame = 0;
        set_ship(ship, i, size_win);
        ship[i]->texture = sfSprite_getTexture(ship[i]->ship);
        sfSprite_setPosition(ship[i]->ship, ship[i]->pos);
        ship[i]->hit = false;
    }
    return ship;
}
