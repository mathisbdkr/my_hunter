/*
** EPITECH PROJECT, 2023
** test
** File description:
** curseur_bare
*/

#include "hunter.h"
#include "struct.h"

static void set_volume(struct game_t *game)
{
    sfMusic_setVolume(game->song.music, game->settings.volum_music);
    sfMusic_setVolume(game->song.effect_eplo, game->settings.volum_effect);
    sfMusic_setVolume(game->song.effect_fire, game->settings.volum_effect);
}

static void change_volume(struct game_t *game, sfVector2f pos, int i)
{
    sfVector2f mouse = game->mous_pos;
    bool button_pressed = sfMouse_isButtonPressed(0);

    if (sfJoystick_isConnected(0)) {
        if (sfJoystick_isButtonPressed(0, KEY_A)) {
            button_pressed = true;
        }
    }
    if (mouse.x <= pos.x + 200 && mouse.x >= pos.x && mouse.y <= pos.y + 35 &&
    mouse.y >= pos.y - 10 && button_pressed && i == 0) {
        game->settings.volum_general = (mouse.x - pos.x) / 2;
    }
    if (mouse.x <= pos.x + 200 && mouse.x >= pos.x && mouse.y <= pos.y + 35 &&
    mouse.y >= pos.y - 10 && button_pressed && i == 1) {
        game->settings.volum_music = (mouse.x - pos.x) / 2;
    }
    if (mouse.x <= pos.x + 200 && mouse.x >= pos.x && mouse.y <= pos.y + 35 &&
    mouse.y >= pos.y - 10 && button_pressed && i == 2) {
        game->settings.volum_effect = (mouse.x - pos.x) / 2;
    }
    set_volume(game);
}

static sfVector2f pos_curseur(struct game_t *game, sfVector2f pos, int i)
{
    if (i == 0) {
        pos.x += game->settings.volum_general * 2;
    }
    if (i == 1) {
        pos.x += game->settings.volum_music * 2;
    }
    if (i == 2) {
        pos.x += game->settings.volum_effect * 2;
    }
    return pos;
}

static void aligne_volume(struct game_t *game)
{
    if (game->settings.volum_general < game->settings.volum_music)
        game->settings.volum_music = game->settings.volum_general;
    if (game->settings.volum_general < game->settings.volum_effect)
        game->settings.volum_effect = game->settings.volum_general;
}

void curseur_bare(struct game_t *game, sfVector2f pos, int i)
{
    pos.y += 9;
    sfVector2f size = get_position(4, 20);
    sfColor color = sfColor_fromRGB(255, 195, 30);
    change_volume(game, pos, i);
    aligne_volume(game);
    pos = pos_curseur(game, pos, i);
    sfRectangleShape *bare = made_button(size, pos, color);
    sfRenderWindow_drawRectangleShape(game->window, bare, 0);
    sfRectangleShape_destroy(bare);
}
