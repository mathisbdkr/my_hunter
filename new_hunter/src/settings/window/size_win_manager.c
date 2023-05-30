/*
** EPITECH PROJECT, 2023
** test
** File description:
** size_win_manager
*/

#include "hunter.h"
#include "struct.h"

static void make_fullscreen(struct game_t *game)
{
    if (game->settings.size_select == 0) {
        if (game->settings.is_fullscreen == 0) {
            sfRenderWindow_close(game->window);
            sfRenderWindow_destroy(game->window);
            sfVideoMode mode = { 1920, 1080 , 32 };
            game->window = sfRenderWindow_create(mode, "my rpg",
            sfFullscreen, NULL);
            game->settings.is_fullscreen = 1;
        }
    } else if (game->settings.is_fullscreen == 1) {
        sfRenderWindow_close(game->window);
        sfRenderWindow_destroy(game->window);
        sfVideoMode mode = { 1910, 1020 , 32 };
        game->window = sfRenderWindow_create(mode, "my rpg",
        sfResize | sfClose, NULL);
        game->settings.is_fullscreen = 0;
    }
}

void change_win_size(struct game_t *game)
{
    make_fullscreen(game);
    if (game->settings.size_select == 1)
        sfRenderWindow_setSize(game->window, (sfVector2u){1920, 1029});
    if (game->settings.size_select == 2)
        sfRenderWindow_setSize(game->window, (sfVector2u){1366, 716});
}

sfRectangleShape *butt_pressed(sfVector2f size, sfVector2f pos,
    struct game_t *game, int i)
{
    sfColor color = sfColor_fromRGBA(255, 255, 255, 100);
    sfRectangleShape *button = made_button(size, pos, color);
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(button);
    sfVector2f mouse = game->mous_pos;
    bool button_pressed = sfMouse_isButtonPressed(0);
    if (sfJoystick_isConnected(0)) {
        if (sfJoystick_isButtonPressed(0, KEY_A)) {
            button_pressed = true;
        }
    }
    if ((sfFloatRect_contains(&bound,mouse.x, mouse.y) && button_pressed) ||
    i == game->settings.size_select) {
        sfRectangleShape_setFillColor(button, sfColor_fromRGBA(0,255,100,100));
        game->settings.size_select = i;
        change_win_size(game);
        return button;
    }
    if (i == game->settings.size_select)
        sfRectangleShape_setFillColor(button, sfColor_fromRGBA(0,255,100,100));
    if (sfFloatRect_contains(&bound,mouse.x, mouse.y)) {
        color.a += 100;
        sfRectangleShape_setFillColor(button, color);
    }
    return button;
}

static void button_set(struct game_t *game, sfVector2f pos)
{
    sfRectangleShape *button;
    sfVector2f size = get_position(180, 50);
    pos.y -= 10;
    pos.x -= 10;
    for (int i = 0; i < 3; i++) {
        button = butt_pressed(size, pos, game, i);
        sfRenderWindow_drawRectangleShape(game->window, button, NULL);
        sfRectangleShape_destroy(button);
        pos.x += 200;
    }
}

void size_win_manager(struct game_t *game)
{
    sfVector2f pos = get_position(700, 450);
    sfVector2f size = get_position(0.7, 0.7);
    button_set(game, pos);
    sfRenderWindow_drawText(game->window,
    made_txt("Full screen", pos, size, game->starjhol), 0);
    pos.x += 200;
    size = get_position(0.8, 0.8);
    sfRenderWindow_drawText(game->window,
    made_txt("1920 x 1080", pos, size, game->starjhol), 0);
    pos.x += 200;
    sfRenderWindow_drawText(game->window,
    made_txt("1366 x 716", pos, size, game->starjhol), 0);
    sfText *win_select = made_txt("window size",
    get_position(750, 350), get_position(2, 2), game->starjhol);
    sfRenderWindow_drawText(game->window, win_select, 0);
}
