/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** Permet de séparer un part un les caractères de la chaine
*/

#include "my.h"

int my_putstr(char const *str)
{
    int len = my_strlen(str);

    if (*str == 0)
        return 0;
    write(1, str, len);
    return 0;
}
