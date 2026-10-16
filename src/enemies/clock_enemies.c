/*
** EPITECH PROJECT, 2024
** test
** File description:
** clock_enemies
*/

#include "project.h"

static void flight(main_t *main, int a)
{
    if (main->enemies[a].rect.left >= 27 * 3)
        main->enemies[a].rect.left = 0;
    else
        main->enemies[a].rect.left += 27;
    sfSprite_setTextureRect(main->enemies[a].sprite, main->enemies[a].rect);
}

void clock_enemies(main_t *main, int a)
{
    sfTime time = sfClock_getElapsedTime(main->enemies[a].clock);
    float seconds = sfTime_asSeconds(time);

    if (seconds > 0.15) {
        flight(main, a);
        sfClock_restart(main->enemies[a].clock);
    }
}
