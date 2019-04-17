/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** main function
*/
#include "include/my.h"

struct variable_signal sig;

char *decimal_to_binary(int integer)
{
    int i = 0;
    char *str_res;

    str_res = malloc(sizeof(char) * 100);
    while (integer > 0) {
        str_res[i] = integer % 2 + 48;
        integer = integer / 2;
        i++;
    }
    str_res[i + 1] = '\0';
    str_res = my_revstr(str_res);
}

void send_pid(void)
{
    char *binary_pid = decimal_to_binary(sig.pid2);

    for (int i = 0; binary_pid[i] != '\0'; i++) {
        if (binary_pid[i] == '0') {
            kill(sig.pid1, SIGUSR1);
            usleep(6000);
        }
        else if (binary_pid[i] == '1') {
            kill(sig.pid1, SIGUSR2);
            usleep(6000);
        }
    }
}

void binary_to_decimal(void)
{
    sig.pid2 = 0;
    for (int i = 0; sig.pid_bin[i] != '\0'; i++) {
        if (sig.pid_bin[i] == '1')
            sig.pid2 = sig.pid2 * 2 + 1;
        else if (sig.pid_bin[i] == '0')
            sig.pid2 *= 2;
    }
}

int input_player(char *str, variable_map *mp, variable_boat *bt)
{
    int pos;

    if ((str[0] < 65 || str[0] > 72) || (str[1] < 49 || str[1] > 57))
        exiterr();
    pos = ((str[0] - 64) + ((str[1] - 49) * 8) - 1);
    if (mp->map_boat1[pos] >= 50 && mp->map_boat1[pos] < 54) {
        mp->map_boat1[pos] = 'x';
        return (1);
    } else if (mp->map_boat1[pos] == '.') {
        mp->map_boat1[pos] = 'o';
        return (0);
    }
}

int input_player_two(char *str, variable_map *mp, int touch)
{
    int pos;

    if ((str[0] < 65 || str[0] > 72) || (str[1] < 49 || str[1] > 57))
        exiterr();
    pos = ((str[0] - 64) + ((str[1] - 49) * 8) - 1);
    if (touch == 1) {
        mp->map_enemy1[pos] = 'x';
        return (1);
    } else if (touch == -1) {
        mp->map_enemy1[pos] = 'o';
        return (0);
    }
}