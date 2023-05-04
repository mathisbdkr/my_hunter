/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-mathis.brehm
** File description:
** my_strcpy
*/

char *my_strcpy(char* dest, char* src)
{
    char *ptr = dest;
    while (*src != '\0') {
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return dest;
}
