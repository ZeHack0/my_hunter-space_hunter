##
## EPITECH PROJECT, 2023
## __
## File description:
## sources.mk
##

VPATH += src/
src += main.c
src += window.c
src += init_fnct.c

VPATH += src/main_menu/
src += background_main_menu.c
src += select_mode.c
src += play_music_main_menu.c

VPATH += src/gameplay/
src += background_gameplay.c
src += if_play_music_game.c
src += cursor.c

VPATH += src/event/
src += analyse_event.c
src += event_in_game.c

VPATH += src/enemies/
src += create_enemies.c
src += clock_enemies.c

VPATH += src/gameplay/base/
src += create_base.c
src += turret.c
src += shoot_base.c

VPATH += src/gameplay/score/
src += score.c

VPATH += src/gameplay/magazine/
src += laser_magazine.c
