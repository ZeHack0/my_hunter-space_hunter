/*
** EPITECH PROJECT, 2024
** starting_project
** File description:
** project.h
*/

#ifndef STARTING_PROJECT_PROJECT_H
    #define STARTING_PROJECT_PROJECT_H

    #include "my.h"
    #include <time.h>
    #include <math.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <sys/stat.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Network.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio/Music.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/System/Clock.h>
    #include <SFML/Graphics/Rect.h>

typedef struct laser_magazine_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f position;
    int state;
} laser_magazine_t;

typedef struct score_s {
    sfText *text;
    sfVector2f position;
    sfVector2f scale;
    int score;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position_zone;
    sfVector2f scale_zone;
} score_t;

typedef struct shoot_base_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f position;
    sfVector2f copy_position;
    sfVector2f direction;
    sfVector2f origin;
    int is_shoot;
    float speed;
    int active;
    int current_projectile;
} shoot_base_t;

typedef struct turret_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f position;
    sfVector2f origin;
} turret_t;

typedef struct base_s {
    shoot_base_t *shoot_base;
    turret_t *turret;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f position;
    sfVector2f origin;
} base_t;

typedef struct enemies_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f position;
    sfIntRect rect;
    sfClock *clock;
    int nb_enemies;
    int kill_enemies;
    double speed;
} enemies_t;

typedef struct background_in_gameplay_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
} background_in_gameplay_t;

typedef struct background_in_main_menu_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
} background_in_main_menu_t;

typedef struct cursor_select_mode_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f position;
    int pos;
} cursor_select_mode_t;

typedef struct cursor_game_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f position;
} cursor_game_t;

typedef struct main_menu_s {
    cursor_select_mode_t *cursor_select_mode;
    background_in_main_menu_t *background_in_main_menu;
    sfMusic *music;
    int if_play;
} main_menu_t;

typedef struct gameplay_s {
    laser_magazine_t *laser_magazine;
    cursor_game_t *cursor_game;
    base_t *base;
    background_in_gameplay_t *background_in_gameplay;
    sfMusic *music;
    score_t *score;
    int if_play;
} gameplay_t;

typedef struct main_s {
    enemies_t *enemies;
    gameplay_t *gameplay;
    main_menu_t *main_menu;
} main_t;

main_t *background_main_menu(void);
main_t *background_gameplay(main_t *main);
void analyse_event
(sfRenderWindow *window, sfEvent event, main_t *main, int *game_status);
void open_the_window(sfRenderWindow *window, main_t *main, int *game_status);
void create_enemies(main_t *main, int nb_enemies);
void clock_enemies(main_t *main, int a);
void create_base(main_t *main);
void create_cursor_main_menu(main_t *main);
void change_pos_selector_menu(main_t *main);
void if_play_music_main_menu(main_t *main);
void if_play_music_game(main_t *main);
void set_cursor(main_t *main);
void create_turret(main_t *main);
void set_rotation_turret(main_t *main, sfRenderWindow *window);
void shoot_base(main_t *main);
void fire_projectile(main_t *main, sfVector2i mouse_pos, int i);
void update_projectile(main_t *main, float delta_time, int i);
void event_in_game(main_t *main, sfVector2i mouse_pos, sfEvent event);
void init_fnct(main_t *main);
void set_rotation_shoot(main_t *main, sfRenderWindow *window, int i);
void malloc_shoot_base(main_t *main);
void laser_magazine_init(main_t *main);
void check_state_magazine(main_t *main);


void init_score(main_t *main);
void update_score(main_t *main);
void init_zone_score(main_t *main);

#endif //STARTING_PROJECT_PROJECT_H
