/*
** EPITECH PROJECT, 2018
** str cpy
** File description:
** desc
*/
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int i = my_strlen(src);
    int j = 0;

    dest = malloc(sizeof(char) * (i+1));
    for (j; j != i; j++) {
        dest[j] = src[j];
    }
    dest[j] = '\0';
    return (dest);
}
