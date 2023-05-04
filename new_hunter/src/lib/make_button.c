/*
** EPITECH PROJECT, 2023
** test
** File description:
** make_button
*/

#include "hunter.h"

sfRectangleShape *made_button(sfVector2f size, sfVector2f pos, sfColor color)
{
    sfRectangleShape *button = sfRectangleShape_create();
    sfRectangleShape_setSize(button, size);
    sfRectangleShape_setPosition(button, pos);
    sfRectangleShape_setFillColor(button, color);
    sfRectangleShape_setOutlineThickness(button, 1);
    sfRectangleShape_setOutlineColor(button, sfColor_fromRGB(255, 195, 30));
    return button;
}
