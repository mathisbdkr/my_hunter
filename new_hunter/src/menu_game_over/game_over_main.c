/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** game_over_main
*/

#include "hunter.h"
#include "struct.h"

static void play_music(struct game_t *game)
{
    sfMusic_stop(game->song.music);
    sfMusic_destroy(game->song.music);
    game->song.music = set_music(music[MUSIC_GAME], game->settings.volum_music);
    sfMusic_play(game->song.music);
    sfMusic_setLoop(game->song.music, sfTrue);
}

static void play_quit_action(struct game_t *game)
{
    sfFloatRect retry = sfSprite_getGlobalBounds(game->sprite[RETRY]->sprite);
    sfFloatRect quit = sfSprite_getGlobalBounds(game->sprite[QUIT_END]->sprite);
    if ((sfFloatRect_contains(&retry, game->mous_pos.x, game->mous_pos.y)
    && sfMouse_isButtonPressed(0) && game->is_press == false) ||
    (sfFloatRect_contains(&retry, game->pos_manette.x, game->pos_manette.y)
    && sfJoystick_isButtonPressed(0, KEY_A) && game->is_press == false)) {
        game->menu_difficulty = true;
    }
    if ((sfFloatRect_contains(&quit, game->mous_pos.x, game->mous_pos.y)
    && sfMouse_isButtonPressed(0) && game->is_press == false) ||
    (sfFloatRect_contains(&quit, game->pos_manette.x, game->pos_manette.y)
    && sfJoystick_isButtonPressed(0, KEY_A) && game->is_press == false)) {
        sfRenderWindow_close(game->window);
        game->is_press = true;
    }
    if (!sfMouse_isButtonPressed(0))
        game->is_press = false;
}

void game_over_main(struct game_t *game)
{
    sfRenderWindow_drawSprite(game->window,game->sprite[BACK_MENU]->sprite, 0);
    sfSprite_setPosition(game->sprite[RETRY]->sprite, get_position(655 , 680));
    sfRenderWindow_drawSprite(game->window, game->sprite[RETRY]->sprite, 0);
    sfSprite_setPosition(game->sprite[QUIT_END]->sprite, get_position(1057, 680));
    sfRenderWindow_drawSprite(game->window, game->sprite[QUIT_END]->sprite, 0);
    if (game->menu_difficulty == true)
        select_dificulty(game);
    else
        play_quit_action(game);
    if (game->menu == 1) {
        play_music(game);
        game->menu_difficulty = false;
    }
}
