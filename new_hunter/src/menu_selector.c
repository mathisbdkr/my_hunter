/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** menu_selector
*/

#include "hunter.h"
#include "struct.h"

static void menu_selector_pt2(struct game_t *game)
{
    if (game->menu == 2 && !game->is_settings) {
        game_over_main(game);
    }
    if (game->is_settings) {
        display_settings(game);
    }
}

void menu_selector(struct game_t *game)
{
    if (game->menu == 1 || !game->is_settings)
        sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    else
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    if (game->menu == 0 && !game->is_settings) {
        sfRenderWindow_drawSprite(game->window,
        game->sprite[BACK_MENU]->sprite, 0);
        sfRenderWindow_drawSprite(game->window,
        game->sprite[COCKPIT]->sprite, 0);
        main_menu(game);
    }
    if (game->menu == 1 && !game->is_settings) {
        sfRenderWindow_drawSprite(game->window, game->sprite[BACK]->sprite, 0);
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        sfSprite_setPosition(game->sprite[SCOPE]->sprite, game->mous_pos);
        game_main(game);
        sfRenderWindow_drawSprite(game->window, game->sprite[SCOPE]->sprite, 0);
    }
    menu_selector_pt2(game);
}
