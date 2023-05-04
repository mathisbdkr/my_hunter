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

    game->pos_manette.x += (sfJoystick_getAxisPosition(0, JOYSTICK_LX) / 10);
    game->pos_manette.y += (sfJoystick_getAxisPosition(0, JOYSTICK_LY) / 10);
    if (game->pos_manette.x >= size_win.x)
        game->pos_manette.x -= 10;
    if (game->pos_manette.y >= size_win.y)
        game->pos_manette.y -= 10;
    if (game->pos_manette.x <= 0)
        game->pos_manette.x += 10;
    if (game->pos_manette.y <= 0)
        game->pos_manette.y += 10;
    if (event.type == sfEvtMouseMoved) {
        sfVector2i tmp = sfMouse_getPositionRenderWindow(game->window);
        game->mous_pos =
        sfRenderWindow_mapPixelToCoords(game->window, tmp, NULL);
    } else if (event.type == sfEvtJoystickMoved) {
        game->mous_pos = game->pos_manette;
    }
}

static void loop_game(struct game_t *game)
{
    sfEvent event;
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_pollEvent(game->window, &event);
        mous_pos(game, event);
        sfRenderWindow_clear(game->window, sfBlack);
        menu_selector(game);
        sfRenderWindow_display(game->window);
        exit_game(game, event);
    }
}

int launch_game(void)
{
    struct game_t *game = init_game();
    loop_game(game);
    return 0;
}
