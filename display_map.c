/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** main function
*/
#include "include/my.h"

struct variable_signal sig;

int disp_map_three(char *map, int i, int first)
{
    if (first == 0) {
        my_putchar(map[i]);
        first = 1;
    } else {
        my_putchar(32);
        my_putchar(map[i]);
    }
    return (first);
}

int disp_map_two_scnd(int i, int counter2)
{
    if (i == counter2)
        counter2 = counter2 + 8;
    return (counter2);
}

int disp_map_two(int i, int counter2, int nb_line)
{
    if (i == counter2) {
        my_putchar(nb_line);
        my_putchar('|');
        nb_line++;
    }
    return (nb_line);
}

void disp_map(char *map)
{
    int counter = 7;
    int counter2 = 0;
    int first = 0;
    int nb_line = 49;

    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; i != 64; i++) {
        nb_line = disp_map_two(i, counter2, nb_line);
        first = disp_map_three(map, i, first);
        counter2 = disp_map_two_scnd(i, counter2);
        if (i == counter) {
            first = 0;
            my_putchar(10);
            counter = counter + 8;
        }
    }
}
