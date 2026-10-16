/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** Permet
*/

#include "my.h"

static int fnct(const char *format, va_list list, int a)
{
    if (format[a + 1] == 'd')
        my_put_nbr(va_arg(list, int));
    if (format[a + 1] == 'i')
        my_put_nbr(va_arg(list, int));
    if (format[a + 1] == 's')
        my_putstr(va_arg(list, char *));
    if (format[a + 1] == 'c')
        my_putchar(va_arg(list, int));
    if (format[a + 1] == '%')
        my_putchar('%');
    return 0;
}

int mini_printf(const char *format, ...)
{
    va_list list;
    int a = 0;

    va_start(list, format);
    for (; format[a] != '\0'; a++) {
        if (format[a] == '%') {
            fnct(format, list, a);
            a++;
        } else
            my_putchar(format[a]);
    }
    va_end(list);
    return 0;
}
