/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** shout
*/

#include "../include/hunter.h"

int shout(sfVector2f mouse_pos, sfVector2f bird_pos, struct hunter_t *hunter, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        exit(0);
    sfRenderWindow *window = hunter->window;
    sfRenderWindow_pollEvent(window, &event);
    if (event.type == sfEvtMouseButtonPressed) {
        if (mouse_pos.x <= bird_pos.x + 134 &&
		mouse_pos.x >= bird_pos.x &&
        mouse_pos.y <= bird_pos.y + hunter->haut &&
		mouse_pos.y >= bird_pos.y) {
            hunter->score += 1;
            return 1;
        }
        hunter->vie -= 1;
        return 0;
    }
    return 0;
}
