/*
** EPITECH PROJECT, 2024
** test
** File description:
** analyse_event
*/

#include "project.h"

static void handle_menu_navigation(main_t *main, sfKeyCode key)
{
    if (key == sfKeyUp) {
        main->main_menu->cursor_select_mode->pos--;
        if (main->main_menu->cursor_select_mode->pos == 0)
            main->main_menu->cursor_select_mode->pos = 3;
    }
    if (key == sfKeyDown) {
        main->main_menu->cursor_select_mode->pos++;
        if (main->main_menu->cursor_select_mode->pos == 4)
            main->main_menu->cursor_select_mode->pos = 1;
    }
}

static void handle_menu_selection
(main_t *main, int *game_status, sfKeyCode key, sfRenderWindow *window)
{
    if (key == sfKeyEnter) {
        if (main->main_menu->cursor_select_mode->pos == 1 ||
            main->main_menu->cursor_select_mode->pos == 2) {
            *game_status = 1;
            main->main_menu->if_play = 2;
            main->enemies->nb_enemies =
                main->main_menu->cursor_select_mode->pos;
            main->gameplay->if_play = 2;
        }
        if (main->main_menu->cursor_select_mode->pos == 3)
            sfRenderWindow_close(window);
    }
}

void event_main_menu
(main_t *main, int *game_status, sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtKeyPressed) {
        handle_menu_navigation(main, event.key.code);
        handle_menu_selection(main, game_status, event.key.code, window);
    }
}

void analyse_event
(sfRenderWindow *window, sfEvent event, main_t *main, int *game_status)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (*game_status == 1) {
            event_in_game(main, mouse_pos, event);
        }
        if (*game_status == 0) {
            event_main_menu(main, game_status, event, window);
        }
    }
}
