/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** main function
*/
#include "include/my.h"

struct variable_signal sig;

int len_boat(variable_boat *bt)
{
    if (bt->bboat_1 + 1 != bt->eboat_1 && bt->bboat_1 + (1*8) != bt->eboat_1
        || bt->bboat_2 + 2 != bt->eboat_2 && bt->bboat_2 +
        (2*8) != bt->eboat_2 || bt->bboat_3 + 3 != bt->eboat_3 && bt->bboat_3
        + (3*8) != bt->eboat_3 || bt->bboat_4 + 4 != bt->eboat_4 && bt->bboat_4
        + (4*8) != bt->eboat_4)
        return (84);
    else
        return (0);
}

int check_good_pos_boat(char *file, variable_boat *bt)
{
    check_boat_two(file, bt);
    check_boat_three(file, bt);
    check_boat_four(file, bt);
    check_boat_five(file, bt);
    if (len_boat(bt) == 84)
        return (84);
    check_boat_diff_pos_distrib(bt);
    return (0);
}

char *create_map(variable_map *mp)
{
    mp->map_boat1 = malloc(sizeof(char) * 65);
    for (int i = 0; i != 64; i++)
        mp->map_boat1[i] = '.';
    mp->map_boat1[64] = '\0';
    mp->map_boat2 = my_strcpy(mp->map_boat2, mp->map_boat1);
    mp->map_enemy1 = my_strcpy(mp->map_enemy1, mp->map_boat1);
    mp->map_enemy2 = my_strcpy(mp->map_enemy2, mp->map_boat1);
}

void rewrite_map_with_boat_player1(int bboat, int eboat, int direc,
variable_map *mp)
{
    static int len_boat = 50;
    if (direc == -1) {
        while (bboat != eboat + 8) {
            mp->map_boat1[bboat - 1] = len_boat;
            bboat = bboat + 8;
        }
    } else if (direc == -2) {
        while (bboat != eboat + 1) {
            mp->map_boat1[bboat - 1] = len_boat;
            bboat = bboat + 1;
        }
    }
    len_boat++;
}

void rewrite_map_with_boat(variable_boat *bt, variable_map *mp)
{
    rewrite_map_with_boat_player1(bt->bboat_1, bt->eboat_1, bt->direc1, mp);
    rewrite_map_with_boat_player1(bt->bboat_2, bt->eboat_2, bt->direc2, mp);
    rewrite_map_with_boat_player1(bt->bboat_3, bt->eboat_3, bt->direc3, mp);
    rewrite_map_with_boat_player1(bt->bboat_4, bt->eboat_4, bt->direc4, mp);
}