/*
** EPITECH PROJECT, 2022
** fonction_my_other.c
** File description:
** Function : cd
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "../../../include/struct_all.h"
#include "../../../include/my.h"

char *cherch_path(i_s *info_shell)
{
    for (int n = 0; info_shell->env[n] != NULL; n++) {
        if (info_shell->env[n][0] == 'P' &&
            info_shell->env[n][1] == 'A' &&
            info_shell->env[n][2] == 'T' &&
            info_shell->env[n][3] == 'H' &&
            info_shell->env[n][4] == '=') {
            info_shell->tmp_env =
            malloc(sizeof(char) * (my_strlen(info_shell->env[n]) + 2));
            return my_strcpy(info_shell->tmp_env, info_shell->env[n]);
        }
    }
    char *result = malloc(sizeof(char) * 3);
    result[0] = '8';
    result[1] = '4';
    result[2] = '\0';
    return result;
}

char *add_cmd(char *path, char *cmd)
{
    int size_cmd = my_strlen(cmd);
    int size_path = my_strlen(path);
    char *result = malloc(sizeof(char) * (size_cmd + size_path + 2));
    int a = 0;
    for (; path[a] != '\0'; a++) {
        result[a] = path[a];
    }
    if (result[a - 1] == '/') {
        for (int n = 0; cmd[n] != '\0'; n++) {
            result[a] = cmd[n];
            a++;
        } result[a] = '\0';
    } else {
        result[a] = '/';
        a++;
        for (int n = 0; cmd[n] != '\0'; n++) {
            result[a] = cmd[n];
            a++;
        } result[a] = '\0';
    } return result;
}

char **cherch_dr(i_s *info_shell, char *cmd)
{
    char *path = cherch_path(info_shell);
    if (path[0] == '8' && path[1] == '4' && path[2] == '\0')
        return NULL;
    int a = 0;
    for (int n = 5; path[n] != '\0'; n++) {
        path[a] = path[n];
        a++;
    } path[a] = '\0';
    int n = 0;
    for (; path[n] != '\0'; n++) {
        if (path[n] == ':')
        path[n] = ' ';
    }
    path[n] = '\0';
    char **result = my_str_to_word_array(path, " ");
    for (int a = 0; result[a] != NULL; a++) {
        result[a] = add_cmd(result[a], cmd);
    }
    return result;
}
