/*
** EPITECH PROJECT, 2024
** test
** File description:
** turret
*/

#include "project.h"

void create_turret(main_t *main)
{
    main->gameplay->base->turret =
        malloc(sizeof(*main->gameplay->base->turret));
    if (main->gameplay->base->turret == NULL)
        return;
    main->gameplay->base->turret->sprite = sfSprite_create();
    main->gameplay->base->turret->texture =
        sfTexture_createFromFile("content/turret.png", NULL);
    main->gameplay->base->turret->position = (sfVector2f) {367.5f, 444};
    main->gameplay->base->turret->origin = (sfVector2f) {9.5f, 19};
    sfSprite_setTexture(main->gameplay->base->turret->sprite,
        main->gameplay->base->turret->texture, sfTrue);
    sfSprite_setPosition(main->gameplay->base->turret->sprite,
        main->gameplay->base->turret->position);
    sfSprite_setOrigin(main->gameplay->base->turret->sprite,
        main->gameplay->base->turret->origin);
}

void set_rotation_turret(main_t *main, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    float adjacent = main->gameplay->base->turret->position.x -
        (float)mouse_pos.x;
    float opposite = main->gameplay->base->turret->position.y -
        (float)mouse_pos.y;
    float angle = (float)atan2((double)opposite, (double)adjacent);
    float degrees = angle * (float)(180.0 / M_PI);

    degrees -= 90;
    sfSprite_setRotation(main->gameplay->base->turret->sprite, degrees);
}
