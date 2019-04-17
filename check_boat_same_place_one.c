/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** main function
*/
#include "include/my.h"

int check_boat_diff_pos_scnd_two(int tmp1, int tmp2)
{
    if (tmp1 == tmp2)
        exiterr();
}

int check_boat_diff_pos_scnd(variable_boat *bt, int bboat, int z)
{
    int tmp1 = bt->bboat_1;
    int tmp2 = bboat;

    while (tmp1 != bt->bboat_1 + (2*8)) {
        tmp2 = bboat;
        while (tmp2 != bboat + z) {
            check_boat_diff_pos_scnd_two(tmp1, tmp2);
            tmp2++;
        }
        tmp1 = tmp1 + 8;
    }
}

int check_boat_diff_pos(variable_boat *bt, int bboat, int z, int direc)
{
    if (bt->direc1 == -1 && direc == -2)
        check_boat_diff_pos_scnd(bt, bboat, z);
    return (0);
}