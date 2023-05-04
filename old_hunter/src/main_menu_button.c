/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** main_menu_button
*/

#include "../include/hunter.h"

int action(sfVector2f mouse_pos, struct hunter_t *hunter)
{
    if (mouse_pos.x <= hunter->pos_play.x + 56 &&
    mouse_pos.x >= hunter->pos_play.x &&
    mouse_pos.y <= hunter->pos_play.y + 66 &&
    mouse_pos.y >= hunter->pos_play.y) {
        return 1;
    }
    if (mouse_pos.x <= hunter->pos_quit.x + 55 &&
    mouse_pos.x >= hunter->pos_quit.x &&
    mouse_pos.y <= hunter->pos_quit.y + 70 &&
    mouse_pos.y >= hunter->pos_quit.y) {
        return 42;
    }
}

int main_menu_button(sfVector2f mouse_pos, struct hunter_t *hunter)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        return 42;
    sfEvent event;
    sfRenderWindow *window = hunter->window;
    sfRenderWindow_pollEvent(window, &event);
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(hunter->window);
        return 42;
    }
    if (event.type == sfEvtMouseButtonPressed) {
        if (action(mouse_pos, hunter) == 42)
            return 42;
        if (action(mouse_pos, hunter) == 1)
            return 1;
    }
    return 0;
}
