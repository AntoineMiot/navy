/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** main function
*/
#include "include/my.h"

struct variable_signal sig;

int test_input(char *str)
{
    if (my_strlen(str) != 3) {
        my_putstr("wrong position\n");
        return (1);
    }
    if ((str[0] < 65 || str[0] > 72) || (str[1] < 49 || str[1] > 56)) {
        my_putstr("wrong position\n");
        return (1);
    }
    return (0);
}

void send_input(char *str, int pid)
{
    for (int i = 0; i != str[0] - 64; i++) {
        kill(pid, SIGUSR2);
        usleep(6000);
    }
    kill(pid, SIGUSR1);
    usleep(6000);
    for (int i = 0; i != str[1] - 48; i++) {
        kill(pid, SIGUSR2);
        usleep(6000);
    }
    kill(pid, SIGUSR1);
    usleep(6000);
}

int input_player_two_scnd(char *str, variable_map *mp, int touch)
{
    int pos;

    if ((str[0] < 65 || str[0] > 72) || (str[1] < 49 || str[1] > 57))
        exiterr();
    pos = ((str[0] - 64) + ((str[1] - 49) * 8) - 1);
    if (touch == -1) {
        mp->map_enemy1[pos] = 'x';
        return (1);
    } else if (touch == 1) {
        mp->map_enemy1[pos] = 'o';
        return (0);
    }
}