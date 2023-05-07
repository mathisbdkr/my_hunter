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
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        sfRenderWindow_close(game->window);
    }
}

static void mous_pos(struct game_t *game, sfEvent event)
{
    sfVector2u size_win = sfRenderWindow_getSize(game->window);

    game->pos_manette = game->mous_pos;
    game->mous_pos.x += (sfJoystick_getAxisPosition(0, JOYSTICK_LX) / 10);
    game->mous_pos.y += (sfJoystick_getAxisPosition(0, JOYSTICK_LY) / 10);
    if (game->mous_pos.x >= size_win.x)
        game->mous_pos.x -= 10;
    if (game->mous_pos.y >= size_win.y)
        game->mous_pos.y -= 10;
    if (game->mous_pos.x <= 0)
        game->mous_pos.x += 10;
    if (game->mous_pos.y <= 0)
        game->mous_pos.y += 10;
    if (event.type == sfEvtMouseMoved) {
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
    game->song->music = set_music(music[MUSIC_MENU], game->song->volum_music);
    sfMusic_play(game->song->music);
    sfMusic_setLoop(game->song->music, sfTrue);
    loop_game(game);
    return 0;
}
