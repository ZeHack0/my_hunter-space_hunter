/*
** EPITECH PROJECT, 2023
** my_isneg.c
** File description:
** permet d'afficher les chiffres
*/

#include "my.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else if (n <= 0){
        my_putchar('N');
    }
    return 0;
}
