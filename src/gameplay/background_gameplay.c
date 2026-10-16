/*
** EPITECH PROJECT, 2024
** test
** File description:
** background_gameplay
*/

#include "project.h"

main_t *background_gameplay(main_t *main)
{
    main->gameplay = malloc(sizeof(*main->gameplay));
    main->gameplay->background_in_gameplay =
        malloc(sizeof(*main->gameplay->background_in_gameplay));
    if (main->gameplay == NULL ||
        main->gameplay->background_in_gameplay == NULL)
        return NULL;
    main->gameplay->background_in_gameplay->texture = sfTexture_createFromFile
        ("content/background.jpg", NULL);
    main->gameplay->background_in_gameplay->sprite = sfSprite_create();
    main->gameplay->background_in_gameplay->scale = (sfVector2f) { 2.5f, 2.5f};
    main->gameplay->music =
        sfMusic_createFromFile("content/Synthwave_Sonata.mp3");
    sfSprite_setTexture(main->gameplay->background_in_gameplay->sprite,
        main->gameplay->background_in_gameplay->texture, sfTrue);
    sfSprite_setScale(main->gameplay->background_in_gameplay->sprite,
        main->gameplay->background_in_gameplay->scale);
    return main;
}
