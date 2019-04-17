/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** map victory function
*/
#include "include/my.h"

int check_map(char *map)
{
    int counter = 0;
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'x') {
            counter++;
        }
    }
    if (counter == 14)
        return (1);
    else
        return (0);
}