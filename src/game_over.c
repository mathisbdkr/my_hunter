/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** game_over
*/

#include "../include/hunter.h"

void display_bestscore(struct hunter_t *hunter, sfText *nbr_bscore, char *bufx)
{
    sfText_setFont(nbr_bscore,sfFont_createFromFile("text/score.otf"));
    sfText_setCharacterSize(nbr_bscore, 47);
    sfText_setString(nbr_bscore, bufx);
    sfText_setColor(nbr_bscore, sfYellow);
}

char* get_bestscore_char(struct hunter_t *hunter)
{
    char n;
    if (hunter->bestscore <= 9) {
        n = hunter->bestscore + 48;
        hunter->bestscore_char[0] = n;
        hunter->bestscore_char[1] = '\0';
    }
    if (hunter->bestscore > 9) {
        n = (hunter->bestscore * 0.1) + 48;
        hunter->bestscore_char[0] = n;
        n = (hunter->bestscore - (n * 10) + 16);
        hunter->bestscore_char[1] = n;
    }
}

void txt_score_fin(struct hunter_t *hunter)
{
    FILE *fp = fopen("text/score.txt", "w" );
    char *test = "Votre score a ete de ";
    char buf[42];
    int score = hunter->score;
    get_score_char(hunter);
    char *temp = hunter->score_char;
    fwrite(test, 1 , my_strlen(test) , fp );
    fwrite(temp, 1 , my_strlen(temp) , fp );
    fwrite(" TIE detruit gg!!!", 1 , 18 , fp );
    fclose(fp);
    int fd = open("text/score.txt", O_RDONLY);
    read(fd, buf, 42);
    close(fd);
    sfText *nbr_score = sfText_create();
    display_score(hunter, nbr_score, buf);
    sfText_setPosition(nbr_score, get_position(440, 600));
    hunter->txt_score = nbr_score;
}

void txt_bestscore_fin(struct hunter_t *hunter)
{
    char *tem;
    int fd;
    if (hunter->score > hunter->bestscore) {
        hunter->bestscore = hunter->score;
        get_bestscore_char(hunter);
        tem = hunter->bestscore_char;
        FILE *fp = fopen("best/bestscore.txt", "w" );
        fwrite(tem, 1 , my_strlen(tem) , fp );
        fclose(fp);
    } else {
        get_bestscore_char(hunter);
        tem = hunter->bestscore_char;
    }
    fd = open("best/bestscore.txt", O_RDONLY);
    read(fd, hunter->bestscore_char, 2);
    close(fd);
    sfText *nbr_bestscore = sfText_create();
    display_bestscore(hunter, nbr_bestscore, hunter->bestscore_char);
    sfText_setPosition(nbr_bestscore, get_position(175, -2));
    hunter->txt_bestscore = nbr_bestscore;
}

int window_end(struct hunter_t *hunter)
{
    set_game_over(hunter);set_retry(hunter);set_quit(hunter);
    hunter->pos_retry = get_position(450, 450);
    hunter->pos_quit = get_position(750, 450);
    sfEvent event;
    while (sfRenderWindow_isOpen(hunter->window)) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(hunter->window);
        if (menu_game_over(get_position(mouse.x, mouse.y), hunter) == 42) {
            return 42;
        }
        if (menu_game_over(get_position(mouse.x, mouse.y), hunter) == 1) {
            return 1;
        }
        disp_window_end(hunter);
    }
}
