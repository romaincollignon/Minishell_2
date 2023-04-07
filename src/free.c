/*
** EPITECH PROJECT, 2022
** free.c
** File description:
** Function: free_struct
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "../include/struct_all.h"
#include "my.h"

void free_struct(i_s *info_shell)
{
    free(info_shell->env);
    free(info_shell->dir);
    free(info_shell->back_dir);
}
