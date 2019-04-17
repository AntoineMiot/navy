/*
** EPITECH PROJECT, 2018
** str cpy
** File description:
** desc
*/
#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);

char *my_strcat_two(char *str_first, char const str_scnd)
{
    int k = 0;
    char *strrtn = malloc(sizeof(char)* (my_strlen(str_first) + 2));

    for (int i = 0; str_first[i] != '\0'; i++) {
        strrtn[k] = str_first[i];
        k++;
    }
    strrtn[k] = str_scnd;
    strrtn[k+1] = '\0';
    return (strrtn);
}