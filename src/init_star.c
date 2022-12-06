/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** init_star
*/

#include "../include/hunter.h"

void init_star(struct star_t *star)
{
    star->speed = 1;
    star->pos_star_start = 1;
    sfTexture *star_tex = sfTexture_createFromFile("img/star.png", NULL);
    sfSprite *stars = sfSprite_create();
    sfSprite_setTexture(stars, star_tex, 0);
    sfVector2f scale_star = sfSprite_getScale(stars);
    scale_star.x *= 0.60;scale_star.y *= 0.60;
    sfSprite_setScale(stars, scale_star);
    star->pos_star = get_position(423,60);
    star->sprite_star = stars;

    star->pos_star_two_start = 1;
    sfTexture *star_tex_two = sfTexture_createFromFile("img/star2.png", NULL);
    sfSprite *stars_two = sfSprite_create();
    sfSprite_setTexture(stars_two, star_tex_two, 0);
    sfSprite_setScale(stars_two, scale_star);
    star->pos_star_two = get_position(800,200);
    star->sprite_star_two = stars_two;
}
