/*
** EPITECH PROJECT, 2024
** test
** File description:
** shoot_base
*/

#include "project.h"

void malloc_shoot_base(main_t *main)
{
    main->gameplay->base->shoot_base =
        malloc(sizeof(*main->gameplay->base->shoot_base) * 4);
    if (main->gameplay->base->shoot_base == NULL)
        return;
}

static void init_var_shoot(main_t *main, int i)
{
    main->gameplay->base->shoot_base[i].sprite = sfSprite_create();
    main->gameplay->base->shoot_base[i].texture =
        sfTexture_createFromFile("content/laser.png", NULL);
    main->gameplay->base->shoot_base[i].position =
        (sfVector2f){main->gameplay->base->turret->position.x,
                        main->gameplay->base->turret->position.y};
    main->gameplay->base->shoot_base[i].copy_position =
        (sfVector2f){main->gameplay->base->turret->position.x,
                        main->gameplay->base->turret->position.y};
    main->gameplay->base->shoot_base[i].direction = (sfVector2f){0.0f, 0.0f};
    main->gameplay->base->shoot_base[i].speed = 0.0f;
    main->gameplay->base->shoot_base[i].active = 0;
    main->gameplay->base->shoot_base[i].scale = (sfVector2f){0.05f, 0.05f};
    main->gameplay->base->shoot_base[i].origin = (sfVector2f){180, 72};
}

void shoot_base(main_t *main)
{
    for (int i = main->gameplay->
        base->shoot_base->current_projectile; i != 4; i++) {
        init_var_shoot(main, i);
        sfSprite_setTexture(main->gameplay->base->shoot_base[i].sprite,
                            main->gameplay->base->shoot_base[i].texture,
                            sfTrue);
        sfSprite_setPosition(main->gameplay->base->shoot_base[i].sprite,
                                main->gameplay->base->shoot_base[i].position);
        sfSprite_setRotation(main->gameplay->base->shoot_base[i].sprite, -90);
        sfSprite_setOrigin(main->gameplay->base->shoot_base[i].sprite,
            main->gameplay->base->shoot_base[i].origin);
    }
}

void fire_projectile(main_t *main, sfVector2i mouse_pos, int i)
{
    sfVector2f target = {(float)mouse_pos.x, (float)mouse_pos.y};
    sfVector2f direction = {
        target.x - main->gameplay->base->shoot_base[i].position.x,
        target.y - main->gameplay->base->shoot_base[i].position.y
    };
    float length =
        sqrtf(direction.x * direction.x + direction.y * direction.y);

    main->gameplay->base->shoot_base[i].direction =
        (sfVector2f){direction.x / length, direction.y / length};
    main->gameplay->base->shoot_base[i].speed = 5000.0f;
    main->gameplay->base->shoot_base[i].position =
        main->gameplay->base->turret->position;
    sfSprite_setPosition(main->gameplay->base->shoot_base[i].sprite,
                            main->gameplay->base->shoot_base[i].position);
}

static void init_var_projectile(main_t *main, int i, float delta_time)
{
    main->gameplay->base->shoot_base[i].position.x +=
        main->gameplay->base->shoot_base[i].direction.x *
        main->gameplay->base->shoot_base[i].speed * delta_time;
    main->gameplay->base->shoot_base[i].position.y +=
        main->gameplay->base->shoot_base[i].direction.y *
        main->gameplay->base->shoot_base[i].speed * delta_time;
}

void update_projectile(main_t *main, float delta_time, int i)
{
    if (main->gameplay->base->shoot_base[i].active == 1) {
        init_var_projectile(main, i, delta_time);
        if (main->gameplay->base->shoot_base[i].position.x < 0 ||
        main->gameplay->base->shoot_base[i].position.x > 800 ||
        main->gameplay->base->shoot_base[i].position.y < 0 ||
        main->gameplay->base->shoot_base[i].position.y > 600) {
            main->gameplay->base->shoot_base[i].position =
            (sfVector2f){main->gameplay->base->turret->position.x,
                            main->gameplay->base->turret->position.y};
            main->gameplay->base->shoot_base[i].active = 0;
        }
        sfSprite_setPosition(main->gameplay->base->shoot_base[i].sprite,
        main->gameplay->base->shoot_base[i].position);
    }
}

void set_rotation_shoot(main_t *main, sfRenderWindow *window, int i)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    float adjacent = main->gameplay->base->turret->position.x -
        (float)mouse_pos.x;
    float opposite = main->gameplay->base->turret->position.y -
        (float)mouse_pos.y;
    float angle = (float)atan2((double)opposite, (double)adjacent);
    float degrees = angle * (float)(180.0 / M_PI);

    degrees -= 90;
    if (main->gameplay->base->shoot_base->is_shoot == 0 &&
        main->gameplay->base->shoot_base[i].active == 0)
        sfSprite_setRotation(main->gameplay->base->shoot_base[i].sprite,
            degrees - 90);
}
