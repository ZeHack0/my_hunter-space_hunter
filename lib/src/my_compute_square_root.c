/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** Permet
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int result;

    if (nb <= 0) {
        return 0;
    }
    for (int i = 1; i * i <= nb; i++) {
        if (i * i > nb) {
            return 0;
        } else {
            result = i;
        }
    }
    return (result);
}
