/*
** EPITECH PROJECT, 2024
** my_secured_bs
** File description:
** my_strdup.c
*/

#include "my.h"

char *my_strdup(const char *str)
{
    int len = my_strlen(str);
    char *new_str = malloc(sizeof(char) * (len + 1));

    if (new_str == NULL && len == 0)
        return NULL;
    my_strcpy(new_str, str);
    return new_str;
}
