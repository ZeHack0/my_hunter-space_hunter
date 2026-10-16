/*
** EPITECH PROJECT, 2023
** starting_project
** File description:
** my_square.c
*/

#include "my.h"

int my_power(int nbr, int power)
{
    int result = nbr;

    power--;
    while (power > 0) {
        result = result * nbr;
        power--;
    }
    return result;
}
