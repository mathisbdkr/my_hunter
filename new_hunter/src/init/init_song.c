/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** init_song
*/

#include "hunter.h"
#include "struct.h"

struct song_t *init_song()
{
    struct song_t *song = malloc(sizeof(struct song_t));
    song->volum_music = 100;
    song->volum_effect = 100;
    song->music = set_music(music[MUSIC_MENU], song->volum_music);
    song->effect_eplo = set_music(effect[EFFECT_EXPLOSION], song->volum_effect);
    song->effect_fire = set_music(effect[EFFECT_FIRE], song->volum_effect);
    return song;
}
