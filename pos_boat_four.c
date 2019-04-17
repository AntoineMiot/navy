/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** pos boat 4
*/
#include "include/my.h"

int check_boat_four_b(char *file, variable_boat *bt)
{
    int letter1;
    int number1;
    int z = 1;
    int j = 0;

    for (int i = 65; i != 73; i++) {
        if (file[18] == i) {
            letter1 = z;
            break;
        }
        z++;
    }
    for (int i = 49; i != 58; i++) {
        if (file[19] == i) {
            number1 = j;
            break;
        }
        j++;
    }
    return (letter1 + (number1 * 8));
}

int check_boat_four_e(char *file, variable_boat *bt)
{
    int letter2;
    int number2;
    int z = 1;
    int j = 0;

    for (int i = 65; i != 73; i++) {
        if (file[21] == i) {
            letter2 = z;
            break;
        }
        z++;
    }
    for (int i = 49; i != 58; i++) {
        if (file[22] == i) {
            number2 = j;
            break;
        }
        j++;
    }
    return (letter2 + (number2 * 8));
}

int check_direction_four(char *file, variable_boat *bt)
{
    if (file[18] == file[21])
        return (-1);
    else if (file[19] == file[22])
        return (-2);
    else
        return (-3);
}

int check_boat_four(char *file, variable_boat *bt)
{
    bt->bboat_3 = check_boat_four_b(file, bt);
    bt->eboat_3 = check_boat_four_e(file, bt);
    bt->direc3 = check_direction_four(file, bt);
}
