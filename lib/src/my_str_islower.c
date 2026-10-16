/*
** EPITECH PROJECT, 2024
** starting_project
** File description:
** my_str_islower.c
*/

#include "my.h"

int my_str_islower(char const *str)
{
    for (int a = 0; str[a] != '\0';) {
        if (str[a] >= 'a' && str[a] <= 'z')
            a++;
        else {
            mini_printf("ERROR : my_str_islower : Invalid Character '%c"
                        "'\n", str[a]);
            return 84;
        }
    }
    return 0;
}
