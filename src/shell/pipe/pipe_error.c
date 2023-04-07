/*
** EPITECH PROJECT, 2022
** pipe_error.c
** File description:
** Function : pipe_error
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>

#include "../../../include/struct_all.h"
#include "my.h"

void waitpid_pipe(i_s *info_shell)
{
    for (int n = 0; n <= info_shell->st_pipe.nb_pipe; n++) {
        verif_signal(info_shell->st_pipe.waitpid[n]);
    }
}

int pipe_error(i_s *info_shell, char *cmd)
{
    int n = 0;
    for (; cmd[n] != '\0' && cmd[n] != '>' && cmd[n] != '<'; n++);
    if (cmd[n] == '\0')
        return 0;
    int i = n + 1;
    for (; cmd[i] != '\0' && cmd[i] != '|'; i++);
    if (cmd[i] == '|') {
        return write_error_rep("Ambiguous output redirect.\n");
    }
    return 0;
}
