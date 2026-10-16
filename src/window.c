/*
** EPITECH PROJECT, 2024
** test
** File description:
** window
*/

#include "project.h"

static void draw_enemies(sfRenderWindow *window, main_t *main)
{
    for (int i = 0; i < main->enemies->nb_enemies; i++) {
        main->enemies[i].position.x += main->enemies->speed;
        sfSprite_setPosition(main->enemies[i].sprite,
            main->enemies[i].position);
        clock_enemies(main, i);
        sfRenderWindow_drawSprite(window, main->enemies[i].sprite, NULL);
        if (main->enemies[i].position.x > 800)
            main->enemies[i].position.x = -150;
    }
}

static void draw_shoot(main_t *main, sfRenderWindow *window, float delta_time)
{
    set_rotation_shoot(main, window, 0);
    set_rotation_shoot(main, window, 1);
    set_rotation_shoot(main, window, 2);
    set_rotation_shoot(main, window, 3);
    update_projectile(main, delta_time, 0);
    update_projectile(main, delta_time, 1);
    update_projectile(main, delta_time, 2);
    update_projectile(main, delta_time, 3);
    if (main->gameplay->base->shoot_base[0].active == 1)
        sfRenderWindow_drawSprite(window,
            main->gameplay->base->shoot_base[0].sprite, NULL);
    if (main->gameplay->base->shoot_base[1].active == 1)
        sfRenderWindow_drawSprite(window,
            main->gameplay->base->shoot_base[1].sprite, NULL);
    if (main->gameplay->base->shoot_base[2].active == 1)
        sfRenderWindow_drawSprite(window,
            main->gameplay->base->shoot_base[2].sprite, NULL);
    if (main->gameplay->base->shoot_base[3].active == 1)
        sfRenderWindow_drawSprite(window,
            main->gameplay->base->shoot_base[3].sprite, NULL);
}

static void draw_score(main_t *main, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window,
        main->gameplay->score->sprite, NULL);
    update_score(main);
    sfRenderWindow_drawText(window, main->gameplay->score->text, NULL);
}

static void draw_base(main_t *main, sfRenderWindow *window, sfClock *clock)
{
    float delta_time = sfTime_asSeconds(sfClock_restart(clock));

    sfRenderWindow_drawSprite(window, main->gameplay->base->sprite, NULL);
    set_rotation_turret(main, window);
    sfRenderWindow_drawSprite(window,
        main->gameplay->base->turret->sprite, NULL);
    draw_shoot(main, window, delta_time);
    if (main->gameplay->base->shoot_base[main->gameplay->
            base->shoot_base->current_projectile].copy_position.x !=
                main->gameplay->base->shoot_base[main->gameplay->base->
                    shoot_base->current_projectile].position.x) {
        main->gameplay->base->shoot_base->current_projectile++;
    }
    if (main->gameplay->base->shoot_base->current_projectile == 4)
        main->gameplay->base->shoot_base->current_projectile = 0;
    check_state_magazine(main);
    sfRenderWindow_drawSprite(window,
        main->gameplay->laser_magazine->sprite, NULL);
    draw_score(main, window);
}

static void draw_the_game
(main_t *main, sfRenderWindow *window, int game_status, sfClock *clock)
{
    if (game_status == 1) {
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        if_play_music_game(main);
        sfRenderWindow_drawSprite(window,
            main->gameplay->background_in_gameplay->sprite, NULL);
        draw_enemies(window, main);
        draw_base(main, window, clock);
        sfRenderWindow_drawSprite(window,
            main->gameplay->cursor_game->sprite, NULL);
    }
    if (game_status == 0) {
        if_play_music_main_menu(main);
        sfRenderWindow_drawSprite(window,
            main->main_menu->background_in_main_menu->sprite, NULL);
        change_pos_selector_menu(main);
        sfRenderWindow_drawSprite
            (window, main->main_menu->cursor_select_mode->sprite, NULL);
    }
}

void open_the_window(sfRenderWindow *window, main_t *main, int *game_status)
{
    sfEvent event;
    sfClock *clock = sfClock_create();

    init_fnct(main);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        analyse_event(window, event, main, game_status);
        draw_the_game(main, window, *game_status, clock);
        sfRenderWindow_display(window);
    }
}
