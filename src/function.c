/*
** EPITECH PROJECT, 2022
** function.c
** File description:
** Function : open_file
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <signal.h>
#include <dirent.h>

#include "../include/struct_all.h"
#include "my.h"

void fill(char *str, int size)
{
    for (int n = 0; n < size; n++)
        str[n] = '.';
    str[size] = '\0';
}

int cherch_nb_dir(char **dir)
{
    int size = 0;
    for (; dir[size] != NULL; size++);
    return size;
}

int nb_arg(char *cmd)
{
    int nb = 1;
    for (int n = 0; cmd[n] != '\0'; n++) {
        if (cmd[n] == ' ')
            nb++;
    }
    return nb;
}

int verif_perm_directo(char *directo)
{
    struct stat st;
    if (stat(directo, &st) == -1)
        return 0;
    if (S_ISREG(st.st_mode)) {
        double_write(directo, ": Not a directory.\n");
        return 1;
    }
    DIR* dir = opendir(directo);
    if (dir) {
        closedir(dir);
        return 0;
    } else {
        double_write(directo, ": Permission denied.\n");
        return 1;
    }
}
