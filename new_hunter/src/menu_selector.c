/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** menu_selector
*/

#include "hunter.h"
#include "struct.h"

void menu_selector(struct game_t *game)
{
    if (game->menu == 0) {
        sfRenderWindow_drawSprite(game->window,
        game->sprite[BACK_MENU]->sprite, 0);
        sfRenderWindow_drawSprite(game->window,
        game->sprite[COCKPIT]->sprite, 0);
        sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
        main_menu(game);
    }
    if (game->menu == 1) {
        sfRenderWindow_drawSprite(game->window, game->sprite[BACK]->sprite, 0);
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        sfSprite_setPosition(game->sprite[SCOPE]->sprite, game->mous_pos);
        game_main(game);
        sfRenderWindow_drawSprite(game->window, game->sprite[SCOPE]->sprite, 0);
    }
    if (game->menu == 2) {
        sfRenderWindow_drawSprite(game->window,
        game->sprite[BACK_MENU]->sprite, 0);
        sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    }
}
