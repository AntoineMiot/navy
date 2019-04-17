/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** main function
*/
#include "include/my.h"

struct variable_signal sig;

int main(int ac, char **av)
{
    sig.pid_bin = "";
    sig.counterH = 0;
    if (ac != 2 && ac != 3)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h')
        disp_usage();
    player_one(ac, av);
    player_two(ac, av);
    return (0);
}