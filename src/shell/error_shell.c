/*
** EPITECH PROJECT, 2022
** error_shell.c
** File description:
** Function : error_shell
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "../../include/struct_all.h"
#include "../../include/my.h"

void error_shell(i_s *info_shell, int nb_error)
{
    if (info_shell->restart == 0)
        info_shell->restart = 0;
    if (nb_error == 0)
        return;
    return;
}
