/*
** EPITECH PROJECT, 2018
** str cpy
** File description:
** desc
*/
#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcat_two(char *str_first, char const str_scnd);

char *my_revstr(char *str)
{
    char *strrtn = malloc(sizeof(char));

    for (int i = my_strlen(str); i != -1; i--)
        strrtn = my_strcat_two(strrtn, str[i]);
    return (strrtn);
}