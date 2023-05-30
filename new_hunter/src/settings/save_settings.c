/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** save_settings
*/

#include "hunter.h"
#include "struct.h"

void save_settings(struct game_t *game)
{
    int fd = open("config/settings.mbf", O_WRONLY | O_TRUNC | O_CREAT, 422);
    write(fd, &(game->settings), sizeof(struct settings_s));
    close(fd);
}
