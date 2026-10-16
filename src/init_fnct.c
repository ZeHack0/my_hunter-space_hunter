/*
** EPITECH PROJECT, 2024
** test
** File description:
** init_fnct
*/

#include "project.h"

static void init_first_part(main_t *main, int tmp, int nb_enemies)
{
    background_gameplay(main);
    create_enemies(main, nb_enemies);
    main->enemies->nb_enemies = tmp;
    tmp = nb_enemies;
    main->enemies->nb_enemies = nb_enemies;
    create_base(main);
    create_turret(main);
    create_cursor_main_menu(main);
    set_cursor(main);
}

void init_fnct(main_t *main)
{
    int nb_enemies = 2;
    int tmp = 0;

    init_first_part(main, tmp, nb_enemies);
    malloc_shoot_base(main);
    main->gameplay->base->shoot_base->current_projectile = 0;
    shoot_base(main);
    main->gameplay->base->shoot_base->is_shoot = 0;
    main->main_menu->cursor_select_mode->pos = 1;
    main->main_menu->if_play = 0;
    main->gameplay->if_play = 0;
    main->gameplay->base->shoot_base->active = 0;
    laser_magazine_init(main);
    init_score(main);
    init_zone_score(main);
}
