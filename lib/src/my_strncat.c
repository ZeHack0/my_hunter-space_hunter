/*
** EPITECH PROJECT, 2023
** Day07-Libmy, arguments
** File description:
** Task02 - concatenate two strings
** non-printable characters are printed hexadecimally
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int len = my_strlen(dest);
    int i = 0;

    for (; i < nb && src[i] != '\0'; i++) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';
    return dest;
}
