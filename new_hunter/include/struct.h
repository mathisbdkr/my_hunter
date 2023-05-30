/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include "hunter.h"

    #define NB_SPRITE 17
    #define EASY 4
    #define HARD 6
    #define IMPOSSIBLE 10
    #define NB_DIFFICULTY 3
    #define NB_EFFECT 2
    #define NB_MUSIC 3
    #define NB_TXT_PAUSE 4
    #define NB_TXT_FPS 3
    #define NB_SONG_TXT 4
    #define NB_LEVEL_FOR_BOSSE 10

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
    VADER,
    PAUSE,
    SETTINGS,
};

enum{
    MUSIC_GAME,
    MUSIC_MENU,
    MUSIC_GAME_OVER,
};

enum{
    EFFECT_EXPLOSION,
    EFFECT_FIRE,
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
    "assets/img/game/settings.png",
    "assets/img/game/settings.png"
};

static char *const effect[NB_EFFECT] = {
    "assets/song/effect/explosion.ogg",
    "assets/song/effect/fire.ogg",
};

static char *const volume_txt[NB_SONG_TXT] = {
    "song :",
    "general :",
    "music :",
    "effect :",
};

static char *const music[NB_MUSIC] = {
    "assets/song/music/game.ogg",
    "assets/song/music/menu.ogg",
    "assets/song/music/you_lose.wav",
};

static char *const pause_txt[NB_TXT_PAUSE] = {
    "back to game",
    "settings",
    "back to menu",
    "back to desktop",
};

static char *const fps_txt[NB_TXT_FPS] = {
    "45",
    "60",
    "90",
};

static int const fps_select[NB_TXT_FPS] = {
    45,
    60,
    90,
};

static const sfVector2f win_border[2] = {
    {-134, 2053},
    {-134, 2053},
};

static const sfVector2f resize[1] = {
    {1.4055636896, 1.5083798883},
};

static char *const difficulty_txt[NB_DIFFICULTY] = {
    "easy",
    "hard",
    "impossible",
};

struct game_sprite_t {
    sfSprite *sprite;
};

struct stat_t {
    int level;
    int life;
    int score;
    int nb_ennemy;
    bool is_bosse;
};

struct ship_t {
    sfSprite *ship;
    sfSprite *explo;
    sfVector2f pos;
    sfTexture *texture;
    int anim_frame;
    int anim_revers;
    int boss_nb_hit;
    bool left;
    bool hit;
};

typedef struct song_s {
    sfMusic *music;
    sfMusic *effect_eplo;
    sfMusic *effect_fire;
} song_t;

typedef struct settings_s {
    int fps_select;
    int size_select;
    int is_fullscreen;
    float volum_music;
    float volum_effect;
    float volum_general;
    float sensibility;
} settings_t;

struct game_t {
    sfRenderWindow *window;
    sfVector2f mous_pos;
    sfEvent event;
    sfVector2f pos_manette;
    sfFont *starjhol;
    int menu;
    int dificulty;
    int end;
    bool menu_difficulty;
    bool is_press;
    bool is_pause;
    bool is_settings;
    struct ship_t **ship;
    struct game_sprite_t **sprite;
    struct stat_t *stat;
    song_t song;
    settings_t settings;
};

#endif /* !STRUCT_H_ */
