/*
** EPITECH PROJECT, 2024
** starting_project
** File description:
** my_str_isalpha.c
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    if (str == NULL) {
        mini_printf("my_str_isalpha: null string\n");
        return 84;
    }
    for (int a = 0; str[a] != '\0'; a++) {
        if (my_char_isalpha(str[a]) == 1) {
            mini_printf("ERROR : my_char_isalpha: invalid charact"
                        "er '%c'\n", str[a]);
            return 84;
        }
    }
    return 0;
}
