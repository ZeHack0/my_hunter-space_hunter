/*
** EPITECH PROJECT, 2023
** starting_project
** File description:
** my_atoi.c
*/

#include "my.h"

static int atoi_for_number(char nbr_to_convert)
{
    int number = nbr_to_convert - 48;

    return number;
}

int my_atoi(char *nbr_to_convert)
{
    int nbr = 0;
    int temp = 0;
    int multi = my_power(10, my_strlen(nbr_to_convert) - 1);

    if (my_strlen(nbr_to_convert) == 1) {
        nbr = atoi_for_number(nbr_to_convert[0]);
        return nbr;
    }
    for (int i = 0; i < my_strlen(nbr_to_convert); i++) {
        temp = atoi_for_number(nbr_to_convert[i]) * multi;
        multi = multi / 10;
        nbr += temp;
        temp = 0;
    }
    return nbr;
}
