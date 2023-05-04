/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** made_round_rect
*/

#include "hunter.h"
#include "struct.h"

static sfCircleShape *made_cercle(sfVector2f pos,
    sfColor color)
{
    sfCircleShape *cercle = sfCircleShape_create();
    sfCircleShape_setPosition(cercle, pos);
    sfCircleShape_setRadius(cercle, 20);
    sfCircleShape_setFillColor(cercle, color);
    return cercle;
}

static void round_right(sfVector2f size, sfVector2f pos, sfColor color,
    sfRenderWindow *window)
{
    sfCircleShape *cercle = made_cercle(
    get_position(pos.x + size.x - 20, pos.y + size.y - 20), color);
    sfRenderWindow_drawCircleShape(window, cercle, 0);

    cercle = made_cercle(
    get_position(pos.x + size.x - 20, pos.y - 20), color);
    sfRenderWindow_drawCircleShape(window, cercle, 0);
    sfCircleShape_destroy(cercle);
}

static void round_left(sfVector2f size, sfVector2f pos, sfColor color,
    sfRenderWindow *window)
{
    sfCircleShape *cercle = made_cercle(
    get_position(pos.x - 20, pos.y + size.y - 20), color);
    sfRenderWindow_drawCircleShape(window, cercle, 0);

    cercle = made_cercle(
    get_position(pos.x - 20, pos.y - 20), color);
    sfRenderWindow_drawCircleShape(window, cercle, 0);
    sfCircleShape_destroy(cercle);
}

void made_rond_rect(sfVector2f size, sfVector2f pos, sfColor color,
    sfRenderWindow *window)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    round_left(size, pos, color, window);
    round_right(size, pos, color, window);
    pos.x -= 20;
    size.x += 40;
    for (int i = 0; i < 2; i += 1) {
        sfRectangleShape_setPosition(rect, pos);
        sfRectangleShape_setSize(rect, size);
        sfRectangleShape_setFillColor(rect, color);
        sfRenderWindow_drawRectangleShape(window, rect, 0);

        pos.y -= 20;
        pos.x += 20;
        size.y += 40;
        size.x -= 40;
    }

    sfRectangleShape_destroy(rect);
}
