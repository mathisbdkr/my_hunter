/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** time
*/

#include "../include/hunter.h"

int timing(struct hunter_t *hunter,int resstart)
{
    int temp = 0;
    const sfClock *cloky = sfClock_create();
    hunter->time = sfClock_getElapsedTime(cloky);
    temp = sfTime_asSeconds(hunter->time);
	hunter->speed = (temp % 6) * -1;
    return ((temp % 6) * -1 + 3);
}