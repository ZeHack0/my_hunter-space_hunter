/*
** EPITECH PROJECT, 2023
** my_compute_power_rec
** File description:
** Permet
*/

#include "my.h"

int my_compute_power_rec(int nb, int power)
{
    int p = nb;

    if (power < 0)
        return 0;
    if (power == 0)
        return 1;
    p = nb * my_compute_power_rec(nb, power - 1);
    return p;
}
