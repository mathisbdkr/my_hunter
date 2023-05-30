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
    for (int i = 0; i < game->stat->nb_ennemy; i++) {
        if (game->ship[i]->hit == false) {
            return;
        }
    }
    for (int i = 0; i < game->stat->nb_ennemy; i++) {
        free(game->ship[i]);
    }
    free(game->ship);
    game->stat->level += 1;
    game->stat->nb_ennemy = game->stat->level;
    game->ship = init_ship(game);
}

static void display_life(struct game_t *game)
{
    sfSprite_setTextureRect(game->sprite[HEART]->sprite, anim_life(game));
    sfRenderWindow_drawSprite(game->window, game->sprite[HEART]->sprite, 0);
    if (game->stat->life <= 0) {
        game->menu = 2;
        sfMusic_stop(game->song.music);
        sfMusic_destroy(game->song.music);
        game->song.music = set_music(music[MUSIC_MENU],
        game->settings.volum_music);
        sfMusic_play(game->song.music);
        sfMusic_setLoop(game->song.music, sfTrue);
        game->stat->life = 3;
        game->stat->level = 1;
        game->stat->nb_ennemy = 1;
    }
}

static void explosion(struct game_t *game)
{
    for (int i = 0; i < game->stat->nb_ennemy; i++) {
        if (game->ship[i]->hit == false || game->ship[i]->anim_frame < 0)
            continue;
        if (game->ship[i]->anim_revers == -1) {
            game->ship[i]->pos.y -= 110;
            game->ship[i]->anim_revers = 0;
            game->ship[i]->pos.x -= 668 / 5;
            sfSprite_setScale(game->ship[i]->explo, resize[0]);
            sfSprite_setPosition(game->ship[i]->explo, game->ship[i]->pos);
        }
        if (game->ship[i]->anim_frame >= 15)
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
    if (!game->is_pause)
        game->ship[i]->anim_frame += 1;
    if (game->stat->is_bosse == false)
        sfSprite_setTextureRect(game->ship[i]->ship, anim_ship(game, i));
    if (!game->is_pause) {
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

static void display_bosse_hit(struct game_t *game)
{
    char *txt = "bosse life : \0";
    char *test = my_getchar((game->stat->level * 1.5) - game->ship[0]->boss_nb_hit);
    txt = my_strcat(txt, test);
    sfText *sftxt = made_txt(txt, get_position(1200, 0),
    get_position(1.5, 1.5), game->starjhol);
    sfRenderWindow_drawText(game->window, sftxt, 0);
    sfText_destroy(sftxt);
}

void is_a_bosse(struct game_t *game)
{
    if (game->stat->level % NB_LEVEL_FOR_BOSSE == 0) {
        game->stat->nb_ennemy = 1;
        game->stat->is_bosse = true;
    } else if (game->stat->is_bosse) {
        game->stat->is_bosse = false;
        game->stat->nb_ennemy = game->stat->level;
    }
    if (game->stat->is_bosse == true) {
        display_bosse_hit(game);
    }
}

void game_main(struct game_t *game)
{
    sfClock* clock = sfClock_create();
    sfTime time;
    float deltaTime = 0;
    is_a_bosse(game);
    while (deltaTime < 0.02) {
        time = sfClock_getElapsedTime(clock);
        deltaTime = sfTime_asSeconds(time);
    }
    sfClock_restart(clock);
    for (int i = 0; i < game->stat->nb_ennemy; i++) {
        loop_ship_move(game, i);
    }
    if (!game->is_pause) {
        explosion(game);
        round_end(game);
    }
    display_life(game);
    display_lvl(game);
    display_score(game);
    display_pause(game);
    if (game->is_pause)
        menu_pause(game);
}
