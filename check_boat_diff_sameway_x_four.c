/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** main function
*/
#include "include/my.h"

int check_boat_diff_sameway_two_scnd_two(int tmp1, int tmp2)
{
    if (tmp1 == tmp2)
        exiterr();
}

int check_boat_diff_sameway_two_scnd(variable_boat *bt, int bboat,
int eboat)
{
    int tmp1 = bt->bboat_2;
    int tmp2 = bboat;

    while (tmp1 != bt->eboat_2 + 1) {
        tmp2 = bboat;
        while (tmp2 != eboat + 1) {
            check_boat_diff_sameway_two_scnd_two(tmp1, tmp2);
            tmp2++;
        }
        tmp1++;
    }
}

int check_boat_diff_sameway_two(variable_boat *bt, int bboat,
int eboat, int direc)
{
    if (bt->direc2 == -2 && direc == -2) {
        if (check_boat_diff_sameway_two_scnd(bt, bboat, eboat) == 84)
            return (84);
    }
    return (0);
}