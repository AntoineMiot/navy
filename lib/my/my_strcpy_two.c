/*
** EPITECH PROJECT, 2018
** str cpy
** File description:
** desc
*/
#include <stdlib.h>

char *my_strcpy_two(char *dest, char const src)
{
    int i = 1;
    int j = 0;

    dest = malloc(sizeof(char) * (i+1));
    for (j; j != i; j++) {
        dest[j] = src;
    }
    dest[j] = '\0';
    return (dest);
}