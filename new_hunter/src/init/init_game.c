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
    if (texture == NULL)
        exit(EXIT_FAILURE);
    sfVector2f scale = get_position(size, size);

    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

struct stat_t *init_stat(void)
{
    struct stat_t *stat = malloc(sizeof(struct stat_t));
    stat->level = 1;
    stat->life = 3;
    stat->score = 0;
    stat->is_bosse = false;
    stat->nb_ennemy = 1;
    return stat;
}

static void init_game_variables(struct game_t *game)
{
    game->menu = 0;
    game->starjhol = sfFont_createFromFile("./assets/font/Starjhol2.ttf");
    if (game->starjhol == NULL)
        exit(EXIT_FAILURE);
    game->is_pause = false;
    game->pos_manette = get_position(100, 100);
    game->dificulty = HARD;
    game->is_settings = false;
    game->settings.size_select = 0;
    game->settings.fps_select = 2;
    game->settings.sensibility = 1;
    game->mous_pos = get_position(0, 0);
    sfVideoMode mode = { 1910, 1020, 32 };
    game->window = sfRenderWindow_create(mode,
        "hunter", sfClose | sfResize,  NULL);
    sfRenderWindow_setFramerateLimit(game->window, 90);
}

struct game_t *init_game(void)
{
    struct game_t *game = malloc(sizeof(struct game_t));
    init_game_variables(game);
    game->sprite = init_game_sprite(game);
    game->stat = init_stat();
    game->ship = init_ship(game);
    init_song(game);
    init_settings(game);
    return game;
}
