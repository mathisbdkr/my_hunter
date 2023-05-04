/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** main_menu
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

void main_menu_two(struct hunter_t *hunter)
{
    sfRenderWindow_clear(hunter->window, sfBlack);
    sfRenderWindow_drawSprite(hunter->window, hunter->background, NULL);
    sfRenderWindow_drawSprite(hunter->window, hunter->star->cockpit, NULL);
    sfRenderWindow_drawSprite(hunter->window, hunter->game_name, NULL);
    sfSprite_setPosition(hunter->play, hunter->pos_play);
    sfRenderWindow_drawSprite(hunter->window, hunter->play, NULL);
    sfSprite_setPosition(hunter->star->quit, hunter->pos_quit);
    sfRenderWindow_drawSprite(hunter->window, hunter->star->quit, NULL);
    sfRenderWindow_display(hunter->window);
}

int main_menu(struct hunter_t *hunter)
{
    float i = 1;
    set_game_name(hunter);set_cockpit(hunter);
    set_play(hunter);set_quit(hunter);
    hunter->pos_play = get_position(660, 450);
    hunter->pos_quit = get_position(750, 450);
    sfVector2f pos_name = sfSprite_getPosition(hunter->game_name);
    pos_name.y -= 70;
    sfSprite_setPosition(hunter->game_name, pos_name);
    sfEvent event;
    sfVector2f pos = sfSprite_getScale(hunter->background);
    sfSprite_setOrigin(hunter->background, get_position(683,358));
    sfSprite_setPosition(hunter->background, get_position(683,358));
    while (sfRenderWindow_isOpen(hunter->window)) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(hunter->window);
        if (main_menu_button(get_position(mouse.x, mouse.y), hunter) == 1)
            return 1;
        if (main_menu_button(get_position(mouse.x, mouse.y), hunter) == 42)
            return 42;
        main_menu_two(hunter);
    }
}
