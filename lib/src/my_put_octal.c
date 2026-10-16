/*
** EPITECH PROJECT, 2024
** starting_project
** File description:
** my_put_octal.c
*/

#include "my.h"

void my_put_octal(int nb)
{
    int res;

    if (nb >= 8) {
        res = nb % 8;
        nb = nb / 8;
        my_put_octal(nb);
    } else if (nb > 0) {
        res = nb % 8;
        nb = nb / 8;
    }
    my_putchar(res + 48);
}
