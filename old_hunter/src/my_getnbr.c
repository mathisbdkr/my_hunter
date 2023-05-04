/*
** EPITECH PROJECT, 2022
** My_getnbr.c
** File description:
** task05 day04
*/

#include "../include/hunter.h"

int creat_nbr(char *nb, int i)
{
    int len = my_strlen(nb);
    int temp[len];
    int size_n = 0;
    int res = 0;
    while (nb[i] && nb[i] > 47 && nb[i] < 58) {
        if (size_n > 0) {
            res --;
            res *= 10;
        }
        temp[i] = nb[i] - 47;
        res += temp[i];
        i++;
        size_n++;
    }
    return res;
}

int my_getnbr(char* nb)
{
    int i = 0;
    int i2 = i;
    int res = creat_nbr(nb, i);
    res--;
    return res;
}
