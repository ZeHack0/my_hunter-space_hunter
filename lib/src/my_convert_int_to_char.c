/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** my_convert_int_to_char
*/

#include "../include/my.h"

int get_number_length(int num, bool *is_negative)
{
    int length = 0;

    if (num == 0)
        return 1;
    *is_negative = (num < 0);
    if (*is_negative)
        num = -num;
    while (num > 0) {
        num /= 10;
        length++;
    }
    return length;
}

char *my_convert_int_to_char(int num)
{
    char *str = NULL;
    bool is_negative;
    int length = get_number_length(num, &is_negative);

    str = malloc(length + is_negative + 1);
    str[length + is_negative] = '\0';
    if (num == 0) {
        str[0] = '0';
        return str;
    }
    if (is_negative) {
        num = -num;
        str[0] = '-';
    }
    for (int i = length + is_negative - 1; i >= is_negative; i--) {
        str[i] = (num % 10) + '0';
        num /= 10;
    }
    return str;
}
