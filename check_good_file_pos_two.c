/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** main function
*/
#include "include/my.h"

char *recup_pos(char *file)
{
    char *buff;
    char *pos_txt;
    unsigned long fd;
    int counter = 0;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        exiterr();
    for (counter; read(fd, &buff, 1) != 0; counter++);
    close(fd);
    if (counter != 31 && counter != 32)
        exiterr();
    buff = malloc(sizeof(char) * (counter + 1));
    fd = open(file, O_RDONLY);
    read(fd, buff, counter);
    close(fd);
    buff[counter] = '\0';
    pos_txt = my_strcpy(pos_txt, buff);
    free(buff);
    return (pos_txt);
}

int check_nb_charactere(char *pos_txt)
{
    int i = 0;

    for (i; pos_txt[i] != '\0'; i++);
    if (i == 31 || i == 32)
        return (0);
    return (-1);
}