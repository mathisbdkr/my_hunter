/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** init_sprite
*/

#include "hunter.h"
#include "struct.h"

static void change_origin(struct game_sprite_t **sprite, int nb_sprite)
{
    const sfTexture *texture = sfSprite_getTexture(sprite[nb_sprite]->sprite);
    sfVector2u size = sfTexture_getSize(texture);
    sfSprite_setOrigin(sprite[nb_sprite]->sprite,
    get_position(size.x / 2, size.y / 2));
    sfSprite_setScale(sprite[nb_sprite]->sprite, get_position(1, 1));
}

struct game_sprite_t **init_game_sprite(struct game_t *game)
{
    struct game_sprite_t **game_sprite =
    malloc(NB_SPRITE * sizeof(struct game_sprite_t *));
    for (int i = 0; i < NB_SPRITE; i++) {
        game_sprite[i] = malloc(sizeof(struct game_sprite_t));
        game_sprite[i]->sprite = set_sprite(sprite_path[i], 1);
        sfSprite_setScale(game_sprite[i]->sprite, resize[0]);
    }
    change_origin(game_sprite, SCOPE);
    change_origin(game_sprite, TIE);
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    sfVector2f pos = get_position(size_win.x - 100, 0);
    sfSprite_setPosition(game_sprite[PAUSE]->sprite, pos);
    pos = get_position(795, 840);
    sfSprite_setPosition(game_sprite[SETTINGS]->sprite, pos);
    return game_sprite;
}
