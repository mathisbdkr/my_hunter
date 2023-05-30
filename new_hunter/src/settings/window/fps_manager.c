/*
** EPITECH PROJECT, 2023
** test
** File description:
** fps_manager
*/

#include "hunter.h"
#include "struct.h"

void change_fps(struct game_t *game)
{
    sfRenderWindow_setFramerateLimit(game->window,
    fps_select[game->settings.fps_select]);
}

sfRectangleShape *button_pressed(sfVector2f size, sfVector2f pos,
    struct game_t *game, int i)
{
    sfRectangleShape *button;
    sfColor color = sfColor_fromRGBA(255, 255, 255, 100);
    button = made_button(size, pos, color);
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(button);
    if ((sfFloatRect_contains(&bound,game->mous_pos.x, game->mous_pos.y) &&
    sfMouse_isButtonPressed(0)) || i == game->settings.fps_select ||
    (sfFloatRect_contains(&bound, game->pos_manette.x, game->pos_manette.y)
    && sfJoystick_isButtonPressed(0, KEY_A))) {
        sfRectangleShape_setFillColor(button, sfColor_fromRGBA(0,255,100,100));
        game->settings.fps_select = i;
        change_fps(game);
        return button;
    }
    if (i == game->settings.fps_select)
        sfRectangleShape_setFillColor(button, sfColor_fromRGBA(0,255,100,100));
    if (sfFloatRect_contains(&bound,game->mous_pos.x, game->mous_pos.y)) {
        color.a += 100;
        sfRectangleShape_setFillColor(button, color);
    }
    return button;
}

void set_button(sfVector2f size, sfVector2f pos, struct game_t *game)
{
    sfRectangleShape *button;
    size = get_position(100, 50);
    pos = get_position(pos.x - 90, pos.y + 60);

    for (int i = 0; i < 3; i++) {
        button = button_pressed(size, pos, game, i);
        sfRenderWindow_drawRectangleShape(game->window, button, NULL);
        sfRectangleShape_destroy(button);
        pos.x += 125;
    }
    pos.y += 5;
    pos.x -= 348;
    size = get_position(1, 1);
    for (int i = 0; i < NB_TXT_FPS; i++) {
        sfRenderWindow_drawText(game->window,
        made_txt(fps_txt[i], pos, size, game->starjhol), 0);
        pos.x += 125;
    }
}

void fps_manager(struct game_t *game)
{
    sfVector2f pos = get_position(200, 550);
    sfVector2f size = get_position(1, 1);
    sfRenderWindow_drawText(game->window, made_txt("    fps", pos,
    size, game->starjhol), NULL);
    set_button(size, pos, game);
}
