/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** init_settings
*/

#include "hunter.h"
#include "struct.h"

void init_settings(struct game_t *game)
{
    struct stat sb;
    int type = stat("config/settings.mbf", &sb);
    int fd = open("config/settings.mbf", O_RDONLY);
    if (type == -1 || fd == -1) {
        close(fd);
        return;
    }
    read(fd, &(game->settings), sb.st_size);
    close(fd);
}
