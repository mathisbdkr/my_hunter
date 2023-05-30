/*
** EPITECH PROJECT, 2023
** hunter_v2
** File description:
** main_menu
*/

#include "hunter.h"
#include "struct.h"

static void text_button_pause(int i, sfVector2f pos, struct game_t *game)
{
    sfText *txt = sfText_create();
    sfVector2f size = get_position(1, 1);
    char *text = difficulty_txt[i];
    pos.x -= 230;
    pos.y -= 18;
    txt = made_txt(text, pos, size, game->starjhol);
    sfRenderWindow_drawText(game->window, txt, 0);
    sfText_destroy(txt);
}

static sfRectangleShape *hover_button(struct game_t *game,
sfRectangleShape *rect)
{
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(rect);
    sfVector2f pos = game->mous_pos;
    sfColor color = sfColor_fromRGBA(40, 40, 40, 220);
    if (sfFloatRect_contains(&bound,pos.x, pos.y)) {
        sfRectangleShape_setFillColor(rect, color);
    }
    return rect;
}

static void pause_background(struct game_t *game, sfVector2f size_back)
{
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    size_back.x -= 50;
    size_back.y -= 50;
    sfVector2f posi_back = get_position((size_win.x / 2) - size_back.x / 2,
    (size_win.y / 2) - size_back.y / 2);
    sfColor color = sfColor_fromRGBA(100, 100, 100, 255);
    made_rond_rect(size_back, posi_back, color, game->window);
}

static void difficulty_button_pt2(struct game_t *game, sfRectangleShape *rect,
    int i)
{
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(rect);
    sfVector2f pos = game->mous_pos;
    if ((sfFloatRect_contains(&bound,pos.x, pos.y)
    && sfMouse_isButtonPressed(0) && i == 2)
    || (sfFloatRect_contains(&bound, game->pos_manette.x, game->pos_manette.y)
    && sfJoystick_isButtonPressed(0, KEY_A) && i == 2)) {
        game->dificulty = IMPOSSIBLE;
        game->menu = 1;
        game->is_press = true;
    }
}

static void difficulty_button(struct game_t *game, sfRectangleShape *rect, int i)
{
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(rect);
    sfVector2f pos = game->mous_pos;
    if ((sfFloatRect_contains(&bound,pos.x, pos.y)
    && sfMouse_isButtonPressed(0) && i == 0)
    || (sfFloatRect_contains(&bound, game->pos_manette.x, game->pos_manette.y)
    && sfJoystick_isButtonPressed(0, KEY_A) && i == 0)) {
        game->dificulty = EASY;
        game->menu = 1;
        game->is_press = true;
    }
    if ((sfFloatRect_contains(&bound,pos.x, pos.y)
    && sfMouse_isButtonPressed(0) && i == 1)
    || (sfFloatRect_contains(&bound, game->pos_manette.x, game->pos_manette.y)
    && sfJoystick_isButtonPressed(0, KEY_A) && i == 1)) {
        game->dificulty = HARD;
        game->menu = 1;
        game->is_press = true;
    }
    difficulty_button_pt2(game, rect, i);
}

void select_dificulty(struct game_t *game)
{
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    sfVector2f size_butt = get_position(500, 50);
    sfVector2f posi_butt = get_position(size_win.x / 2, (size_win.y / 2) + 40);
    sfColor color = sfColor_fromRGBA(20, 20, 20, 240);
    sfRectangleShape *button = sfRectangleShape_create();
    pause_background(game, get_position(650, 280));
    posi_butt.y -= 120;
    if (sfKeyboard_isKeyPressed(sfKeyEscape) || sfJoystick_isButtonPressed(0, KEY_B))
        game->menu_difficulty = false;
    for (int i = 0; i < NB_DIFFICULTY; i++) {
        button = made_button(size_butt, posi_butt, color);
        sfRectangleShape_setOrigin(button,
        get_position(size_butt.x / 2, size_butt.y / 2));
        button = hover_button(game, button);
        sfRenderWindow_drawRectangleShape(game->window, button, 0);
        text_button_pause(i, posi_butt, game);
        difficulty_button(game, button, i);
        posi_butt.y += 80;
    }
}
