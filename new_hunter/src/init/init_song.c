/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** init_song
*/

#include "hunter.h"
#include "struct.h"

void init_song(struct game_t *game)
{
    game->song.music = set_music(music[MUSIC_MENU], 100);
    game->song.effect_eplo = set_music(effect[EFFECT_EXPLOSION], 100);
    game->song.effect_fire = set_music(effect[EFFECT_FIRE], 100);
}
