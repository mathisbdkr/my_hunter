/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** menu_game_over
*/

#include "../include/hunter.h"

int menu_game_over(sfVector2f mouse_pos, struct hunter_t *hunter)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        exit(0);
    sfEvent event;
    sfRenderWindow *window = hunter->window;
    sfRenderWindow_pollEvent(window, &event);
    if (event.type == sfEvtMouseButtonPressed) {
        if (mouse_pos.x <= hunter->pos_retry.x + 198 &&
		mouse_pos.x >= hunter->pos_retry.x &&
        mouse_pos.y <= hunter->pos_retry.y + 92 &&
		mouse_pos.y >= hunter->pos_retry.y) {
            sfRenderWindow_close(hunter->window);
            char **av;
            av[1] = "my_hunter";
            main(1, av);
        }
        if (mouse_pos.x <= hunter->pos_quit.x + 198 &&
		mouse_pos.x >= hunter->pos_quit.x &&
        mouse_pos.y <= hunter->pos_quit.y + 92 &&
		mouse_pos.y >= hunter->pos_quit.y) {
            exit(0);
        }
    }
    return 0;
}