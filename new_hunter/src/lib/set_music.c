/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** set_music
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

sfMusic *set_music(char *path, float volume)
{
    sfMusic *music = sfMusic_createFromFile(path);
    sfMusic_setVolume(music, volume);
    return music;
}
