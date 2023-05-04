/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** vader
*/

#include "../include/hunter.h"

void disp_vader(struct hunter_t *hunter)
{
    sfRenderWindow_clear(hunter->window, sfBlack);
    sfRenderWindow_drawSprite(hunter->window, hunter->star->vader_sprite, NULL);
    sfRenderWindow_display(hunter->window);
}

int vader(struct hunter_t *hunter)
{
    sfMusic_stop(hunter->menu_music);
    int temp = 0;
    const sfClock *cloky = sfClock_create();
    while (temp < 3) {
        if (temp == 1)
            sfMusic_play(hunter->vader_music);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            return 42;
        sfEvent event;
        sfRenderWindow_pollEvent(hunter->window, &event);
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(hunter->window);
            return 42;
        }
        sfTime elapse = sfClock_getElapsedTime(cloky);
        temp = sfTime_asSeconds(elapse);
        disp_vader(hunter);
    }
    return window_end(hunter);
}
