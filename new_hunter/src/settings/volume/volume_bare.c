/*
** EPITECH PROJECT, 2023
** test
** File description:
** volume_bare
*/

#include "hunter.h"
#include "struct.h"

void volume_bare(struct game_t *game)
{
    sfVector2f pos = get_position(260, 200);
    for (int i = 0; i < 3; i++) {
        create_box(game, pos);
        center_bare(game, pos);
        curseur_bare(game, pos, i);
        pos.y += 100;
    }
}
