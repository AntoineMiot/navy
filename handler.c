/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** handler
*/
#include "include/my.h"

struct variable_signal sig;


void handler1(int sign)
{
    sig.counterH++; 
}

void handler2(int sign)
{
    if (sign == 10) {
        sig.pid_bin = my_strcat(sig.pid_bin, "0");
    } else if (sign == 12) {
        sig.pid_bin = my_strcat(sig.pid_bin, "1");
    }
}

void handler3(int sign)
{
    if (sign == 12) {
        sig.pid_bin = my_strcat(sig.pid_bin, "1");
    } else if (sign == 10) {
        sig.counterH = 1;
    }
}

void handler4(int sign)
{
    if (sign == 10) {
        sig.counterH = -1;
    } else if (sign == 12) {
        sig.counterH = 1;
    }
}