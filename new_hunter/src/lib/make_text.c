/*
** EPITECH PROJECT, 2023
** test
** File description:
** make_text
*/

#include "hunter.h"

sfText *made_txt(char *text, sfVector2f pos, sfVector2f size, sfFont *font)
{
    sfText *txt = sfText_create();
    sfText_setFont(txt, font);
    sfText_setScale(txt, size);
    sfText_setColor(txt, sfColor_fromRGB(255, 195, 30));
    sfText_setPosition(txt, pos);
    sfText_setString(txt, text);
    return txt;
}
