/*
** EPITECH PROJECT, 2024
** test
** File description:
** event_in_game
*/

#include "project.h"

static void check_music(void)
{
    sfSoundBuffer *buffer;
    sfSound *sound;

    buffer = sfSoundBuffer_createFromFile("content/sound_blaster.mp3");
    sound = sfSound_create();
    sfSound_setBuffer(sound, buffer);
    sfSound_setVolume(sound, 50);
    sfSound_play(sound);
}

static void check_shoot(main_t *main, sfVector2i mouse_pos)
{
    fire_projectile(main, mouse_pos,
        main->gameplay->base->shoot_base->current_projectile);
    main->gameplay->base->shoot_base[main->
        gameplay->base->shoot_base->current_projectile].active = 1;
}

static void check_enemies(main_t *main, sfVector2i mouse_pos)
{
    sfFloatRect enemies_bounds;
    sfFloatRect enemies_2_bounds;

    enemies_bounds = sfSprite_getGlobalBounds(main->enemies[0].sprite);
    if (sfFloatRect_contains(&enemies_bounds, (float)mouse_pos.x,
        (float)mouse_pos.y)) {
        main->enemies[0].position = (sfVector2f) {-150, rand() % 300};
        main->enemies->speed += 0.25f;
        main->gameplay->laser_magazine->state++;
        main->gameplay->score->score += 50;
    }
    if (main->enemies->nb_enemies == 2) {
        enemies_2_bounds = sfSprite_getGlobalBounds(main->enemies[1].sprite);
        if (sfFloatRect_contains(&enemies_2_bounds, (float)mouse_pos.x,
            (float)mouse_pos.y)) {
            main->enemies->speed += 0.5f;
            main->enemies[1].position = (sfVector2f) {-150, rand() % 300};
            main->gameplay->laser_magazine->state++;
        }
    }
}

void event_in_game(main_t *main, sfVector2i mouse_pos, sfEvent event)
{
    sfSprite_setPosition(main->gameplay->cursor_game->sprite, (sfVector2f)
                                    {(float)mouse_pos.x - 18,
                                        (float)mouse_pos.y - 18});
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft &&
            main->gameplay->laser_magazine->state != 1) {
        if (main->gameplay->laser_magazine->state != 1)
            main->gameplay->laser_magazine->state--;
        check_music();
        check_shoot(main, mouse_pos);
        check_enemies(main, mouse_pos);
    }
}
