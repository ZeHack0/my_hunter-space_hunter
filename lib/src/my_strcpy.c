/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** Permet
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    if (src == NULL)
        return NULL;
    for (int a = 0; src[a] != '\0'; a++)
        dest[a] = src[a];
    return dest;
}
