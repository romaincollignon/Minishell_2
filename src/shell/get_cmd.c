/*
** EPITECH PROJECT, 2022
** get_cmd.c
** File description:
** Function : get_cmd
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "../../include/struct_all.h"
#include "my.h"

char *get_cmd(i_s *info_shell)
{
    size_t line = 0;
    char *buffer = NULL;
    int error = 0;
    error = getline(&buffer, &line, stdin);
    if (error == -1) {
        info_shell->stop = 1;
        info_shell->restart = 1;
        return 0;
    }
    return buffer;
}

char *get_cmd_redi(void)
{
    size_t line = 0;
    char *buffer = NULL;
    int error = 0;
    error = getline(&buffer, &line, stdin);
    char *char_error = malloc(sizeof(char) * 3);
    char_error[0] = '~';
    char_error[1] = '\0';
    if (error == -1) {
        return char_error;
    }
    free(char_error);
    buffer[my_strlen(buffer) - 1] = '\0';
    return buffer;
}

char *cleaner_espace(char *cmd)
{
    int i, j, n;
    int compt = 0;
    for (int u = 0; cmd[u] != '\0'; u++) {
        if (cmd[u] == '>' || cmd[u] == '<' || cmd[u] == '|')
            compt++;
    } char *new_cmd = malloc(my_strlen(cmd) + compt + 1);
    n = my_strlen(cmd);
    for (i = 0, j = 0; i < n; i++) {
        if ((cmd[i] == '<' || cmd[i] == '>' || cmd[i] == '|') &&
            i < (my_strlen(cmd) - 1) && cmd[i + 1] != ' ' &&
            cmd[i + 1] != '<' && cmd[i + 1] != '>' && cmd[i + 1] != '|') {
            j++;
            new_cmd[j++] = ' ';
        }
        if (cmd[i] == '<' || cmd[i] == '>' || cmd[i] == '|')
            new_cmd[j - 2] = cmd[i];
        else
            new_cmd[j++] = cmd[i];
    } new_cmd[j] = '\0';
    return new_cmd;
}
