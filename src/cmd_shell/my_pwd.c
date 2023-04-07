/*
** EPITECH PROJECT, 2022
** my_pwd.c
** File description:
** Function : my_pwd
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "../../include/struct_all.h"
#include "my.h"

int my_pwd(i_s *info_shell, char *cmd)
{
    if (nb_arg(cmd) != 1)
        write_error("pwd: ignoring non-option arguments\n");
    mini_printf("%s\n", info_shell->dir);
    return 0;
}
