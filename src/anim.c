/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** anim
*/

#include "../include/hunter.h"

sfVector2f get_position(int x, int y)
{
	sfVector2f vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

sfIntRect anim_gd(int i, struct hunter_t *hunter)
{
	sfIntRect rect;
	if (i >= 0 && i < 10) {
		rect = get_rect(0, 402/1, 402/3 * -1, 110);
	}
	if (i >= 10 && i < 20) {
		rect = get_rect(0, 402 / 3, (402/3) * -1, 110);
	}
	if (i >= 20 && i < 30) {
		rect = get_rect(0, 402 / 3 * 2, (402/3) * -1, 110);
	}
	hunter-> haut = 110;
	return rect;
}

sfIntRect anim_dg(int i, struct hunter_t *hunter)
{
	sfIntRect rect;
	if (i >= 0 && i < 10) {
		rect = get_rect(0, 0, 402/3, 110);
	}
	if (i >= 10 && i < 20) {
		rect = get_rect(0, 402 / 3, 402/3, 110);
	}
	if (i >= 20 && i < 30) {
		rect = get_rect(0, 402 / 3 * 2, 402/3, 110);
	}
	hunter-> haut = 110;
	return rect;
}
