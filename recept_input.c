/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** main function
*/
#include "include/my.h"

struct variable_signal sig;

void loop_one(void)
{
    sig.pid_bin = "";
    sig.counterH = 0;
    while (1) {
        signal(SIGUSR1, handler3);
        signal(SIGUSR2, handler3);
        usleep(6000);
        if (sig.counterH == 1)
            break;
    }
}

char *recept_input(void)
{
    char *letter = "";
    char *number = "";

    loop_one();
    for (int i = 0; i != my_strlen(sig.pid_bin); i++)
        letter = my_strcpy_two(letter, i + 65);
    loop_one();
    for (int i = 0; i != my_strlen(sig.pid_bin); i++)
        number = my_strcpy_two(number, i + 49);
    return (my_strcat(letter, number));
}