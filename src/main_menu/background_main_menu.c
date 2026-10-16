/*
** EPITECH PROJECT, 2024
** test
** File description:
** backgorund_main_menu
*/

#include "project.h"

main_t *background_main_menu(void)
{
    main_t *main = malloc(sizeof(main_t));

    main->main_menu = malloc(sizeof(main_menu_t));
    main->main_menu->background_in_main_menu =
        malloc(sizeof(background_in_main_menu_t));
    main->main_menu->background_in_main_menu->texture =
        sfTexture_createFromFile("content/main_menu.png", NULL);
    main->main_menu->background_in_main_menu->sprite = sfSprite_create();
    main->main_menu->background_in_main_menu->scale =
        (sfVector2f){0.78f, 0.78f};
    main->main_menu->music =
        sfMusic_createFromFile("content/Cosmic_Cadence.mp3");
    sfSprite_setTexture(main->main_menu->background_in_main_menu->sprite,
        main->main_menu->background_in_main_menu->texture, sfTrue);
    sfSprite_setScale(main->main_menu->background_in_main_menu->sprite,
        main->main_menu->background_in_main_menu->scale);
    return main;
}
