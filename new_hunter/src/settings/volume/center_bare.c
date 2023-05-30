/*
** EPITECH PROJECT, 2023
** test
** File description:
** center_bare
*/

#include "hunter.h"
#include "struct.h"

void center_bare(struct game_t *game, sfVector2f pos)
{
    pos.y += 18;
    sfVector2f size = get_position(200, 4);
    sfColor color = sfColor_fromRGB(255, 195, 30);
    sfRectangleShape *bare = made_button(size, pos, color);
    sfRenderWindow_drawRectangleShape(game->window, bare, 0);
}
