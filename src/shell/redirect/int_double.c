/*
** EPITECH PROJECT, 2022
** int_double.c
** File description:
** Function :
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>

#include "../../../include/struct_all.h"
#include "my.h"

int init_int_double(i_s *info_shell)
{
    if (info_shell->st_redi.redir_type[1] != 1)
        return 0;
    if (arg_redirect(info_shell) == 0)
        return 84;
    info_shell->st_redi.old = dup(STDIN_FILENO);
    if (pipe(info_shell->st_redi.pipe_out) == -1)
        perror("pipe");
    for (int n = 0; info_shell->st_redi.file_tmp[n] != NULL; n++) {
        write(info_shell->st_redi.pipe_out[1], info_shell->st_redi.file_tmp[n],
            my_strlen(info_shell->st_redi.file_tmp[n]));
            write(info_shell->st_redi.pipe_out[1], "\n", 1);
    }
    close(info_shell->st_redi.pipe_out[1]);
    return 0;
}

int child_int_double(i_s *info_shell)
{
    if (info_shell->st_redi.redir_type[1] != 1 ||
        info_shell->st_pipe.pos != info_shell->st_pipe.pos_max)
        return 0;
    if (dup2(info_shell->st_redi.pipe_out[0], STDIN_FILENO) == -1) {
        perror("dup2");
        exit(EXIT_FAILURE);
    }
    close(info_shell->st_redi.pipe_out[0]);
    return 0;
}

void reset_int_double(i_s *info_shell)
{
    if (info_shell->st_redi.redir_type[1] != 1)
        return;
    dup2(info_shell->st_redi.old, STDIN_FILENO);
    close(info_shell->st_redi.old);
    return;
}
