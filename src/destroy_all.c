/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** destroy_all
*/

#include "../include/hunter.h"

void dest_all(struct hunter_t *hunter)
{
    sfMusic_destroy(hunter->game_music);
    sfMusic_destroy(hunter->explosion_music);
    sfMusic_destroy(hunter->fire_music);
    sfMusic_destroy(hunter->menu_music);
    sfMusic_destroy(hunter->vader_music);
    sfSprite_destroy(hunter->back_game);
    sfSprite_destroy(hunter->background);
    sfSprite_destroy(hunter->bird);
    sfSprite_destroy(hunter->coeur);
    sfSprite_destroy(hunter->explo);
    sfSprite_destroy(hunter->game_name);
    sfSprite_destroy(hunter->play);
    sfSprite_destroy(hunter->scope);
    sfSprite_destroy(hunter->star);
}
