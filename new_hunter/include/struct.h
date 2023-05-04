/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include "hunter.h"

    #define NB_SPRITE 15

enum{
    KEY_A,
    KEY_B,
    KEY_X,
    KEY_Y,
    KEY_LB,
    KEY_RB,
    KEY_BACK,
    KEY_START,
    KEY_CENTER,
    KEY_LSB,
    KEY_LRB,
};

enum{
    JOYSTICK_LX,
    JOYSTICK_LY,
    JOYSTICK_LT,
    JOYSTICK_RT,
    JOYSTICK_RX,
    JOYSTICK_RY,
    PAD_X,
    PAD_Y,
};

enum{
    BACK,
    HEART,
    EXPLOSION,
    SCOPE,
    TIE,
    STAR,
    BACK_MENU,
    COCKPIT,
    GAME_NAME,
    GAME_OVER,
    PLAY,
    QUIT,
    QUIT_END,
    RETRY,
    VADER
};

static char *const sprite_path[NB_SPRITE] = {
    "assets/img/game/back_game.png",
    "assets/img/game/coeur.png",
    "assets/img/game/explosion.png",
    "assets/img/game/scope.png",
    "assets/img/game/ship.png",
    "assets/img/game/star.png",
    "assets/img/menu/background.png",
    "assets/img/menu/cockpit.png",
    "assets/img/menu/game_name.png",
    "assets/img/menu/game_over.png",
    "assets/img/menu/play.png",
    "assets/img/menu/quit.png",
    "assets/img/menu/quite_end.png",
    "assets/img/menu/retry.png",
    "assets/img/menu/vader.jpg",
};

static const sfVector2f resize[1] = {
    {1.4055636896, 1.5083798883},
};

struct game_sprite_t {
    sfSprite *sprite;
};

struct stat_t {
    int level;
    int life;
};

struct ship_t {
    sfSprite *ship;
    sfVector2f pos;
    sfTexture *texture;
    int anim_frame;
    bool left;
    bool hit;
};

struct game_t {
    sfRenderWindow *window;
    sfVector2f mous_pos;
    int menu;
    bool press;
    sfVector2f pos_manette;
    struct ship_t **ship;
    struct game_sprite_t **sprite;
    struct stat_t *stat;
};

#endif /* !STRUCT_H_ */
