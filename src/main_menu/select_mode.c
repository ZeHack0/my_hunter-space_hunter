/*
** EPITECH PROJECT, 2024
** test
** File description:
** select_mode
*/

#include "project.h"

void change_pos_selector_menu(main_t *main)
{
    if (main->main_menu->cursor_select_mode->pos == 1)
        main->main_menu->cursor_select_mode->position =
            (sfVector2f) {251.5f, 267.5f};
    if (main->main_menu->cursor_select_mode->pos == 2)
        main->main_menu->cursor_select_mode->position =
            (sfVector2f) {251.5f, 336};
    if (main->main_menu->cursor_select_mode->pos == 3)
        main->main_menu->cursor_select_mode->position =
            (sfVector2f) {251.5f, 410.5f};
    sfSprite_setPosition(main->main_menu->cursor_select_mode->sprite,
                            main->main_menu->cursor_select_mode->position);
}

void create_cursor_main_menu(main_t *main)
{
    main->main_menu->cursor_select_mode = malloc(sizeof(*main->main_menu->
                                                    cursor_select_mode));
    if (main->main_menu->cursor_select_mode == NULL)
        return;
    main->main_menu->cursor_select_mode->sprite = sfSprite_create();
    main->main_menu->cursor_select_mode->texture = sfTexture_createFromFile
        ("content/select_mode.png", NULL);
    main->main_menu->cursor_select_mode->scale = (sfVector2f) {0.8f, 0.8f};
    sfSprite_setTexture(main->main_menu->cursor_select_mode->sprite,
                            main->main_menu->cursor_select_mode->texture,
                            sfTrue);
    sfSprite_setScale(main->main_menu->cursor_select_mode->sprite,
                            main->main_menu->cursor_select_mode->scale);
}
