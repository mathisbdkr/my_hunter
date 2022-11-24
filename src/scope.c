/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** scope
*/

#include "../include/hunter.h"

sfVector2f scope(sfRenderWindow *window, sfSprite *sprite)
{
    sfVector2f pos;
    pos.x = sfEvtMouseMoved;
    //pos.y = pos_mouse.y;
    return pos;
}