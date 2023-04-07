/*
** EPITECH PROJECT, 2022
** edit_env.c
** File description:
** Function : edit_env
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "../../../include/struct_all.h"
#include "../../../include/my.h"

int reset_arg(i_s *info_shell, int pos_env)
{
    int n = 0;
    for (; info_shell->env[pos_env][n] != '=' && info_shell->env[pos_env][n]
        != '\0'; n++);
    info_shell->env[pos_env][n + 1] = '\0';
    return 0;
}

int edit_arg(i_s *info_shell, char **tab_cmd, int pos_env)
{
    int deb = 0;
    for (; info_shell->env[pos_env][deb] != '=' &&
        info_shell->env[pos_env][deb] != '\0'; deb++);
    char *tmp_env = malloc(sizeof(char) * (my_strlen(tab_cmd[2]) +
        my_strlen(info_shell->env[pos_env]) + 5));
    for (int a = 0; a <= deb; a++)
        tmp_env[a] = info_shell->env[pos_env][a];
    deb++;
    for (int a = 0; tab_cmd[2][a] != '\0'; a++) {
        tmp_env[deb] = tab_cmd[2][a];
        deb++;
    } tmp_env[deb] = '\0';
    info_shell->env[pos_env] = tmp_env;
    return 0;
}

int edit_env(i_s *info_shell, char **tab_cmd, int nb_arg, int pos_env)
{
    if (nb_arg == 2)
        return reset_arg(info_shell, pos_env);
    else
        return edit_arg(info_shell, tab_cmd, pos_env);
}
