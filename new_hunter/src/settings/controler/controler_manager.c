/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** controler_manager
*/

#include "hunter.h"
#include "struct.h"

static void change_sensibility(struct game_t *game, sfVector2f pos)
{
    sfVector2f mouse = game->mous_pos;
    bool button_pressed = sfMouse_isButtonPressed(0);

    if (sfJoystick_isConnected(0)) {
        if (sfJoystick_isButtonPressed(0, KEY_A)) {
            button_pressed = true;
        }
    }
    if (mouse.x <= pos.x + 200 && mouse.x >= pos.x && mouse.y <= pos.y + 35 &&
    mouse.y >= pos.y - 10 && button_pressed) {
        float tmp = (mouse.x - pos.x) / 2;
        game->settings.sensibility = (tmp / 10) + 1;
        game->settings.sensibility = 11 - game->settings.sensibility;
    }
}

static void curseur_bare_controler(struct game_t *game, sfVector2f pos)
{
    pos.y += 9;
    sfVector2f size = get_position(4, 20);
    sfColor color = sfColor_fromRGB(255, 195, 30);
    change_sensibility(game, pos);
    float speed = game->settings.sensibility;
    speed = 11 - speed;
    int tmp = (speed * 20) - 20;
    pos.x += tmp;
    sfRectangleShape *bare = made_button(size, pos, color);
    sfRenderWindow_drawRectangleShape(game->window, bare, 0);
    sfRectangleShape_destroy(bare);
}

void controler_manager(struct game_t *game)
{
    sfVector2f pos = get_position(180, 800);
    create_box(game, pos);
    center_bare(game, pos);
    curseur_bare_controler(game, pos);
}
