/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** permet de retourner le nombre de caractère dans le script
*/

#include "my.h"

int my_strlen(char const *str)
{
    int len = 0;

    if (*str == 0)
        return 0;
    for (int a = 0; str[a] != '\0'; a++)
        len++;
    return len;
}
