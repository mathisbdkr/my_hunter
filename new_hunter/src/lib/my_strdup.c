/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-myls-edward.lalande
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char *s1)
{
    int i = 0;
    int len_s1 = my_strlen(s1);
    char *s2 = malloc(sizeof(char) * (len_s1 + 1));

    while (s1[i] != '\0') {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';

    return s2;
}
