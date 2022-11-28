/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** menu_game_over
*/

#include "../include/hunter.h"

int action_over(sfVector2f mouse_pos, struct hunter_t *hunter)
{
    if (mouse_pos.x <= hunter->pos_retry.x + 198 &&
    mouse_pos.x >= hunter->pos_retry.x &&
    mouse_pos.y <= hunter->pos_retry.y + 92 &&
    mouse_pos.y >= hunter->pos_retry.y) {
        return 1;
    }
    if (mouse_pos.x <= hunter->pos_quit.x + 198 &&
    mouse_pos.x >= hunter->pos_quit.x &&
    mouse_pos.y <= hunter->pos_quit.y + 92 &&
    mouse_pos.y >= hunter->pos_quit.y) {
        return 42;
    }
}

int menu_game_over(sfVector2f mouse_pos, struct hunter_t *hunter)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        return 42;
    sfEvent event;
    sfRenderWindow_pollEvent(hunter->window, &event);
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(hunter->window);
        return 42;
    }
    if (event.type == sfEvtMouseButtonPressed) {
        if (action_over(mouse_pos, hunter) == 42)
            return 42;
        if (action_over(mouse_pos, hunter) == 1) {
            hunter->score = 0;
            hunter->vie = 3;
            return 1;
        }
    }
}
