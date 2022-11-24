/*
** EPITECH PROJECT, 2022
** my put str
** File description:
** task02
*/
void my_putchar(char c);

void my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
