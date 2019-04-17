/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** main function
*/
#include "include/my.h"

struct variable_signal sig;

void init_one(char *str, variable_boat *bt, variable_map *mp)
{
    check_good_file_pos(recup_pos(str));
    check_good_pos_boat(recup_pos(str), bt);
    create_map(mp);
    rewrite_map_with_boat(bt, mp);
    sig.pid1 = getpid();
    my_putstr("my_pid: ");
    my_put_nbr(sig.pid1);
    my_putstr("\nwaiting for enemy connection...\n\n");
}

void connect_init()
{
    while (sig.counterH == 0) {
            signal(SIGUSR1, handler1);
            usleep(6000);
    }
    my_putstr("enemy connected\n");
    for (int i = 0; i != 101; i++) {
        signal(SIGUSR1, handler2);
        signal(SIGUSR2, handler2);
        usleep(6000);
    }
    binary_to_decimal();
    kill(sig.pid2, SIGUSR1);
    usleep(6000);
}

int recinput(char *str1, char *str_tmp, int i, variable_map mp)
{
    my_putstr("\nmy positions:\n");
    disp_map(mp.map_boat1);
    my_putstr("\nenemy's positions:\n");
    disp_map(mp.map_enemy1);
    my_putchar(10);
    do {
        my_putstr("attack: ");
        str1 = malloc(sizeof(char) * 2);
        str_tmp = "";
        i = 0;
        for (i; str1[0] != '\n'; i++) {
            if (read(0, str1, 1) == 0)
                exiterr();
        str_tmp = my_strcat_two(str_tmp, str1[0]);
        }
        str_tmp[i] = '\0';
    } while (test_input(str_tmp) != 0);
    send_input(str_tmp, sig.pid2);
}

void hand_four(void)
{
    sig.counterH = 0;
    while (sig.counterH == 0) {
        signal(SIGUSR1, handler4);
        signal(SIGUSR2, handler4);
        usleep(6000);
    }
}

int pass_one(char *str_tmp, variable_map *mp)
{
    my_putchar(str_tmp[0]);
    my_putchar(str_tmp[1]);
    if (sig.counterH == 1)
        my_putstr(": hit");
    else if (sig.counterH == -1)
        my_putstr(": missed");
    input_player_two(str_tmp, mp, sig.counterH);
    if (check_map(mp->map_enemy1) == 1) {
        usleep(6000);
        kill(sig.pid2, SIGUSR2);
        return (1);
    } else if (check_map(mp->map_enemy1) == 0){
        usleep(6000);
        kill(sig.pid2, SIGUSR1);
    }
    return (0);
}

void pass_two(char *str1, variable_map *mp, variable_boat *bt)
{
    my_putstr("\n\nwaiting for enemy's attack...\n");
    str1 = my_strcpy(str1, recept_input());
    my_putstr(str1);
    my_putstr(":");
    if (input_player(str1, mp, bt) == 1) {
        my_putstr(" hit\n");
        usleep(6000);
        kill(sig.pid2, SIGUSR1);
    } else {
        my_putstr(" missed\n");
        usleep(6000);
        kill(sig.pid2, SIGUSR2);
    }
    hand_four();
}

int player_one(int ac, char **av)
{
    struct variable_boat bt;
    struct variable_map mp;
    char *str1;
    char *str_tmp = "";
    int i = 0;

    if (ac == 2) {
        init_one(av[1], &bt, &mp);
        connect_init();
        while (1) {
            recinput(str1, str_tmp, i, mp);
            hand_four();
            if (pass_one(str_tmp, &mp) != 0)
                break;
            if (sig.counterH == 1)
                break;
            pass_two(str1, &mp, &bt);
        }
        if (check_map(mp.map_enemy1) == 1)
            my_putchar(10);
        my_putstr("\nmy positions:\n");
        disp_map(mp.map_boat1);
        my_putstr("\nenemy's positions:\n");
        disp_map(mp.map_enemy1);
        if (check_map(mp.map_enemy1) == 1) {
            my_putstr("\nI won\n");
            exit_victory();
        }
        else if (sig.counterH == 1) {
            my_putstr("\nEnemy won\n");
            exit_loose();
        }
    }
}