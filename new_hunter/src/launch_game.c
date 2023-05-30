/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** launch_game
*/

#include "hunter.h"
#include "struct.h"

static void exit_game(struct game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(game->window);
    }
    if ((sfKeyboard_isKeyPressed(sfKeyEscape) && game->menu == 1) ||
    (sfJoystick_isButtonPressed(0, KEY_BACK) && game->menu == 1)) {
        game->is_pause = true;
    }
}

static void controler_pos(struct game_t *game, sfEvent event)
{
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    int x = sfJoystick_getAxisPosition(0, JOYSTICK_LX) / game->settings.sensibility;
    int y = sfJoystick_getAxisPosition(0, JOYSTICK_LY) / game->settings.sensibility;
    int limite = 10 - game->settings.sensibility;
    if (x >= limite || x <= -limite)
        game->pos_manette.x += x;
    if (y >= limite || y <= -limite)
        game->pos_manette.y += y;
    if (game->pos_manette.x >= size_win.x)
        game->pos_manette.x -= x * 2;
    if (game->pos_manette.y >= size_win.y)
        game->pos_manette.y -= y * 2;
    if (game->pos_manette.x <= 0)
        game->pos_manette.x -= x * 2;
    if (game->pos_manette.y <= 0)
        game->pos_manette.y -= y * 2;
    game->mous_pos = game->pos_manette;
}

static void mous_pos(struct game_t *game, sfEvent event)
{
    if (sfJoystick_isConnected(0)) {
        controler_pos(game, event);
    } else {
        sfVector2i tmp = sfMouse_getPositionRenderWindow(game->window);
        game->mous_pos =
        sfRenderWindow_mapPixelToCoords(game->window, tmp, NULL);
    }
}

static void loop_game(struct game_t *game)
{
    sfEvent event;
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_pollEvent(game->window, &event);
        mous_pos(game, event);
        game->event = event;
        sfRenderWindow_clear(game->window, sfBlack);
        menu_selector(game);
        sfRenderWindow_display(game->window);
        exit_game(game, event);
    }
}

int launch_game(void)
{
    struct game_t *game = init_game();
    game->song.music = set_music(music[MUSIC_MENU], game->settings.volum_music);
    sfMusic_play(game->song.music);
    sfMusic_setLoop(game->song.music, sfTrue);
    loop_game(game);
    save_settings(game);
    return 0;
}
