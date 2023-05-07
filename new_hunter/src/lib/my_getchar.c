/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** my_getchar
*/

#include <stdlib.h>

char* my_getchar(int num)
{
    int i = 0;
    int tmp = num;
    if (tmp == 0)
        return "0";
    while (tmp > 0) {
        tmp /= 10;
        i++;
    }
    char* str = malloc(sizeof(char) * (i + 1));
    str[i--] = '\0';
    while (num > 0) {
        str[i--] = (num % 10) + '0';
        num /= 10;
    }
    return str;
}
