/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** game_over
*/

#include "../include/hunter.h"

int window_end(struct hunter_t *hunter)
{
    sfVideoMode mode = { 1366, 716, 3 };
	sfRenderWindow* window = sfRenderWindow_create(mode, "my hunter game over", sfTitlebar | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    hunter->window = window;
    set_game_over(hunter);
    set_retry(hunter);
    set_quit(hunter);
    hunter->pos_retry = get_position(450, 450);
    hunter->pos_quit = get_position(750, 450);
    sfEvent event;
	while (sfRenderWindow_isOpen(window)) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(hunter->window);
        menu_game_over(get_position(mouse.x, mouse.y), hunter);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            exit(0);
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, hunter->background, NULL);
        sfRenderWindow_drawSprite(window, hunter->game_over, NULL);
        sfSprite_setPosition(hunter->retry, hunter->pos_retry);
        sfRenderWindow_drawSprite(window, hunter->retry, NULL);
        sfSprite_setPosition(hunter->quit, hunter->pos_quit);
        sfRenderWindow_drawSprite(window, hunter->quit, NULL);
		sfRenderWindow_display(window);
	}
}
