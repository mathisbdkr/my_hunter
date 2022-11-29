/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** display_all
*/

#include "../include/hunter.h"

void display_score(struct hunter_t *hunter, sfText *nbr_score, char *buf)
{
    sfText_setFont(nbr_score,sfFont_createFromFile("text/score.otf"));
    sfText_setCharacterSize(nbr_score, 42);
    sfText_setString(nbr_score, buf);
    sfText_setColor(nbr_score, sfYellow);
}

char* get_score_char(struct hunter_t *hunter)
{
    char n;
    if (hunter->score <= 9) {
        n = hunter->score + 48;
        hunter->score_char[0] = n;
        hunter->score_char[1] = '\0';
    }
    if (hunter->score > 9) {
        n = (hunter->score * 0.1) + 48;
        hunter->score_char[0] = n;
        n = (hunter->score - (n * 10) + 16);
        hunter->score_char[1] = n;
    }
}

int ondulation(struct hunter_t *hunter)
{
    if (hunter->score > 9) {
        if (hunter->ondulation_check == 0)
            hunter->pos_bird.y += 2;
        if (hunter->pos_bird.y > hunter->pos_bird_start + hunter->score)
            hunter->ondulation_check = 1;
        if (hunter->ondulation_check == 1)
            hunter->pos_bird.y -= 2;
        if (hunter->pos_bird.y < hunter->pos_bird_start - hunter->score)
            hunter->ondulation_check = 0;
    }
    if (hunter->vie == 0) {
        return 1;
    }
    return 0;
}

void disp_window_end(struct hunter_t *hunter)
{
    sfRenderWindow_clear(hunter->window, sfBlack);
    sfRenderWindow_drawSprite(hunter->window, hunter->background, NULL);
    sfRenderWindow_drawSprite(hunter->window, hunter->game_over, NULL);
    sfSprite_setPosition(hunter->retry, hunter->pos_retry);
    sfRenderWindow_drawSprite(hunter->window, hunter->retry, NULL);
    sfSprite_setPosition(hunter->quit, hunter->pos_quit);
    sfRenderWindow_drawSprite(hunter->window, hunter->quit, NULL);
    txt_bestscore_fin(hunter);
    sfRenderWindow_drawText(hunter->window, hunter->txt_bestscore, NULL);
    sfRenderWindow_drawText(hunter->window, hunter->txt_msg_best_score, NULL);
    txt_score_fin(hunter);
    sfRenderWindow_drawText(hunter->window, hunter->txt_score, NULL);
    sfRenderWindow_display(hunter->window);
}
