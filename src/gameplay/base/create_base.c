/*
** EPITECH PROJECT, 2024
** test
** File description:
** create_base
*/

#include "project.h"

void create_base(main_t *main)
{
    main->gameplay->base = malloc(sizeof(*main->gameplay->base));
    main->gameplay->base->sprite = sfSprite_create();
    main->gameplay->base->texture =
        sfTexture_createFromFile("content/base.png", NULL);
    main->gameplay->base->position = (sfVector2f) {400, 523};
    main->gameplay->base->scale = (sfVector2f) {2, 2};
    main->gameplay->base->origin = (sfVector2f) {25.5f, 59};
    sfSprite_setOrigin
        (main->gameplay->base->sprite, main->gameplay->base->origin);
    sfSprite_setTexture(main->gameplay->base->sprite,
        main->gameplay->base->texture, sfTrue);
    sfSprite_setPosition
        (main->gameplay->base->sprite, main->gameplay->base->position);
    sfSprite_setScale
        (main->gameplay->base->sprite, main->gameplay->base->scale);
}
