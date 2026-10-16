/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** Permet
*/

#include "my.h"

int my_is_prime(int nb)
{
    int a = 2;

    if (nb < 2)
        return 0;
    for (; a <= nb / 2; a++) {
        if (nb % a == 0)
            return 0;
    }
    return (a);
}
