/*
** EPITECH PROJECT, 2023
** Day06-Pointers are back
** File description:
** Test - Task05 - finds the first occurrence of s2 in s1
*/

#include "my.h"

static int check_is_eqqal(char *str, char const *to_find, int i)
{
    int j = 0;

    while (str[i + j] == to_find[j]) {
        if (to_find[j +1] == '\0')
            return 1;
        j++;
    }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    char *rtrn = 0;

    if (str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == to_find[0] && check_is_eqqal(str, to_find, i))
            rtrn = str + i;
    return rtrn;
}
