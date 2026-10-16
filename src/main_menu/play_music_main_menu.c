/*
** EPITECH PROJECT, 2024
** test
** File description:
** play_music_main_menu
*/

#include "project.h"

void if_play_music_main_menu(main_t *main)
{
    if (main->main_menu->if_play == 0) {
        sfMusic_setVolume(main->main_menu->music, 10);
        sfMusic_play(main->main_menu->music);
        main->main_menu->if_play = 1;
    }
}
