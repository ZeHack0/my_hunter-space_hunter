/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** Permet
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int sign = 1;
    int i = 0;
    int value = 0;

    while (str[i] != '\0') {
        if (str[i] == '-') {
            sign = sign * - 1;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            value = value * 10;
            value = value + (str[i]) - '0';
        }
        i++;
    }
    value = value * sign;
    return value;
}
