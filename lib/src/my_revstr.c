/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** Permet
*/

#include "my.h"

char *my_revstr(char *str)
{
    int b = my_strlen(str) - 1;
    char c = 0;

    for (int a = 0; a <= b; a++) {
        c = str[a];
        str[a] = str[b];
        str[b] = c;
        b--;
    }
    return str;
}
