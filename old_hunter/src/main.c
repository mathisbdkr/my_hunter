/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** main
*/

#include "../include/hunter.h"

int check(struct hunter_t *hunter, int redirect)
{
    if (sfRenderWindow_isOpen(hunter->window)) {
        return redirect;
    }
    return 42;
}

void help(void)
{
    my_putstr("shoot the TIE fighter and don't let them go\n");
    my_putstr("if you miss you loose a life\n");
    my_putstr("you have 3 life and the goal\n");
    my_putstr("is to DESTROY THE EMPIRE\n");
    my_putstr("\n");
    my_putstr("exit int game with escape key \n");
    my_putstr("enjoy!!!\n");
}

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
    sfMusic_stop(hunter->menu_music);
    sfMusic_play(hunter->game_music);
    sfRenderWindow_drawSprite(hunter->window, hunter->background, NULL);
    while (sfRenderWindow_isOpen(hunter->window)) {
        display_bird(hunter, event, hunter->star);
        if (hunter->vie == 0) {
            sfMusic_stop(hunter->game_music);
            sfMusic_play(hunter->menu_music);
            return 2;
        }
    }
    return 42;
}

int main(int ac, char **av)
{
    int redirect = 0;
    struct star_t *star = malloc(sizeof(struct star_t));
    init_star(star);
    struct hunter_t *hunter = malloc(sizeof(struct hunter_t));
    if (ac == 2 && (av[1][0] == '-' || av[1][1] == 'h')) {
        help();return (0);
    }
    init_struct(hunter);init_struct2(hunter, star);
    sfMusic_play(hunter->menu_music);
    while (redirect != 42) {
        redirect = check(hunter, redirect);
        if (redirect == 0)
            redirect = main_menu(hunter);
        if (redirect == 1)
            redirect = run_window(hunter);
        sfRenderWindow_setMouseCursorVisible(hunter->window, sfTrue);
        if (redirect == 2)
            redirect = vader(hunter);
    }
}
