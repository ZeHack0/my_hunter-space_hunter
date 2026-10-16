/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** Permet
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int size)
{
    int a = 0;

    while (*s1 != '\0' && *s2 != '\0' && a < size) {
        if (*s1 != *s2) {
            return (1);
        }
        s1++;
        s2++;
        a++;
    }
    return (0);
}
