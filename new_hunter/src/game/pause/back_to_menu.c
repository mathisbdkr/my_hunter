/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** back_to_menu
*/

#include "hunter.h"
#include "struct.h"

void back_to_menu(struct game_t *game)
{
    game->menu = 0;
    sfMusic_stop(game->song->music);
    game->song->music = set_music(music[1], game->song->volum_music);
    sfMusic_play(game->song->music);
    sfMusic_setLoop(game->song->music, sfTrue);
    game->settings = false;
    game->stat->level = 0;
    game->stat->life = 3;
    game->stat->score = 0;
}
