/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** score
*/

#include "project.h"

void init_score(main_t *main)
{
    sfFont *font = sfFont_createFromFile("content/space_age/space_age.ttf");

    main->gameplay->score = malloc(sizeof(*main->gameplay->score));
    if (main->gameplay->score == NULL)
        return;
    main->gameplay->score->text = sfText_create();
    main->gameplay->score->score = 0;
    main->gameplay->score->position = (sfVector2f) {569, 510};
    main->gameplay->score->scale = (sfVector2f) {0.25f, 0.25f};
    sfText_setString(main->gameplay->score->text,
        my_convert_int_to_char(main->gameplay->score->score));
    sfText_setPosition(main->gameplay->score->text,
        main->gameplay->score->position);
    sfText_setFont(main->gameplay->score->text, font);
}

void init_zone_score(main_t *main)
{
    main->gameplay->score->sprite = sfSprite_create();
    main->gameplay->score->texture =
        sfTexture_createFromFile("content/zone_for_score.png", NULL);
    main->gameplay->score->position_zone = (sfVector2f) {559, 500};
    main->gameplay->score->scale_zone = (sfVector2f) {4, 3};
    sfSprite_setTexture(main->gameplay->score->sprite,
        main->gameplay->score->texture, sfTrue);
    sfSprite_setPosition(main->gameplay->score->sprite,
        main->gameplay->score->position_zone);
    sfSprite_setScale(main->gameplay->score->sprite,
        main->gameplay->score->scale_zone);
}

static char *format_score(main_t *main)
{
    int size_score = 6 - len_int(main->gameplay->score->score);
    char *formatted_score = malloc(7);
    char score_str[12];

    if (formatted_score == NULL) {
        return NULL;
    }
    formatted_score[0] = '\0';
    for (int i = 0; i < size_score; i++) {
        my_strcat(formatted_score, "0");
    }
    sprintf(score_str, "%d", main->gameplay->score->score);
    my_strcat(formatted_score, score_str);
    return formatted_score;
}

void update_score(main_t *main)
{
    char *formatted_score = format_score(main);

    sfText_setString(main->gameplay->score->text, formatted_score);
}
