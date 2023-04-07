/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main -> mini_shell
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "../include/struct_all.h"
#include "my.h"

int main(int ac, char **av, char **env)
{
    if (av == NULL) return 84;
    if (ac != 1) return 84;
    i_s *info_shell = malloc(sizeof(i_s));
    init_struct(info_shell, env);
    shell(info_shell);
    free_struct(info_shell);
    return 0;
}
