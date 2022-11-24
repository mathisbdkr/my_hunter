/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** main
*/

#include "../include/hunter.h"

sfIntRect get_rect(int top, int left, int width, int height)
{
	sfIntRect rect;
	rect.top = top;
	rect.left = left;
	rect.width = width;
	rect.height = height;
	return (rect);
}

int run_window(struct hunter_t *hunter)
{
	sfEvent event;
	sfRenderWindow_drawSprite(hunter->window, hunter->background, NULL);
	while (sfRenderWindow_isOpen(hunter->window)) {
		display_bird(hunter, event);
		if (hunter->vie == 0) {
			sfRenderWindow_close(hunter->window);
			return 1;
		}
	}
}

int main(int ac, char **av)
{
	int redirect = 0;
	struct hunter_t *hunter = malloc(sizeof(struct hunter_t));
	hunter->score = 0;
	hunter->vie = 1;
	if (ac == 2 && (av[1][0] == '-' || av[1][1] == 'h')) {
		my_putstr("shoot the TIE fighter \n");
		my_putstr("exit with escape key \n");
		my_putstr("enjoy\n");
		return (0);
	}
	sfVideoMode mode = { 1366, 716, 32 };
	sfRenderWindow* window = sfRenderWindow_create(mode, "my hunter",
		sfTitlebar | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(window, 60);
	sfRenderWindow_setMouseCursorVisible(window, sfFalse);
	set_background(hunter);
	hunter->window = window;
	if (redirect == 0)
		redirect = run_window(hunter);
	if (redirect == 1)
		redirect = window_end(hunter);
	return (0);
}

