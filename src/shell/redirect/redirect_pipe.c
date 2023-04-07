/*
** EPITECH PROJECT, 2022
** redirect_pipe.c
** File description:
** Function : redirect_pipe
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>

#include "../../../include/struct_all.h"
#include "my.h"

int recup_one_pipe(i_s *info_shell, char *cmd, int n, int pos)
{
    if (cmd[n] == ' ')
        n++;
    info_shell->st_pipe.tab_pipe[pos] = malloc(sizeof(char) * my_strlen(cmd));
    int i = 0;
    while (cmd[n] != '\0' && cmd[n] != '|' && cmd[n] != '<' && cmd[n] != '>'
        && cmd[n] != ';') {
        info_shell->st_pipe.tab_pipe[pos][i] = cmd[n];
        n++;
        i++;
    }
    if (info_shell->st_pipe.tab_pipe[pos][i - 1] == ' ')
        info_shell->st_pipe.tab_pipe[pos][i - 1] = '\0';
    else
        info_shell->st_pipe.tab_pipe[pos][i] = '\0';
    return n--;
}

void recup_pipe(i_s *info_shell, char *cmd)
{
    info_shell->st_pipe.tab_pipe = malloc(sizeof(char *) *
        (info_shell->st_pipe.nb_pipe + 2));
    int pos = 0;
    for (int n = 0; cmd[n] != '\0'; n++) {
        if (cmd[n] == '|') {
            n = recup_one_pipe(info_shell, cmd, n + 1, pos);
            n--;
            pos++;
        }
    }
    info_shell->st_pipe.tab_pipe[pos] = NULL;
}

char *suppr_zone_pipe(char *cmd)
{
    int deb = 0;
    for (; cmd[deb] != '\0' && cmd[deb] != '|' && cmd[deb] != '<' &&
    cmd[deb] != '>' && cmd[deb] != ';'; deb++);
    if (cmd[deb] == '\0')
        return cmd;
    int suite = deb + 1;
    for (; cmd[suite] != '\0' && cmd[suite] != '|' && cmd[suite] != '<' &&
    cmd[suite] != '>' && cmd[suite] != ';'; suite++);
    while (cmd[suite - 1] != '\0') {
        cmd[deb] = cmd[suite];
        deb++;
        suite++;
    }
    return cmd;
}

char *clean_cmd_pipe(i_s *info_shell, char *cmd)
{
    for (int n = 0; n < info_shell->st_pipe.nb_pipe; n++) {
        cmd = suppr_zone_pipe(cmd);
    }
    return cmd;
}

char *redirect_pipe(i_s *info_shell, char *cmd)
{
    if (info_shell->st_pipe.nb_pipe == 0)
        return cmd;
    recup_pipe(info_shell, cmd);
    cmd = clean_cmd_pipe(info_shell, cmd);
    return cmd;
}
