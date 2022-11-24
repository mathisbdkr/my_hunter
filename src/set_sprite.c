/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** set_sprite
*/

#include "../include/hunter.h"

sfSprite *set_background(struct hunter_t *hunter)
{
    sfSprite *background = sfSprite_create();
	sfSprite_setTexture(background, sfTexture_createFromFile("img/background.png", NULL), 0);
    hunter->background = background;
}

sfSprite *sprite_bird(void)
{
	sfTexture *oiseau = sfTexture_createFromFile("img/bird.png", NULL);
	sfSprite *img_bird = sfSprite_create();
	sfSprite_setTexture(img_bird, oiseau, 0);
	return img_bird;
}

sfSprite *sprite_scope1(void)
{
	sfTexture *img_scope1 = sfTexture_createFromFile("img/scope1.png", NULL);
	sfSprite *scope1 = sfSprite_create();
	sfSprite_setTexture(scope1, img_scope1, 0);
	sfSprite_setOrigin(scope1, get_position(52, 44));
	return scope1;
}
