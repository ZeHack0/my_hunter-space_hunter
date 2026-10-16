/*
** EPITECH PROJECT, 2024
** starting_project
** File description:
** my_char_isalpha.c
*/

#include "my.h"

int my_char_isalpha(char str)
{
    if (str == 0)
        return 84;
    if (str >= 'a' && str <= 'z')
        return 0;
    if (str >= 'A' && str <= 'Z')
        return 0;
    if (str >= '0' && str <= '9')
        return 0;
    return 1;
}
