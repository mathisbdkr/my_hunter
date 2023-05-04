/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** bird
*/

#include "../include/hunter.h"

void txt_score(struct hunter_t *hunter)
{
    int fd = 0;
    int i = 3;
    int result = 0;
    FILE *fp;
    char *test = "score = ";
    char buf[32];
    fp = fopen("text/score.txt", "w" );
    int score = hunter->score;
    get_score_char(hunter);
    char *temp = hunter->score_char;
    fwrite(test, 1 , my_strlen(test) , fp );
    fwrite(temp, 1 , my_strlen(temp) , fp );
    fclose(fp);
    fd = open("text/score.txt", O_RDONLY);
    read(fd, buf, 32);
    close(fd);
    sfText *nbr_score = sfText_create();
    display_score(hunter, nbr_score, buf);
    sfText_setPosition(nbr_score, get_position(150, -10));
    hunter->txt_score = nbr_score;
}

void bird_gd(struct hunter_t *hunter, sfEvent event, struct star_t *star)
{
    sfSprite *coeur = set_coeur(hunter); int i = 0;
    hunter->pos_bird.y = rand() % 600;
    hunter->pos_bird.x = -134;
    hunter->pos_bird_start = hunter->pos_bird.y;
    while (hunter->pos_bird.x < 1479 && sfRenderWindow_isOpen(hunter->window)) {
        if (ondulation(hunter) == 1) {
            return;
        }
        hunter->speed = timing(hunter, 0);
        i += 1;
        sfSprite_setTextureRect(hunter->bird, anim_gd(i, hunter));
        sfSprite_setTextureRect(coeur, anim_coeur(hunter));
        if (i >= 30)
            i = 0;
        hunter->pos_bird.x += hunter->speed + hunter->score;
        if (display_game(hunter, event, hunter->pos_bird) == 1) {
            return;
        }
    }
    hunter->vie -= 1;
}

void bird_dg(struct hunter_t *hunter, sfEvent event, struct star_t *star)
{
    sfSprite *coeur = set_coeur(hunter); int i = 0;
    hunter->pos_bird.y = rand() % 600;
    hunter->pos_bird.x = 1364;
    hunter->pos_bird_start = hunter->pos_bird.y;
    while (hunter->pos_bird.x > -113 && sfRenderWindow_isOpen(hunter->window)) {
        if (ondulation(hunter) == 1) {
            return;
        }
        hunter->speed = timing(hunter, 0);
        i += 1;
        sfSprite_setTextureRect(hunter->bird, anim_dg(i, hunter));
        sfSprite_setTextureRect(coeur, anim_coeur(hunter));
        if (i >= 30)
            i = 0;
        hunter->pos_bird.x -= hunter->speed + hunter->score;
        if (display_game(hunter, event, hunter->pos_bird) == 1) {
            return;
        }
    }
    hunter->vie -= 1;
}

int display_bird(struct hunter_t *hunter, sfEvent event, struct star_t *star)
{
    int sance = rand() % 100;
    hunter->speed = timing(hunter, 1);
    if (hunter->star->pos_star.x >= 1366)
        hunter->star->pos_star.x = -423;
    if (hunter->star->pos_star_two.x <= -706)
        hunter->star->pos_star_two.x = 1400;
    sfRenderWindow_setMouseCursorVisible(hunter->window, sfFalse);
    if (hunter->vie == 0) {
        return 1;
    }
    if (sance < 50 && sfRenderWindow_isOpen(hunter->window)) {
        bird_gd(hunter, event, star);
    }
    if (sance >= 50 && sfRenderWindow_isOpen(hunter->window)) {
        bird_dg(hunter, event, star);
    }
}
