/*
** EPITECH PROJECT, 2024
** test
** File description:
** if_play_music_game
*/

#include "project.h"

void if_play_music_game(main_t *main)
{
    if (main->main_menu->if_play == 2) {
        sfMusic_stop(main->main_menu->music);
        sfMusic_destroy(main->main_menu->music);
        main->main_menu->if_play = 3;
    }
    if (main->gameplay->if_play == 2) {
        sfMusic_setVolume(main->gameplay->music, 10);
        sfMusic_play(main->gameplay->music);
        main->gameplay->if_play = 3;
    }
}
