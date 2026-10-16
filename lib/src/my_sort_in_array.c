/*
** EPITECH PROJECT, 2023
** Day04-Pointers
** File description:
** Task06 - integer array in ascending order
*/

#include "my.h"

static int find_min(int *array, int start, int size)
{
    int min = start;

    for (int i = start; i < size; i++) {
        if (*(array + i) < *(array + min))
            min = i;
    }
    return min;
}

void my_sort_int_array(int *array, int size)
{
    int temp;
    int min;

    for (int i = 0; i < size; i++) {
        min = find_min(array, i, size);
        temp = *(array + i);
        *(array + i) = *(array + min);
        *(array + min) = temp;
    }
}
