/*
** EPITECH PROJECT, 2022
** main_pipe.c
** File description:
** Function : main_pipe
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "../../../include/struct_all.h"
#include "my.h"

int init_pipe(i_s *info_shell)
{
    info_shell->st_pipe.pos = 0;
    info_shell->st_pipe.pos_max = info_shell->st_pipe.nb_pipe;

    info_shell->st_pipe.pi = malloc(sizeof(int*) *
        (info_shell->st_pipe.nb_pipe + 1));
    info_shell->st_pipe.waitpid = malloc(sizeof(int) *
        (info_shell->st_pipe.nb_pipe + 3));
    int n = 0;
    for (; n <= info_shell->st_pipe.nb_pipe; n++) {
        info_shell->st_pipe.pi[n] = malloc(sizeof(int) * 3);
        if (pipe(info_shell->st_pipe.pi[n]) == -1) {
            write_error("Error pipe\n");
            return -1;
        }
        info_shell->st_pipe.waitpid[n] = -1;
    }
    return 0;
}

void piped(i_s *info_shell)
{
    if (info_shell->st_pipe.nb_pipe == 0)
        return;
    int pos = info_shell->st_pipe.pos;
    int pos_max = info_shell->st_pipe.pos_max;
    if (pos < pos_max) {
        dup2(info_shell->st_pipe.pi[pos][1], STDOUT_FILENO);
        close(info_shell->st_pipe.pi[pos][1]);
    }
    if (pos != 0) {
        dup2(info_shell->st_pipe.pi[pos - 1][0], STDIN_FILENO);
        close(info_shell->st_pipe.pi[pos - 1][0]);
    }
    all_close_pipe(info_shell);
}

void all_close_pipe(i_s *info_shell)
{
    for (int n = 0; n <= info_shell->st_pipe.nb_pipe; n++) {
        close(info_shell->st_pipe.pi[n][0]);
        close(info_shell->st_pipe.pi[n][1]);
    }
}

void reload_dup2(i_s *info_shell, int n)
{
    dup2(info_shell->st_pipe.old, STDIN_FILENO);
    close(info_shell->st_pipe.old);
    dup2(info_shell->st_pipe.old_out, STDOUT_FILENO);
    close(info_shell->st_pipe.old_out);
    if (n == 0)
        info_shell->st_pipe.pos++;
}

int main_pipe(i_s *info_shell, char *cmd)
{
    cmd = redirect_pipe(info_shell, cmd);
    if (init_pipe(info_shell) == -1) return 0;
    info_shell->st_pipe.old = dup(STDIN_FILENO);
    info_shell->st_pipe.old_out = dup(STDOUT_FILENO);
    if (start_cmd_pipe(info_shell, cmd) == 84) return 0;
    reload_dup2(info_shell, 0);
    while (info_shell->st_pipe.pos <= info_shell->st_pipe.pos_max) {
        close(info_shell->st_pipe.pi[info_shell->st_pipe.pos - 1][1]);
        info_shell->st_pipe.old = dup(STDIN_FILENO);
        info_shell->st_pipe.old_out = dup(STDOUT_FILENO);
        if (start_cmd_pipe(info_shell,
            info_shell->st_pipe.tab_pipe[info_shell->st_pipe.pos - 1]) == 84) {
            return 0;
        }
        reload_dup2(info_shell, 0);
    } reload_dup2(info_shell, 1);
    all_close_pipe(info_shell);
    while (wait(NULL) != -1);
    waitpid_pipe(info_shell);
    return 0;
}

// With /dev/random
