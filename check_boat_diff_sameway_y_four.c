/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** main function
*/
#include "include/my.h"

int check_boat_diff_sameway_y_three_scnd_two(int tmp1, int tmp2)
{
    if (tmp1 == tmp2)
        exiterr();
}

int check_boat_diff_sameway_y_three_scnd(variable_boat *bt, int bboat,
int eboat)
{
    int tmp1 = bt->bboat_3;
    int tmp2 = bboat;

    while (tmp1 != bt->eboat_3 + 8) {
        tmp2 = bboat;
        while (tmp2 != eboat + 8) {
            check_boat_diff_sameway_y_three_scnd_two(tmp1, tmp2);
            tmp2 = tmp2 + 8;
        }
        tmp1 = tmp1 + 8;
    }
}

int check_boat_diff_sameway_y_three(variable_boat *bt, int bboat,
int eboat, int direc)
{
    if (bt->direc3 == -1 && direc == -1)
        check_boat_diff_sameway_y_three_scnd(bt, bboat, eboat);
    return (0);
}