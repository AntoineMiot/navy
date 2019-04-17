/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** main function
*/
#include "include/my.h"

struct variable_signal sig;

int player_two(int ac, char **av)
{
    struct variable_boat bt;
    struct variable_map mp;
    char *str1;
    char *str_tmp = "";
    int i = 0;

    if (ac == 3) {
        check_good_file_pos(recup_pos(av[2]));
        check_good_pos_boat(recup_pos(av[2]), &bt);
        create_map(&mp);
        rewrite_map_with_boat(&bt, &mp);
        sig.pid1 = my_getnbr(av[1]);
        sig.pid2 = getpid();
        usleep(6000);
        if (kill(sig.pid1, SIGUSR1) == -1)
            exiterr();
        usleep(6000);
        my_putstr("my_pid: ");
        my_put_nbr(sig.pid2);
        my_putchar(10);
        my_putstr("successfully connected\n");
        sig.counterH = 0;
        send_pid();
        while (sig.counterH == 0) {
            signal(SIGUSR1, handler1);
            usleep(6000);
        }
        sig.counterH = 0;

        while (1) {
            my_putstr("\nmy positions:\n");
            disp_map(mp.map_boat1);
            my_putstr("\nenemy's positions:\n");
            disp_map(mp.map_enemy1);
            my_putstr("\nwaiting for enemy's attack...\n");

            str1 = my_strcpy(str1, recept_input());
            my_putstr(str1);
            my_putstr(":");
            i = input_player(str1, &mp, &bt);
            if (i == 1) {
                my_putstr(" hit\n");
                usleep(6000);
                kill(sig.pid1, SIGUSR2);
            } else {
                my_putstr(" missed\n");
                usleep(6000);
                kill(sig.pid1, SIGUSR1);
            }

            ////////////////////////////            
            sig.counterH = 0;
            while (sig.counterH == 0) {
                signal(SIGUSR1, handler4);    /////send input
                signal(SIGUSR2, handler4);
                usleep(6000);
            }
            ////////////////////////////            
            if (sig.counterH == 1)
                break;
            ////////////////////////////                        
            
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

            send_input(str_tmp, sig.pid1);

            sig.counterH = 0;
            while (sig.counterH == 0) {
                signal(SIGUSR1, handler4);    /////send input
                signal(SIGUSR2, handler4);
                usleep(6000);
            }

            i = input_player_two_scnd(str_tmp, &mp, sig.counterH);
            my_putchar(str_tmp[0]);
            my_putchar(str_tmp[1]);
            if (sig.counterH == -1)
                my_putstr(": hit\n");
            else if (sig.counterH == 1)
                my_putstr(": missed\n");
            ////////////////////////////
            if (check_map(mp.map_enemy1) == 1) {
                usleep(6000);
                kill(sig.pid1, SIGUSR2);
                break;
            } else if (check_map(mp.map_enemy1) == 0){
                usleep(6000);
                kill(sig.pid1, SIGUSR1);
            }
            ////////////////////////////   

        }
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