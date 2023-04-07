/*
** EPITECH PROJECT, 2022
** my_echo.c
** File description:
** Function : my_echo
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "../../include/struct_all.h"
#include "my.h"

static char *clean_echo(char *cmd)
{
    int n = 0;
    for (int a = 5; cmd[a] != '\0'; a++) {
        cmd[n] = cmd[a];
        n++;
    } cmd[n] = '\0';
    return cmd;
}

int my_echo(i_s *info_shell, char *cmd)
{
    if (info_shell->restart == 0)
        info_shell->restart = 0;
    mini_printf("%s\n", clean_echo(cmd));
    return 0;
}
