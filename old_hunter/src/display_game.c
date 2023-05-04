/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** display_game
*/

#include "../include/hunter.h"

sfSprite *set_back_game(struct hunter_t *hunter)
{
    sfSprite *back_game = sfSprite_create();
    sfSprite_setTexture(back_game,
    sfTexture_createFromFile("img/back_game.png", NULL), 0);
    hunter->back_game = back_game;
}

int display_game_two(struct hunter_t *hunter, sfEvent event, sfVector2f pos)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(hunter->window);
    sfSprite_setPosition(hunter->bird, pos);
    sfRenderWindow_drawSprite(hunter->window, hunter->coeur, NULL);
    sfRenderWindow_drawSprite(hunter->window, hunter->bird, NULL);
    sfSprite_setPosition(hunter->scope, get_position(mouse.x, mouse.y));
    sfRenderWindow_drawSprite(hunter->window, hunter->scope, NULL);
    txt_score(hunter);
    sfRenderWindow_drawText(hunter->window, hunter->txt_score, NULL);
    sfRenderWindow_display(hunter->window);
}

int display_game(struct hunter_t *hunter, sfEvent event, sfVector2f pos)
{
    hunter->star->pos_star.x += 0.4;
    hunter->star->pos_star_two.x -= 0.4;
    sfSprite_setPosition(hunter->star->sprite_star, hunter->star->pos_star);
    sfSprite_setPosition(hunter->star->sprite_star_two,
    hunter->star->pos_star_two);
    sfRenderWindow_clear(hunter->window, sfBlack);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(hunter->window);
    if (sfRenderWindow_pollEvent(hunter->window, &event)) {
        if (shout(get_position(mouse.x, mouse.y), hunter, event) == 1)
            return 1;
    }
    sfRenderWindow_drawSprite(hunter->window, hunter->back_game, NULL);
    sfRenderWindow_drawSprite(hunter->window, hunter->star->sprite_star, NULL);
    sfRenderWindow_drawSprite(hunter->window,
    hunter->star->sprite_star_two, NULL);
    display_game_two(hunter, event, pos);
}
