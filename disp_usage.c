/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** display usage
*/
#include "include/my.h"

void disp_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    first_player_pid:  only for the 2nd player.  pid");
    my_putstr(" of the first player.\n");
    my_putstr("    navy_positions:  file representing the positions");
    my_putstr(" of the ships.\n");
}