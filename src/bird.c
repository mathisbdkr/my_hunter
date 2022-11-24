/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** bird
*/

#include "../include/hunter.h"

void bird_gd(struct hunter_t *hunter, sfEvent event)
{
	int i = 0;
	sfSprite *img_bird = sprite_bird();
	sfVector2f pos = sfSprite_getPosition(img_bird);
	sfSprite *scope1 = sprite_scope1();
	pos.y = rand() % 600;
	pos.x = -134;
	while (pos.x < 1366) {
		if (hunter->vie == 0) {
			return;
		}
		hunter->speed = timing(hunter, 0);
		i += hunter->speed;
		sfSprite_setTextureRect(img_bird, anim_gd(i, hunter));
		if (i >= 30)
			i = 0;
		pos.x += hunter->speed + hunter->score;
		sfRenderWindow_clear(hunter->window, sfBlack);
		sfVector2i mouse = sfMouse_getPositionRenderWindow(hunter->window);
		if (sfRenderWindow_pollEvent(hunter->window, &event)) {
			if (shout(get_position(mouse.x, mouse.y), pos, hunter, event) == 1)
				return;
		}
		sfRenderWindow_drawSprite(hunter->window, hunter->background, NULL);
		sfSprite_setPosition(img_bird, pos);
		sfRenderWindow_drawSprite(hunter->window, img_bird, NULL);
		sfSprite_setPosition(scope1, get_position(mouse.x, mouse.y));
		sfRenderWindow_drawSprite(hunter->window, scope1, NULL);
		sfRenderWindow_display(hunter->window);
	}
}

void bird_dg(struct hunter_t *hunter, sfEvent event)
{
	int i = 0;
	sfSprite *img_bird = sprite_bird();
	sfVector2f pos = sfSprite_getPosition(img_bird);
	sfSprite *scope1 = sprite_scope1();
	pos.y = rand() % 600;
	pos.x = 1364;
	while (pos.x > 0) {
		if (hunter->vie == 0) {
			return;
		}
		hunter->speed = timing(hunter, 0);
		i += hunter->speed;
		sfSprite_setTextureRect(img_bird, anim_dg(i, hunter));
		if (i >= 30)
			i = 0;
		pos.x -= hunter->speed + hunter->score;
		sfRenderWindow_clear(hunter->window, sfBlack);
		sfVector2i mouse = sfMouse_getPositionRenderWindow(hunter->window);
		if (sfRenderWindow_pollEvent(hunter->window, &event)) {
			if (shout(get_position(mouse.x, mouse.y), pos, hunter, event) == 1)
				return;
		}
		sfRenderWindow_drawSprite(hunter->window, hunter->background, NULL);
		sfSprite_setPosition(img_bird, pos);
		sfRenderWindow_drawSprite(hunter->window, img_bird, NULL);
		sfSprite_setPosition(scope1, get_position(mouse.x, mouse.y));
		sfRenderWindow_drawSprite(hunter->window, scope1, NULL);
		sfRenderWindow_display(hunter->window);
	}
}

int display_bird(struct hunter_t *hunter, sfEvent event)
{
	int sance = rand() % 100;
	hunter->speed = timing(hunter, 1);
	if (hunter->vie == 0) {
		return 1;
	}
	if (sance < 50) {
		bird_gd(hunter, event);
	}
	if (sance >= 50) {
		bird_dg(hunter, event);
	}
}