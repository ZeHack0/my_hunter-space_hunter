/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** .
*/

#ifndef MY_H
    #define MY_H

    #include <stdio.h>
    #include <fcntl.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Color.h>

typedef struct node_s {
    char *value;
    struct node_s *next;
} node_t;

int mini_printf(const char *format, ...);
int my_atoi(char *nbr_to_convert);
int my_char_isalpha(char str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
char *my_convert_int_to_char(int num);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int nb);
int len_int(int number);
int my_power(int nbr, int power);
int my_put_hexa(int nb_to_convert, int base);
int my_put_nbr(int nb);
void my_put_octal(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
void my_sort_int_array(int *array, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isupper(char const *str);
char **my_str_to_word_array(const char *str, const char *separator);
char *my_strcat(char *str1, const char *str2);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(const char *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int size);
char *my_strncpy(char *dest, char const *src, int num);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);

//node_t *init_node(char *value);

#endif //MY_H
