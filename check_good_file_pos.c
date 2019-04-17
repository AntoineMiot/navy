/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** main function
*/
#include "include/my.h"

int check_len_boat(char *pos_txt)
{
    int z = 50;
    for (int i = 0; i != 32; i = i + 8) {
        if (pos_txt[i] != z)
            return (-1);
        z++;
    }
    return (0);
}

int check_double_point(char *pos_txt)
{
    for (int i = 1; i != 33; i = i + 8)
        if (pos_txt[i] != ':')
            return (-1);
    for (int i = 4; i != 36; i = i + 8)
        if (pos_txt[i] != ':')
            return (-1);
    return (0);
}

int check_letter_pos(char *pos_txt)
{
    for (int i = 2; i != 34; i = i + 8)
        if (pos_txt[i] < 65 || pos_txt[i] > 72)
            return (-1);
    for (int i = 5; i != 37; i = i + 8)
        if (pos_txt[i] < 65 || pos_txt[i] > 72)
            return (-1);
    return (0);
}

int check_number_pos(char *pos_txt)
{
    for (int i = 3; i != 35; i = i + 8)
        if (pos_txt[i] < 49 || pos_txt[i] > 56)
            return (-1);
    for (int i = 6; i != 38; i = i + 8)
        if (pos_txt[i] < 49 || pos_txt[i] > 56)
            return (-1);
    return (0);
}

void check_good_file_pos(char *pos_txt)
{
    if (check_nb_charactere(pos_txt)+
        check_len_boat(pos_txt)+
        check_double_point(pos_txt)+
        check_letter_pos(pos_txt)+
        check_number_pos(pos_txt) != 0)
        exiterr();
}