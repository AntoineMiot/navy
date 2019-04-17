/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** main function
*/
#include "include/my.h"

int check_boat_diff_pos_distrib_one(variable_boat *bt)
{
    return
    (check_boat_diff_sameway_y(bt, bt->bboat_2, bt->eboat_2, bt->direc2)+
    check_boat_diff_sameway_y(bt, bt->bboat_3, bt->eboat_3, bt->direc3)+
    check_boat_diff_sameway_y(bt, bt->bboat_4, bt->eboat_4, bt->direc4)+
    check_boat_diff_sameway_y_two(bt, bt->bboat_1, bt->eboat_1, bt->direc1)+
    check_boat_diff_sameway_y_two(bt, bt->bboat_3, bt->eboat_3, bt->direc3)+
    check_boat_diff_sameway_y_two(bt, bt->bboat_4, bt->eboat_4, bt->direc4)+
    check_boat_diff_sameway_y_three(bt, bt->bboat_1, bt->eboat_1, bt->direc1)+
    check_boat_diff_sameway_y_three(bt, bt->bboat_2, bt->eboat_2, bt->direc2)+
    check_boat_diff_sameway_y_three(bt, bt->bboat_4, bt->eboat_4, bt->direc4)+
    check_boat_diff_sameway_y_four(bt, bt->bboat_1, bt->eboat_1, bt->direc1)+
    check_boat_diff_sameway_y_four(bt, bt->bboat_2, bt->eboat_2, bt->direc2)+
    check_boat_diff_sameway_y_four(bt, bt->bboat_3, bt->eboat_3, bt->direc3));
}

int check_boat_diff_pos_distrib_two(variable_boat *bt)
{
    return
    (check_boat_diff_sameway(bt, bt->bboat_2, bt->eboat_2, bt->direc2)+
    check_boat_diff_sameway(bt, bt->bboat_3, bt->eboat_3, bt->direc3)+
    check_boat_diff_sameway(bt, bt->bboat_4, bt->eboat_4, bt->direc4)+
    check_boat_diff_sameway_two(bt, bt->bboat_1, bt->eboat_1, bt->direc1)+
    check_boat_diff_sameway_two(bt, bt->bboat_3, bt->eboat_3, bt->direc3)+
    check_boat_diff_sameway_two(bt, bt->bboat_4, bt->eboat_4, bt->direc4)+
    check_boat_diff_sameway_three(bt, bt->bboat_1, bt->eboat_1, bt->direc1)+
    check_boat_diff_sameway_three(bt, bt->bboat_2, bt->eboat_2, bt->direc2)+
    check_boat_diff_sameway_three(bt, bt->bboat_4, bt->eboat_4, bt->direc4)+
    check_boat_diff_sameway_four(bt, bt->bboat_1, bt->eboat_1, bt->direc1)+
    check_boat_diff_sameway_four(bt, bt->bboat_2, bt->eboat_2, bt->direc2)+
    check_boat_diff_sameway_four(bt, bt->bboat_3, bt->eboat_3, bt->direc3));
}

int check_boat_diff_pos_distrib_three(variable_boat *bt)
{
    return
    (check_boat_diff_pos(bt, bt->bboat_2, 3, bt->direc2)+
    check_boat_diff_pos(bt, bt->bboat_3, 4, bt->direc3)+
    check_boat_diff_pos(bt, bt->bboat_4, 5, bt->direc4)+
    check_boat_diff_pos_two(bt, bt->bboat_1, 2, bt->direc1)+
    check_boat_diff_pos_two(bt, bt->bboat_3, 4, bt->direc3)+
    check_boat_diff_pos_two(bt, bt->bboat_4, 5, bt->direc4)+
    check_boat_diff_pos_three(bt, bt->bboat_1, 2, bt->direc1)+
    check_boat_diff_pos_three(bt, bt->bboat_2, 3, bt->direc2)+
    check_boat_diff_pos_three(bt, bt->bboat_4, 5, bt->direc4)+
    check_boat_diff_pos_four(bt, bt->bboat_1, 2, bt->direc1)+
    check_boat_diff_pos_four(bt, bt->bboat_2, 3, bt->direc2)+
    check_boat_diff_pos_four(bt, bt->bboat_3, 4, bt->direc3));
}

int check_boat_diff_pos_distrib(variable_boat *bt)
{
    if (check_boat_diff_pos_distrib_one(bt) +
    check_boat_diff_pos_distrib_two(bt) +
    check_boat_diff_pos_distrib_three(bt) != 0) {
        my_putstr("Error map\n");
        exiterr();
    }
}