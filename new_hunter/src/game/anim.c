/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** anim
*/

#include "hunter.h"
#include "struct.h"

sfIntRect get_rect(int top, int left, int width, int height)
{
    sfIntRect rect;
    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

sfIntRect anim_ship(struct game_t *game, int i)
{
    sfIntRect rect;
    int frame = game->ship[i]->anim_frame;
    sfVector2u size = sfTexture_getSize(game->ship[i]->texture);
    if (frame >= 0 && frame < 10) {
        rect = get_rect(0, 0, size.x / 3, size.y);
    }
    if (frame >= 10 && frame < 20) {
        rect = get_rect(0, size.x / 3, size.x / 3, size.y);
    }
    if (frame >= 20 && frame <= 31) {
        rect = get_rect(0, size.x / 3 * 2, size.x / 3, size.y);
    }
    if (game->ship[i]->anim_frame >= 31) {
        game->ship[i]->anim_frame = 0;
    }
    return rect;
}

sfIntRect anim_life(struct game_t *game)
{
    sfIntRect rect;
    if (game->stat->life == 3) {
        rect = get_rect(0, 0 , 144 / 1, 100);
    }
    if (game->stat->life == 2) {
        rect = get_rect(0, 144 / 3, 144 / 1, 100);
    }
    if (game->stat->life == 1) {
        rect = get_rect(0, 144 / 3 * 2, 144 / 3, 100);
    }
    return rect;
}

sfIntRect anim_explo(struct game_t *game, int index)
{
    sfIntRect rect;
    int i = game->ship[index]->anim_frame;
    if (i >= 0 && i < 3) {
        rect = get_rect(0, 0, 668 / 5, 110);
    }
    if (i >= 3 && i < 6) {
        rect = get_rect(0, 668 / 5, 668 / 5, 110);
    }
    if (i >= 6 && i < 9) {
        rect = get_rect(0, 668 / 5 * 2, 668 / 5, 110);
    }
    if (i >= 9 && i < 12) {
        rect = get_rect(0, 668 / 5 * 3, 668 / 5, 110);
    }
    if (i >= 12 && i < 15) {
        rect = get_rect(0, 668 / 5 * 4, 668 / 5, 110);
    }
    return rect;
}
