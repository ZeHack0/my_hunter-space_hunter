/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** nb_shoot
*/

#include "project.h"

void check_state_magazine(main_t *main)
{
    if (main->gameplay->laser_magazine->state == 1)
        main->gameplay->laser_magazine->texture =
            sfTexture_createFromFile("content/magazine_empty.png", NULL);
    if (main->gameplay->laser_magazine->state == 2)
        main->gameplay->laser_magazine->texture =
            sfTexture_createFromFile("content/magazine_1_4.png", NULL);
    if (main->gameplay->laser_magazine->state == 3)
        main->gameplay->laser_magazine->texture =
            sfTexture_createFromFile("content/magazine_2_4.png", NULL);
    if (main->gameplay->laser_magazine->state == 4)
        main->gameplay->laser_magazine->texture =
            sfTexture_createFromFile("content/magazine_3_4.png", NULL);
    if (main->gameplay->laser_magazine->state == 5)
        main->gameplay->laser_magazine->texture =
            sfTexture_createFromFile("content/magazine_max.png", NULL);
    sfSprite_setTexture(main->gameplay->laser_magazine->sprite,
        main->gameplay->laser_magazine->texture, sfTrue);
}

void laser_magazine_init(main_t *main)
{
    main->gameplay->laser_magazine =
        malloc(sizeof(*main->gameplay->laser_magazine));
    if (main->gameplay->laser_magazine == NULL)
        return;
    main->gameplay->laser_magazine->sprite = sfSprite_create();
    main->gameplay->laser_magazine->texture =
        sfTexture_createFromFile("content/magazine_max.png", NULL);
    main->gameplay->laser_magazine->position = (sfVector2f){50, 500};
    main->gameplay->laser_magazine->state = 5;
    main->gameplay->laser_magazine->scale = (sfVector2f){3, 3};
    sfSprite_setTexture(main->gameplay->laser_magazine->sprite,
        main->gameplay->laser_magazine->texture, sfTrue);
    sfSprite_setPosition(main->gameplay->laser_magazine->sprite,
        main->gameplay->laser_magazine->position);
    sfSprite_setScale(main->gameplay->laser_magazine->sprite,
        main->gameplay->laser_magazine->scale);
}
