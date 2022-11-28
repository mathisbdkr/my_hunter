/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** main_menu
*/

#include "../include/hunter.h"

int main_menu(struct hunter_t *hunter)
{
    set_game_name(hunter);
    set_play(hunter);set_quit(hunter);
    hunter->pos_play = get_position(450, 450);
    hunter->pos_quit = get_position(750, 450);
    sfEvent event;
    while (sfRenderWindow_isOpen(hunter->window)) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(hunter->window);
        if (main_menu_button(get_position(mouse.x, mouse.y), hunter) == 1)
            return 1;
        if (main_menu_button(get_position(mouse.x, mouse.y), hunter) == 42)
            return 42;
        sfRenderWindow_clear(hunter->window, sfBlack);
        sfRenderWindow_drawSprite(hunter->window, hunter->background, NULL);
        sfRenderWindow_drawSprite(hunter->window, hunter->game_name, NULL);
        sfSprite_setPosition(hunter->play, hunter->pos_play);
        sfRenderWindow_drawSprite(hunter->window, hunter->play, NULL);
        sfSprite_setPosition(hunter->quit, hunter->pos_quit);
        sfRenderWindow_drawSprite(hunter->window, hunter->quit, NULL);
        sfRenderWindow_display(hunter->window);
    }
}
