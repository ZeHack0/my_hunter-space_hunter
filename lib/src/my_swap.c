/*
** EPITECH PROJECT, 2023
** my_swap.c
** File description:
** permet d'interchanget a et b
*/

#include "../include/my.h"

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
