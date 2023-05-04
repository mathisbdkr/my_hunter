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
    sfSprite_setTexture(background,
    sfTexture_createFromFile("img/background.png", NULL), 0);
    hunter->background = background;
}

sfSprite *sprite_bird(struct hunter_t *hunter)
{
    sfTexture *oiseau = sfTexture_createFromFile("img/bird.png", NULL);
    sfSprite *img_bird = sfSprite_create();
    sfSprite_setTexture(img_bird, oiseau, 0);
    hunter->bird = img_bird;
    return img_bird;
}

sfSprite *sprite_scope1(struct hunter_t *hunter)
{
    sfTexture *img_scope1 = sfTexture_createFromFile("img/scope1.png", NULL);
    sfSprite *scope1 = sfSprite_create();
    sfSprite_setTexture(scope1, img_scope1, 0);
    sfSprite_setOrigin(scope1, get_position(52, 44));
    hunter->scope = scope1;
    return scope1;
}

sfSprite *set_coeur(struct hunter_t *hunter)
{
    sfSprite *coeur = sfSprite_create();
    sfSprite_setTexture(coeur,
    sfTexture_createFromFile("img/coeur.png", NULL), 0);
    hunter->coeur = coeur;
    return coeur;
}

sfSprite *set_explosion(struct hunter_t *hunter)
{
    sfSprite *explosion = sfSprite_create();
    sfSprite_setTexture(explosion,
    sfTexture_createFromFile("img/explosion.png", NULL), 0);
    hunter->explo = explosion;
}
