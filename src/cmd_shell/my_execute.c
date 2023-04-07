/*
** EPITECH PROJECT, 2022
** my_execute.c
** File description:
** Function : my_execute
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

#include "../../include/struct_all.h"
#include "../../include/my.h"

int nb_slach(char *cmd)
{
    int nb_slach = 0;
    for (int n = 0; cmd[n] != '\0'; n++) {
        if (cmd[n] == '/')
            nb_slach++;
    }
    return nb_slach;
}

int finish_execute_file(char *cmd, int n_slach)
{
    if (n_slach != 0) {
        double_write(cmd, ": Command not found.\n");
        return 1;
    } if (my_strlen(cmd) <= 2) {
        double_write(cmd, ": Command not found.\n");
        return 1;
    } if (cmd[0] == '.' && cmd[1] == '/'){
        double_write(cmd, ": Command not found.\n");
        return 1;
    }
    return 0;
}

int execute_file(i_s *info_shell, char **tab_cmd, char *directo)
{
    pid_t result_fork = fork();
    if (result_fork == 0) {
        piped(info_shell);
        child_int_double(info_shell);
        child_int_single(info_shell);
        execve(directo, tab_cmd, info_shell->env);
        perror(tab_cmd[0]);
        exit(0);
    } else {
        signal_pipe(info_shell, result_fork);
        return 1;
    }
}

char *create_directo(i_s *info_shell, char *access)
{
    char *result = malloc(sizeof(char) * ((my_strlen(info_shell->dir)) +
        (my_strlen(access)) + 2));
    int n = 0;
    while (info_shell->dir[n] != '\0') {
        result[n] = info_shell->dir[n];
        n++;
    }
    if (access[0] != '/') {
        result[n] = '/';
        n++;
    }
    for (int a = 0; access[a] != '\0'; a++) {
        result[n] = access[a];
        n++;
    }
    result[n] = '\0';
    return result;
}

int my_execute(i_s *info_shell, char *cmd)
{
    char **tab_cmd = my_str_to_word_array(cmd, " ");
    if (nb_slach(tab_cmd[0]) == 0)
        return 0;
    char *directo;
    if (tab_cmd[0][0] == '.')
        directo = create_directo(info_shell, tab_cmd[0]);
    else
        directo = tab_cmd[0];
    DIR* dir = opendir(directo);
    if (dir) {
        closedir(dir);
        double_write(tab_cmd[0], ": Permission denied.\n");
        return 1;
    }
    if (access(directo, X_OK) != -1)
        return execute_file(info_shell, tab_cmd, directo);
    return finish_execute_file(cmd, nb_slach(tab_cmd[0]));
}
