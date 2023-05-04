/*
** EPITECH PROJECT, 2022
** My_getnbr.c
** File description:
** task05 day04
*/

#include "hunter.h"

int my_getnbr(char *str)
{
    int i = 0;
    int nbr = 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10 + (str[i] - '0');
        }
        i++;
    }
    if (str[0] == '-') {
        nbr *= -1;
    }
    return nbr;
}
