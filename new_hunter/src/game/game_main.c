/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** game_main
*/

#include "hunter.h"
#include "struct.h"

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
        sfMusic_stop(game->song->music);
        sfMusic_destroy(game->song->music);
        game->song->music = set_music(music[MUSIC_MENU],
        game->song->volum_music);
        sfMusic_play(game->song->music);
        sfMusic_setLoop(game->song->music, sfTrue);
        game->stat->life = 3;
        game->stat->level = 1;
    }
}

static void explosion(struct game_t *game)
{
    for (int i = 0; i < game->stat->level; i++) {
        if (game->ship[i]->hit == false || game->ship[i]->anim_frame < 0)
            continue;
        if (game->ship[i]->anim_revers == -1) {
            game->ship[i]->pos.y -= 110;
            game->ship[i]->anim_revers = 0;
            game->ship[i]->pos.x -= 668 / 5;
            sfSprite_setScale(game->ship[i]->explo, resize[0]);
            sfSprite_setPosition(game->ship[i]->explo, game->ship[i]->pos);
        }
        if (game->ship[i]->anim_frame >= 25)
            game->ship[i]->anim_revers = 1;
        if (game->ship[i]->anim_revers == 0)
            game->ship[i]->anim_frame += 1;
        if (game->ship[i]->anim_revers == 1)
            game->ship[i]->anim_frame -= 1;
        sfSprite_setTextureRect(game->ship[i]->explo, anim_explo(game, i));
        sfRenderWindow_drawSprite(game->window, game->ship[i]->explo, 0);
    }
}

static void loop_ship_move(struct game_t *game, int i)
{
    if (game->ship[i]->hit)
        return;
    if (!game->settings)
        game->ship[i]->anim_frame += 1;
    sfSprite_setTextureRect(game->ship[i]->ship, anim_ship(game, i));
    if (!game->settings) {
        hit_ship(game->ship[i]->ship, game, i);
        if (game->ship[i]->left == true) {
            game->ship[i]->pos.x -= game->dificulty;
        } else {
            game->ship[i]->pos.x += game->dificulty;
        }
    }
    sfSprite_setPosition(game->ship[i]->ship, game->ship[i]->pos);
    sfRenderWindow_drawSprite(game->window, game->ship[i]->ship, 0);
}

void game_main(struct game_t *game)
{
    for (int i = 0; i < game->stat->level; i++) {
        loop_ship_move(game, i);
    }
    if (!game->settings) {
        explosion(game);
        round_end(game);
    }
    display_life(game);
    display_lvl(game);
    display_score(game);
    display_settings(game);
    if (game->settings)
        menu_pause(game);
}
