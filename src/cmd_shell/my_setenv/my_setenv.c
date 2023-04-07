/*
** EPITECH PROJECT, 2022
** my_setenv.c
** File description:
** Function : setenv
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "../../../include/struct_all.h"
#include "../../../include/my.h"

static char *clean_setenv(char **cmd, int nb_arg)
{
    int size_max;
    if (nb_arg == 2)
        size_max = my_strlen(cmd[1]) + 2;
    else
        size_max = my_strlen(cmd[1]) + my_strlen(cmd[2]) + 2;
    char *result = malloc(sizeof(char) * (size_max));
    int n = 0;
    for (; cmd[1][n] != '\0'; n++)
        result[n] = cmd[1][n];
    result[n] = '=';
    if (nb_arg == 2) {
        result[n + 1] = '\0';
    } else {
        n++;
        for (int a = 0; cmd[2][a] != '\0'; a++) {
            result[n] = cmd[2][a];
            n++;
        }
        result[n] = '\0';
    } return result;
}

int in_env(char *env, char *cmd)
{
    int size_env = my_strlen(env);
    int size_cmd = my_strlen(cmd);
    if (size_env < (size_cmd + 1))
        return 0;
    if (my_strncmp(env, cmd, size_cmd) == 0 && env[size_cmd] == '=') {
        return 1;
    }
    return 0;
}

int cherch_arg_env(i_s *info_shell, char *cmd)
{
    for (int a = 0; a < info_shell->size_env; a++) {
        if (in_env(info_shell->env[a], cmd) == 1)
            return a;
    }
    return -1;
}

int my_setenv(i_s *info_shell, char *cmd)
{
    if (nb_arg(cmd) == 1)
        return my_env(info_shell, "env");
    if (nb_arg(cmd) == 4) {
        write_error("setenv: Too many arguments.\n");
        return 0;
    }
    char **tmp = my_str_to_word_array(cmd, " ");
    char *msg = "setenv: Variable name must contain alphanumeric characters.\n";
    if (tmp[1] == NULL)
        return 0;
    for (int n = 0; tmp[1][n] != '\0'; n++) {
        if (tmp[1][n] == '=')
            return write_error(msg);
    } char **tab_cmd = my_str_to_word_array(cmd, " ");
    int pos = cherch_arg_env(info_shell, tab_cmd[1]);
    if (pos == -1)
        return new_env(info_shell, clean_setenv(tab_cmd, nb_arg(cmd)));
    else
        return edit_env(info_shell, tab_cmd, nb_arg(cmd), pos);
    return 0;
}
