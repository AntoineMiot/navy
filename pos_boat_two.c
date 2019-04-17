/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** pos boat 3
*/
#include "include/my.h"

int check_boat_two_b(char *file, variable_boat *bt)
{
    int letter1;
    int number1;
    int z = 1;
    int j = 0;

    for (int i = 65; i != 73; i++) {
        if (file[2] == i) {
            letter1 = z;
            break;
        }
        z++;
    }
    for (int i = 49; i != 58; i++) {
        if (file[3] == i) {
            number1 = j;
            break;
        }
        j++;
    }
    return (letter1 + (number1 * 8));
}

int check_boat_two_e(char *file, variable_boat *bt)
{
    int letter2;
    int number2;
    int z = 1;
    int j = 0;

    for (int i = 65; i != 73; i++) {
        if (file[5] == i) {
            letter2 = z;
            break;
        }
        z++;
    }
    for (int i = 49; i != 58; i++) {
        if (file[6] == i) {
            number2 = j;
            break;
        }
        j++;
    }
    return (letter2 + (number2 * 8));
}

int check_direction_two(char *file, variable_boat *bt)
{
    if (file[2] == file[5])
        return (-1);
    else if (file[3] == file[6])
        return (-2);
    else
        return (-3);
}

int check_boat_two(char *file, variable_boat *bt)
{
    bt->bboat_1 = check_boat_two_b(file, bt);
    bt->eboat_1 = check_boat_two_e(file, bt);
    bt->direc1 = check_direction_two(file, bt);
}
