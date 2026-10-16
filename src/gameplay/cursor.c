/*
** EPITECH PROJECT, 2024
** test
** File description:
** cursor
*/

#include "project.h"

void set_cursor(main_t *main)
{
    main->gameplay->cursor_game = malloc(sizeof(*main->gameplay->cursor_game));
    if (main->gameplay->cursor_game == NULL)
        return;
    main->gameplay->cursor_game->sprite = sfSprite_create();
    main->gameplay->cursor_game->texture = sfTexture_createFromFile
        ("content/cursor.png", NULL);
    main->gameplay->cursor_game->scale = (sfVector2f) {0.8f, 0.8f};
    sfSprite_setTexture(main->gameplay->cursor_game->sprite,
        main->gameplay->cursor_game->texture, sfTrue);
    sfSprite_setScale(main->gameplay->cursor_game->sprite,
        main->gameplay->cursor_game->scale);
}
