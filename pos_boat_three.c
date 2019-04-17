/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** pos boat 3
*/
#include "include/my.h"

int check_boat_three_b(char *file, variable_boat *bt)
{
    int letter1;
    int number1;
    int z = 1;
    int j = 0;

    for (int i = 65; i != 73; i++) {
        if (file[10] == i) {
            letter1 = z;
            break;
        }
        z++;
    }
    for (int i = 49; i != 58; i++) {
        if (file[11] == i) {
            number1 = j;
            break;
        }
        j++;
    }
    return (letter1 + (number1 * 8));
}

int check_boat_three_e(char *file, variable_boat *bt)
{
    int letter2;
    int number2;
    int z = 1;
    int j = 0;

    for (int i = 65; i != 73; i++) {
        if (file[13] == i) {
            letter2 = z;
            break;
        }
        z++;
    }
    for (int i = 49; i != 58; i++) {
        if (file[14] == i) {
            number2 = j;
            break;
        }
        j++;
    }
    return (letter2 + (number2 * 8));
}

int check_direction_three(char *file, variable_boat *bt)
{
    if (file[10] == file[13])
        return (-1);
    else if (file[11] == file[14])
        return (-2);
    else
        return (-3);
}

int check_boat_three(char *file, variable_boat *bt)
{
    bt->bboat_2 = check_boat_three_b(file, bt);
    bt->eboat_2 = check_boat_three_e(file, bt);
    bt->direc2 = check_direction_three(file, bt);
}