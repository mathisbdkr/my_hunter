/*
** EPITECH PROJECT, 2023
** merge
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
