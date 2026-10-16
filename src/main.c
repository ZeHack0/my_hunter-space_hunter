/*
** EPITECH PROJECT, 2024
** starting_project
** File description:
** main.c
*/

#include "project.h"

static int print_help(void)
{
    my_putstr("SPACE HUNTER\n\n");
    my_putstr("USAGE\n    ./space_hunter [-h]\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    Defend your base against enemy space ships.\n");
    my_putstr("    Aim with the mouse and shoot them before they reach you.\n\n");
    my_putstr("CONTROLS\n");
    my_putstr("    Up / Down     navigate the main menu\n");
    my_putstr("    Enter         select a mode\n");
    my_putstr("    Left click    shoot (watch your laser magazine)\n");
    my_putstr("    Close window  quit the game\n");
    return 0;
}

static int run_game(void)
{
    int game_status = 0;
    sfVideoMode video_mode = {800, 600, 60};
    main_t *main = background_main_menu();
    sfRenderWindow *window = sfRenderWindow_create
        (video_mode, "Space Hunter", sfClose, NULL);

    if (window == NULL)
        return 84;
    sfRenderWindow_setFramerateLimit(window, 60);
    open_the_window(window, main, &game_status);
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return print_help();
    if (ac != 1)
        return 84;
    return run_game();
}
