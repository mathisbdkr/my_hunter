/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** init_game
*/

#include "hunter.h"
#include "struct.h"

sfSprite *set_sprite(char *path, float size)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfVector2f scale = get_position(size, size);

    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

static void change_scope_origin(struct game_sprite_t **sprite)
{
    const sfTexture *texture = sfSprite_getTexture(sprite[SCOPE]->sprite);
    sfVector2u size = sfTexture_getSize(texture);
    sfSprite_setOrigin(sprite[SCOPE]->sprite,
    get_position(size.x / 2, size.y / 2));
    sfSprite_setScale(sprite[SCOPE]->sprite, get_position(1, 1));
}

struct game_sprite_t **init_game_sprite(void)
{
    struct game_sprite_t **game_sprite =
    malloc(NB_SPRITE * sizeof(struct game_sprite_t *));
    for (int i = 0; i < NB_SPRITE; i++) {
        game_sprite[i] = malloc(sizeof(struct game_sprite_t));
        game_sprite[i]->sprite = set_sprite(sprite_path[i], 1);
        sfSprite_setScale(game_sprite[i]->sprite, resize[0]);
    }
    change_scope_origin(game_sprite);
    return game_sprite;
}

struct stat_t *init_stat(void)
{
    struct stat_t *stat = malloc(sizeof(struct stat_t));
    stat->level = 1;
    stat->life = 3;
    return stat;
}

struct game_t *init_game(void)
{
    struct game_t *game = malloc(sizeof(struct game_t));
    sfVideoMode mode = { 1910, 1020, 32 };
    game->window = sfRenderWindow_create(mode,
        "hunter", sfClose | sfResize,  NULL);
    sfRenderWindow_setFramerateLimit(game->window, 75);
    game->sprite = init_game_sprite();
    game->stat = init_stat();
    game->ship = init_ship(game);
    game->menu = 0;
    game->pos_manette = get_position(100, 100);
    return game;
}
