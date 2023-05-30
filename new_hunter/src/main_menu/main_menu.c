/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** main_menu
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
    sfFloatRect play = sfSprite_getGlobalBounds(game->sprite[PLAY]->sprite);
    sfFloatRect quit = sfSprite_getGlobalBounds(game->sprite[QUIT]->sprite);
    if ((sfFloatRect_contains(&play, game->mous_pos.x, game->mous_pos.y)
    && sfMouse_isButtonPressed(0) && game->is_press == false) ||
    (sfFloatRect_contains(&play, game->pos_manette.x, game->pos_manette.y)
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

static void select_settings(struct game_t *game)
{
    sfFloatRect hitbox = sfSprite_getGlobalBounds(game->sprite[SETTINGS]->sprite);
    if ((sfFloatRect_contains(&hitbox, game->mous_pos.x, game->mous_pos.y)
    && sfMouse_isButtonPressed(0)) ||
    (sfFloatRect_contains(&hitbox, game->pos_manette.x, game->pos_manette.y)
    && sfJoystick_isButtonPressed(0, KEY_A))) {
        game->is_settings = true;
    }
    sfRenderWindow_drawSprite(game->window, game->sprite[SETTINGS]->sprite, 0);
}

void main_menu(struct game_t *game)
{
    select_settings(game);
    sfSprite_setPosition(game->sprite[PLAY]->sprite, get_position(930, 680));
    sfSprite_setPosition(game->sprite[QUIT]->sprite, get_position(1050, 680));
    sfRenderWindow_drawSprite(game->window, game->sprite[PLAY]->sprite, 0);
    sfRenderWindow_drawSprite(game->window, game->sprite[QUIT]->sprite, 0);
    sfSprite_setPosition(game->sprite[GAME_NAME]->sprite, get_position(400, 100));
    sfSprite_setScale(game->sprite[GAME_NAME]->sprite, get_position(0.9, 0.9));
    sfRenderWindow_drawSprite(game->window, game->sprite[GAME_NAME]->sprite, 0);
    if (game->menu_difficulty == true)
        select_dificulty(game);
    else
        play_quit_action(game);
    sfSprite_setPosition(game->sprite[SCOPE]->sprite, game->mous_pos);
    sfRenderWindow_drawSprite(game->window, game->sprite[SCOPE]->sprite, 0);
    if (game->menu == 1) {
        play_music(game);
        game->menu_difficulty = false;
    }
}
