/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** strcat.c
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_len = 0;
    int src_len = 0;

    while (dest[dest_len] != '\0') {
        dest_len++;
    }
    while (src[src_len] != '\0') {
        src_len++;
    }
    dest = realloc(dest, dest_len + src_len + 1);
    if (dest == NULL) {
        return NULL;
    }
    for (int i = 0; i < src_len; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + src_len] = '\0';
    return dest;
}
