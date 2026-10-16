/*
** EPITECH PROJECT, 2024
** test
** File description:
** create_enemies
*/

#include "project.h"

static void set_enemies_var(main_t *main, int i)
{
    main->enemies[i].sprite = sfSprite_create();
    main->enemies[i].texture =
        sfTexture_createFromFile("content/battle_space_ship.png", NULL);
    main->enemies[i].position =
        (sfVector2f){100, rand() % 300};
    main->enemies[i].scale = (sfVector2f){2.5f, 2.5f};
    main->enemies[i].rect.top = 0;
    main->enemies[i].rect.left = 0;
    main->enemies[i].rect.width = 27;
    main->enemies[i].rect.height = 29;
    main->enemies[i].clock = sfClock_create();
    main->enemies->speed = 4;
}

void create_enemies(main_t *main, int nb_enemies)
{
    srand(time(NULL));
    main->enemies = malloc(sizeof(enemies_t) * nb_enemies);
    if (main->enemies == NULL)
        return;
    for (int i = 0; i < nb_enemies; i++) {
        set_enemies_var(main, i);
        sfSprite_setTexture
            (main->enemies[i].sprite, main->enemies[i].texture, sfTrue);
        sfSprite_setPosition
            (main->enemies[i].sprite, main->enemies[i].position);
        sfSprite_setScale(main->enemies[i].sprite, main->enemies[i].scale);
        sfSprite_setTextureRect
            (main->enemies[i].sprite, main->enemies[i].rect);
    }
}
