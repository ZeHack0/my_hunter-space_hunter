/*
** EPITECH PROJECT, 2023
** my_find__prime_sup
** File description:
** Permet
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int a = nb | 1;

    if (my_is_prime(nb))
        return nb;
    for (; a < 2147483647; a++) {
        if (my_is_prime(a))
            return (a);
    }
    return 0;
}
