/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** song_manager
*/

#include "hunter.h"
#include "struct.h"

void song_manager(struct game_t *game)
{
    sfVector2f pos = get_position(300, 100);
    sfVector2f size = get_position(1.5, 1.5);
    sfRenderWindow_drawText(game->window, made_txt("song",
    pos, size, game->starjhol), NULL);
    size = get_position(1, 1);
    pos.x = 50;
    for (int i = 1; i < NB_SONG_TXT; i++) {
        pos.y += 100;
        sfRenderWindow_drawText(game->window, made_txt(volume_txt[i],
        pos, size, game->starjhol), NULL);
    }
    pos = get_position(50, 200);
    for (int i = 0; i < 2; i++) {
        volume_bare(game);
    }
}
