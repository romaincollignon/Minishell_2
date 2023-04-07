/*
** EPITECH PROJECT, 2022
** my_exit.c
** File description:
** Function : my_exit
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "../../include/struct_all.h"
#include "my.h"

int my_exit(i_s *info_shell, char *cmd)
{
    if (cmd[0] != 'e') return 0;
    mini_printf("exit\n");
    info_shell->stop = 1;
    return 0;
}
