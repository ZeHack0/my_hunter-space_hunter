/*
** EPITECH PROJECT, 2024
** starting_project
** File description:
** my_put_hexa.c
*/

#include "my.h"

static int check_maj_or_lower(int base)
{
    if (base == 0)
        return 97;
    else
        return 65;
}

static int error_handling(unsigned int nb_to_convert, int base)
{
    if (nb_to_convert <= 0) {
        mini_printf("ERROR = nb unvalidated");
        return 84;
    }
    if (base < 0 || base > 1) {
        mini_printf("ERROR = size unvalidated (0 for lowercase || "
                        "1 for uppercase), your size is = %d", base);
        return 84;
    }
    return 0;
}

static char *conversion(int nb_to_convert, int w, int modulo, char *str)
{
    for (int i = 0; nb_to_convert != 0; i++) {
        modulo = nb_to_convert % 16;
        if (modulo > 9)
            str[i] = modulo + w - 10;
        else
            str[i] = modulo + 48;
        nb_to_convert /= 16;
    }
    return str;
}

int my_put_hexa(int nb_to_convert, int base)
{
    int modulo = 0;
    char *str = NULL;
    int len = 1;
    unsigned int cpy = nb_to_convert;
    int w = 0;

    if (error_handling(nb_to_convert, base) == 84)
        return 84;
    w = check_maj_or_lower(base);
    for (; cpy > 15; len++)
        cpy /= 16;
    str = malloc(sizeof(char) * (len + 1));
    conversion(nb_to_convert, w, modulo, str);
    str[len] = '\0';
    my_putstr(my_revstr(str));
    return len;
}
