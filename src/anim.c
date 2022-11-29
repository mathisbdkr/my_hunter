/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** anim
*/

#include "../include/hunter.h"

sfVector2f get_position(int x, int y)
{
    sfVector2f vector;
    vector.x = x;
    vector.y = y;
    return (vector);
}

sfIntRect anim_gd(int i, struct hunter_t *hunter)
{
    sfIntRect rect;
    if (i >= 0 && i < 10) {
        rect = get_rect(0, 402 / 3, 402 / 3 * -1, 110);
    }
    if (i >= 10 && i < 20) {
        rect = get_rect(0, 402 / 3, (402 / 3) * -1, 110);
    }
    if (i >= 20 && i <= 31) {
        rect = get_rect(0, 402 / 3 * 2, (402 / 3) * -1, 110);
    }
    hunter-> haut = 110;
    return rect;
}

sfIntRect anim_dg(int i, struct hunter_t *hunter)
{
    sfIntRect rect;
    if (i >= 0 && i < 10) {
        rect = get_rect(0, 0, 402 / 3, 110);
    }
    if (i >= 10 && i < 20) {
        rect = get_rect(0, 402 / 3, 402 / 3, 110);
    }
    if (i >= 20 && i <= 31) {
        rect = get_rect(0, 402 / 3 * 2, 402 / 3, 110);
    }
    hunter-> haut = 110;
    return rect;
}

sfIntRect anim_coeur(struct hunter_t *hunter)
{
    sfIntRect rect;
    if (hunter->vie == 3) {
        rect = get_rect(0, 0 , 144 / 1, 100);
    }
    if (hunter->vie == 2) {
        rect = get_rect(0, 144 / 3, 144 / 1, 100);
    }
    if (hunter->vie == 1) {
        rect = get_rect(0, 144 / 3 * 2, 144 / 3, 100);
    }
    return rect;
}

sfIntRect set_anim_explosion(int i, struct hunter_t *hunter)
{
    sfIntRect rect;
    if (i >= 0 && i < 4) {
        rect = get_rect(0, 0, 668 / 5, 110);
    }
    if (i >= 4 && i < 8) {
        rect = get_rect(0, 668 / 5, 668 / 5, 110);
    }
    if (i >= 8 && i < 12) {
        rect = get_rect(0, 668 / 5 * 2, 668 / 5, 110);
    }
    if (i >= 12 && i < 16) {
        rect = get_rect(0, 668 / 5 * 3, 668 / 5, 110);
    }
    if (i >= 16 && i < 20) {
        rect = get_rect(0, 668 / 5 * 4, 668 / 5, 110);
    }
    return rect;
}
