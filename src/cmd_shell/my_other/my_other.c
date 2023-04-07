/*
** EPITECH PROJECT, 2022
** my_other.c
** File description:
** Function : my_other
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "../../../include/struct_all.h"
#include "my.h"

char *no_cmd(int size_cmd, char *arg)
{
    char *result = malloc(sizeof(char) * my_strlen(arg));
    int a = 0;
    for (int n = size_cmd; arg[n] != '\n' && arg[n] != '\0'; n++) {
        result[a] = arg[n];
        a++;
    } result[a] = '\0';
    return result;
}

void signal_pipe(i_s *info_shell, pid_t r_fork)
{
    if (info_shell->st_pipe.nb_pipe == 0) {
        verif_signal(r_fork);
    } else {
        info_shell->st_pipe.waitpid[info_shell->st_pipe.pos] = r_fork;
    }
}

int suite_my_other(i_s *info_shell, char **good_arg, char **directo, int tmp)
{
    if (access(directo[tmp], X_OK) == 0) {
        pid_t r_fork = fork();
        if (r_fork == 0) {
            piped(info_shell);
            child_int_double(info_shell);
            child_int_single(info_shell);
            execve(directo[tmp], good_arg, info_shell->env);
            exit(0);
        } else {
            signal_pipe(info_shell, r_fork);
            return 2;
        }
    }
    return 0;
}

int verif_path_exist(i_s *info_shell)
{
    char *path = cherch_path(info_shell);
    if (path[0] == '8')
        return -1;
    if (path[5] == '\0')
        return -1;
    return 0;
}

int my_other(i_s *info_shell, char *arg, char *cmd)
{
    if (verif_path_exist(info_shell) == -1)
        return -1;
    char **directo = cherch_dr(info_shell, cmd);
    if (directo == NULL) return -1;
    char **good_arg = my_str_to_word_array(arg, " ");
    int tmp_error = -1;
    int tmp_two = 0;
    for (int tmp = 0; (tmp_error == -1) && (directo[tmp] != NULL); tmp++) {
        tmp_two = suite_my_other(info_shell, good_arg, directo, tmp);
        if (tmp_two == -1)
            tmp_error = 1;
        if (tmp_two == 2) {
            tmp_error = 1;
            break;
        }
    } if (tmp_error == -1) return -1;
    return 0;
}
