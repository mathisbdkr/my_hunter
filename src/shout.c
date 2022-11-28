/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** shout
*/

#include "../include/hunter.h"

sfVector2f position_tie(float x, float y)
{
    sfVector2f vector;
    vector.x = x;
    vector.y = y;
    return (vector);
}

void anim_explosion(struct hunter_t *hunter, sfVector2f tie_pos)
{
    int i = 0;
    set_explosion(hunter);
    while (i < 20) {
        sfRenderWindow_clear(hunter->window, sfBlack);
        sfRenderWindow_drawSprite(hunter->window, hunter->background, NULL);
        sfSprite_setTextureRect(hunter->explo, set_anim_explosion(i, hunter));
        sfSprite_setPosition(hunter->explo,
        position_tie(tie_pos.x, tie_pos.y));
        sfVector2f scale_explosion = sfSprite_getScale(hunter->explo);
        scale_explosion.x *= 1.01;
        scale_explosion.y *= 1.01;
        sfSprite_setScale(hunter->explo, scale_explosion);
        sfRenderWindow_drawSprite(hunter->window, hunter->explo, NULL);
        sfRenderWindow_drawSprite(hunter->window, hunter->coeur, NULL);
        sfSprite_setTextureRect(hunter->coeur, anim_coeur(hunter));
        txt_score(hunter);
        sfRenderWindow_drawText(hunter->window, hunter->txt_score, NULL);
        sfRenderWindow_display(hunter->window);
        i++;
    }
}

int shout(sfVector2f mouse_pos, struct hunter_t *hunter, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        sfRenderWindow_close(hunter->window);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(hunter->window);
    sfRenderWindow *window = hunter->window;
    sfRenderWindow_pollEvent(window, &event);
    if (event.type == sfEvtMouseButtonPressed) {
        sfMusic_stop(hunter->fire_music);
        sfMusic_play(hunter->fire_music);
        if (mouse_pos.x <= hunter->pos_bird.x + 134 &&
        mouse_pos.x >= hunter->pos_bird.x &&
        mouse_pos.y <= hunter->pos_bird.y + hunter->haut &&
        mouse_pos.y >= hunter->pos_bird.y) {
            sfMusic_stop(hunter->explosion_music);
            sfMusic_play(hunter->explosion_music);
            anim_explosion(hunter, hunter->pos_bird);
            hunter->score += 1; return 1;
        }
        hunter->vie -= 1;
    }
}
