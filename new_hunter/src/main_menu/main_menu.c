/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** main_menu
*/

#include "hunter.h"
#include "struct.h"

static void play_quit_action(struct game_t *game)
{
    sfFloatRect play = sfSprite_getGlobalBounds(game->sprite[PLAY]->sprite);
    sfFloatRect quit = sfSprite_getGlobalBounds(game->sprite[QUIT]->sprite);
    if ((sfFloatRect_contains(&play, game->mous_pos.x, game->mous_pos.y)
    && sfMouse_isButtonPressed(0) && game->press == false) ||
    (sfFloatRect_contains(&play, game->pos_manette.x, game->pos_manette.y)
    && sfJoystick_isButtonPressed(0, KEY_A) && game->press == false)) {
        game->menu = 1;
        game->press = true;
    }
    if ((sfFloatRect_contains(&quit, game->mous_pos.x, game->mous_pos.y)
    && sfMouse_isButtonPressed(0) && game->press == false) ||
    (sfFloatRect_contains(&quit, game->pos_manette.x, game->pos_manette.y)
    && sfJoystick_isButtonPressed(0, KEY_A) && game->press == false)) {
        sfRenderWindow_close(game->window);
        game->press = true;
    }
    if (!sfMouse_isButtonPressed(0))
        game->press = false;
}

static void manette(struct game_t *game)
{
    game->pos_manette.x += (sfJoystick_getAxisPosition(0, JOYSTICK_LX) / 10);
    game->pos_manette.y += (sfJoystick_getAxisPosition(0, JOYSTICK_LY) / 10);
    sfSprite_setPosition(game->sprite[SCOPE]->sprite, game->pos_manette);
    sfRenderWindow_drawSprite(game->window, game->sprite[SCOPE]->sprite, 0);
}

void main_menu(struct game_t *game)
{
    sfSprite_setPosition(game->sprite[PLAY]->sprite, get_position(930, 680));
    sfSprite_setPosition(game->sprite[QUIT]->sprite, get_position(1050, 680));
    play_quit_action(game);
    sfRenderWindow_drawSprite(game->window, game->sprite[PLAY]->sprite, 0);
    sfRenderWindow_drawSprite(game->window, game->sprite[QUIT]->sprite, 0);
    manette(game);
}
