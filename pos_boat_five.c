/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** pos boat 5
*/
#include "include/my.h"

int check_boat_five_b(char *file, variable_boat *bt)
{
    int letter1;
    int number1;
    int z = 1;
    int j = 0;

    for (int i = 65; i != 73; i++) {
        if (file[26] == i) {
            letter1 = z;
            break;
        }
        z++;
    }
    for (int i = 49; i != 58; i++) {
        if (file[27] == i) {
            number1 = j;
            break;
        }
        j++;
    }
    return (letter1 + (number1 * 8));
}

int check_boat_five_e(char *file, variable_boat *bt)
{
    int letter2;
    int number2;
    int z = 1;
    int j = 0;

    for (int i = 65; i != 73; i++) {
        if (file[29] == i) {
            letter2 = z;
            break;
        }
        z++;
    }
    for (int i = 49; i != 58; i++) {
        if (file[30] == i) {
            number2 = j;
            break;
        }
        j++;
    }
    return (letter2 + (number2 * 8));
}

int check_direction_five(char *file, variable_boat *bt)
{
    if (file[26] == file[29])
        return (-1);
    else if (file[27] == file[30])
        return (-2);
    else
        return (-3);
}

int check_boat_five(char *file, variable_boat *bt)
{
    bt->bboat_4 = check_boat_five_b(file, bt);
    bt->eboat_4 = check_boat_five_e(file, bt);
    bt->direc4 = check_direction_five(file, bt);
}