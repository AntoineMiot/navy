/*
** EPITECH PROJECT, 2018
** include functions
** File description:
** include functions
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <wait.h>
#include <signal.h>

#define exiterr()__asm__("movq $60, %rax\nmovq $84,%rdi\nsyscall")
#define exit_victory()__asm__("movq $60, %rax\nmovq $0,%rdi\nsyscall")
#define exit_loose()__asm__("movq $60, %rax\nmovq $1,%rdi\nsyscall")

struct variable_boat{
    char *map;
    int bboat_1;
    int bboat_2;
    int bboat_3;
    int bboat_4;
    int eboat_1;
    int eboat_2;
    int eboat_3;
    int eboat_4;
    int direc1;
    int direc2;
    int direc3;
    int direc4;
};

typedef struct variable_boat variable_boat;

struct variable_map{
    char *map_boat1;
    char *map_enemy1;
    char *map_boat2;
    char *map_enemy2;
};

typedef struct variable_map variable_map;

struct variable_signal{
    char *pid_bin;
    int counterH;
    int pid1;
    int pid2;
};

typedef struct variable_signal variable_signal;

int my_getnbr(char const *str);
int *negneg(int v1, int i, int *neg);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
void disp_usage(void);
char *recup_pos(char *file);
int check_boat_two(char *file, variable_boat *bt);
int check_boat_three(char *file, variable_boat *bt);
int check_boat_four(char *file, variable_boat *bt);
int check_boat_five(char *file, variable_boat *bt);
int check_boat_diff_pos_four(variable_boat *bt, int bboat, int z,
int direc);
int check_boat_diff_pos_three(variable_boat *bt, int bboat,
int z, int direc);
int check_boat_diff_pos_two(variable_boat *bt, int bboat,
int z, int direc);
int check_boat_diff_pos(variable_boat *bt, int bboat,
int z, int direc);
int check_boat_diff_sameway_four(variable_boat *bt, int bboat,
int eboat, int direc);
int check_boat_diff_sameway_three(variable_boat *bt, int bboat,
int eboat, int direc);
int check_boat_diff_sameway_two(variable_boat *bt, int bboat,
int eboat, int direc);
int check_boat_diff_sameway(variable_boat *bt, int bboat,
int eboat, int direc);
int check_boat_diff_pos_distrib(variable_boat *bt);
int check_boat_diff_sameway_y(variable_boat *bt, int bboat,
int eboat, int direc);
int check_boat_diff_sameway_y_two(variable_boat *bt, int bboat,
int eboat, int direc);
int check_boat_diff_sameway_y_three(variable_boat *bt, int bboat,
int eboat, int direc);
int check_boat_diff_sameway_y_four(variable_boat *bt, int bboat,
int eboat, int direc);
void check_good_file_pos(char *pos_txt);
char *my_strcat_two(char *str_first, char const str_scnd);
int check_map(char *map);
char *my_strcpy_two(char *dest, char const src);
int check_nb_charactere(char *pos_txt);
void handler1(int sign);
void handler2(int sign);
void handler3(int sign);
void handler4(int sign);
int check_good_pos_boat(char *file, variable_boat *bt);
void rewrite_map_with_boat(variable_boat *bt, variable_map *mp);
char *create_map(variable_map *mp);
char *decimal_to_binary(int integer);
void send_pid(void);
int input_player(char *str, variable_map *mp, variable_boat *bt);
int input_player_two(char *str, variable_map *mp, int touch);
void binary_to_decimal(void);
int input_player_two_scnd(char *str, variable_map *mp, int touch);
void send_input(char *str, int pid);
int test_input(char *str);
char *recept_input(void);
void disp_map(char *map);
int player_one(int ac, char **av);
int player_two(int ac, char **av);
